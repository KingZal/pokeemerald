#include "technique_manual.h"
#include "global.h"

#include "battle.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "item_menu.h"
#include "item_use.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "gba/isagbprint.h"

#define gSaveBlockTmPtr gSaveBlock3Ptr->techniqueManual


struct ResearchTask
{
    u8 type;
    u8 requirement;
    const u8* descriptionOverride;
};

struct TechniqueManual
{
    u16 move;
    struct ResearchTask species;
    struct ResearchTask counter[TM_COUNTERS_COUNT];
};

#define SATURATING_INCREMENT_COUNTER(counter) \
    if ((counter) < 0xFF) \
        (counter)++;



#include "data/technique_manual.h"

/** Returns which TM is associated with a particular move. Returns TM_NONE if no TM for the move */
static u8 MoveToTm(u16 move)
{
    u8 i;
    for (i = 0; i < TM_COUNT; i++)
    {
        if (sTM[i].move == move)
            return i;
    }
    return TM_NONE;
}

void TmIncrementSeenStats(u16 move, u16 attackerSpecies)
{
    u8 i;
    u8 tmIndex = MoveToTm(move);

    if (TM_NONE != tmIndex)
    {
        if (TM_SPECIESCOUNTER_SEEN == sTM[tmIndex].species.type)
        {
            for (i = 0; i < TM_SPECIES_COUNT; i++)
            {
                u16 *saveSpot = &(gSaveBlockTmPtr[tmIndex].species[i]);
                if (attackerSpecies == *saveSpot)
                    break;

                if (0 == *saveSpot)
                {
                    *saveSpot = attackerSpecies;
                    break;
                }
            }
        }

        for (i = 0; i < TM_COUNTERS_COUNT; i++)
        {
            if ((TM_COUNTER_SEEN == sTM[tmIndex].counter[i].type)
                || ((TM_COUNTER_SEEN_RAIN == sTM[tmIndex].counter[i].type)
                    && (gBattleWeather & B_WEATHER_RAIN))
                || ((TM_COUNTER_SEEN_SUN == sTM[tmIndex].counter[i].type)
                    && (gBattleWeather & B_WEATHER_SUN))
            )
            {
                SATURATING_INCREMENT_COUNTER(
                    gSaveBlockTmPtr[tmIndex].counters[i]);
            }
        }
    }

    if (gMovesInfo[move].type == TYPE_ICE && (gSpeciesInfo[attackerSpecies].types[0] == TYPE_WATER || gSpeciesInfo[attackerSpecies].types[1] == TYPE_WATER))
    {
        // which counter this affects should be constant.
        // TODO: determine which counter to increment at compile-time
        for (tmIndex = 0; tmIndex < TM_COUNT; tmIndex++)
        {
            for (i = 0; i < TM_COUNTERS_COUNT; i++)
            {
                if ((TM_COUNTER_WATER_USING_ICE == sTM[tmIndex].counter[i].type))
                {
                    SATURATING_INCREMENT_COUNTER(
                        gSaveBlockTmPtr[tmIndex].counters[i]);
                }
            }
        }
    }
}

void TmBeTutored(u8 tmIndex)
{
    int i;
    if (TM_NONE != tmIndex && tmIndex < TM_COUNT)
    {
        for (i = 0; i < TM_COUNTERS_COUNT; i++)
        {
            if ((TM_COUNTER_BE_TUTORED == sTM[tmIndex].counter[i].type))
            {
                SATURATING_INCREMENT_COUNTER(
                    gSaveBlockTmPtr[tmIndex].counters[i]);
            }
        }
    }
}

bool8 TmIsMastered(u8 tmIndex)
{
    int i;

    if (sTM[tmIndex].species.type != TM_SPECIESCOUNTER_NONE)
    {
        for (i = 0; i < TM_SPECIES_COUNT; i++)
            if (0 == gSaveBlockTmPtr[tmIndex].species[i])
                break;

        if (i < sTM[tmIndex].species.requirement)
            return FALSE;
    }

    for (i = 0; i < TM_COUNTERS_COUNT; i++)
    {
        if (sTM[tmIndex].counter[i].type == TM_COUNTER_NONE)
            continue;

        if (gSaveBlockTmPtr[tmIndex].counters[i] < sTM[tmIndex].counter[i].requirement)
            return FALSE;
    }

    return TRUE;
}

static bool8 TmShouldDisplayName(u8 tmIndex)
{
    int i;

    if (TmIsMastered(tmIndex))
        return TRUE;

    if (sTM[tmIndex].species.type == TM_SPECIESCOUNTER_SEEN && 0 != gSaveBlockTmPtr[tmIndex].species[0])
        return TRUE;

    for (i = 0; i < TM_COUNTERS_COUNT; i++)
    {
        if ((sTM[tmIndex].counter[i].type == TM_COUNTER_SEEN
            || sTM[tmIndex].counter[i].type == TM_COUNTER_SEEN_RAIN
            || sTM[tmIndex].counter[i].type == TM_COUNTER_SEEN_SUN
            )
            && gSaveBlockTmPtr[tmIndex].counters[i] != 0
        )
            return TRUE;
    }

    return FALSE;
}



// The tm menu

static void CB2_OpenTechniqueManualFromBag(void);
static void Task_OpenRegisteredTechniqueManual(u8 taskId);
static void OpenTechniqueManual(void (*callback)(void));
static void CB2_InitTechniqueManual(void);
static bool8 InitTechniqueManual(void);
static void CB2_TechniqueManual(void);
static void VBlankCB_TechniqueManual(void);
static void Task_HandleTechniqueManualInput(u8 taskId);
static void FadePaletteAndSetTaskToCloseTechniqueManual(u8 taskId);
static void Task_FreeDataAndExitTechniqueManual(u8 taskId);
static void HandleInitBackgrounds(void);
static void HandleInitWindows(void);
static void CreateScrollArrows(void);
static void DestroyScrollArrows(void);
static void MoveTechniqueManualCursor(s32 tmIndex, bool8 onInit, struct ListMenu *list);
static void UpdateTechniqueManualList(void);
static void DrawTechniqueManualHighlight(u16 cursorPos, u16 tileNum);

struct TechniqueManualSavedData
{
    void (*callback)(void);
    u16 selectedRow;
    u16 scrollOffset;
};

struct TechniqueManualStruct
{
    u8 tilemap[BG_SCREEN_SIZE];
    void (*callbackOnUse)(void);
    struct ListMenuItem items[TM_COUNT + 1];
    // 0xFF indicates unused
    u8 monSpriteIds[TM_SPECIES_COUNT];
    u8 arrowTaskId;
};

EWRAM_DATA static struct TechniqueManualSavedData sSavedTechniqueManualData = {0};
EWRAM_DATA static struct TechniqueManualStruct *sTechniqueManualMenu = NULL;

enum {
    WIN_LIST,
    WIN_COUNTER_DESCS,
    WIN_PROMPT_TEACH,
    WIN_PROMPT_CLOSE,
    WIN_DUMMY,
};

static const u32 sMenuTechniqueManual_Gfx[] = INCBIN_U32("build/graphics/technique_manual/background.4bpp.lz");
static const u32 sMenuTechniqueManual_Pal[] = INCBIN_U32("build/graphics/technique_manual/background.gbapal.lz");
static const u32 sMenuTechniqueManual_Tilemap[] = INCBIN_U32("build/graphics/technique_manual/background.tilemap.lz");

static const u16 sCheckmarkTechniqueManual_Gfx[] = INCBIN_U16("graphics/technique_manual/checkmark.4bpp");
static const u16 sAButtonTechniqueManual_Gfx[] = INCBIN_U16("graphics/technique_manual/a_button.4bpp");

static const struct BgTemplate sBgTemplatesForTechniqueManualMenu[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_LIST] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x30
    },
    [WIN_PROMPT_TEACH] = {
        .bg = 0,
        .tilemapLeft = 30 - 6,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x30 + 10 * 9
    },
    [WIN_PROMPT_CLOSE] = {
        .bg = 0,
        .tilemapLeft = 30 - 6,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x30 + 10 * 9 + 6 * 2
    },
    [WIN_COUNTER_DESCS] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 29 - 12,
        .height = 18 - 2,
        .paletteNum = 15,
        .baseBlock = 0x30 + 10 * 9 + 6 * 4
    },
    [WIN_DUMMY] = DUMMY_WIN_TEMPLATE,
};

static const struct ListMenuTemplate sTmMenuTemplate =
{
    .items = NULL,
    .moveCursorFunc = MoveTechniqueManualCursor,
    .itemPrintFunc = NULL,
    .totalItems = TM_COUNT + 1,
    .maxShowed = 5,
    .windowId = WIN_LIST,
    .header_X = 0,
    .item_X = 1,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

#define TILE_HIGHLIGHT_NONE 0x0000 // Tile number for the bg of an unselected menu item
#define TILE_HIGHLIGHT_SELECTED 0x1000 // Tile number for the bg of a selected menu item
#define TAG_SCROLL_ARROW 1110

static const u8 sTextColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

#include "data/text/technique_manual.h"


u16 TmCurrentlySelectedMove(void)
{
    unsigned id = sSavedTechniqueManualData.scrollOffset
        + sSavedTechniqueManualData.selectedRow;

    if (id < TM_COUNT)
        return sTM[id].move;
    return MOVE_NONE;
}



#define tUsingRegisteredKeyItem data[3] // See usage in item_use.c

void ItemUseOutOfBattle_TechniqueManual(u8 taskId)
{
    if (MenuHelpers_IsLinkActive() == TRUE)
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
    else if (gTasks[taskId].tUsingRegisteredKeyItem != TRUE)
    {
        gBagMenu->newScreenCallback = CB2_OpenTechniqueManualFromBag;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gFieldCallback = FieldCB_ReturnToFieldNoScript;
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_OpenRegisteredTechniqueManual;
    }
}

static void CB2_OpenTechniqueManualFromBag(void)
{
    OpenTechniqueManual(CB2_ReturnToBagMenuPocket);
}

static void Task_OpenRegisteredTechniqueManual(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        OpenTechniqueManual(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void OpenTechniqueManual(void (*callback)(void))
{
    int i;
    sTechniqueManualMenu = Alloc(sizeof(*sTechniqueManualMenu));
    sTechniqueManualMenu->callbackOnUse = NULL;
    sTechniqueManualMenu->arrowTaskId = TASK_NONE;
    for (i = 0; i < TM_SPECIES_COUNT; i++)
        sTechniqueManualMenu->monSpriteIds[i] = 0xFF;
    sSavedTechniqueManualData.callback = callback;

    SetMainCallback2(CB2_InitTechniqueManual);
}

void CB2_ReopenTechniqueManual(void)
{
    int i;
    sTechniqueManualMenu = Alloc(sizeof(*sTechniqueManualMenu));
    sTechniqueManualMenu->callbackOnUse = NULL;
    for (i = 0; i < TM_SPECIES_COUNT; i++)
        sTechniqueManualMenu->monSpriteIds[i] = 0xFF;

    SetMainCallback2(CB2_InitTechniqueManual);
}

static void CB2_InitTechniqueManual(void)
{
    while (1)
    {
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE)
            break;
        if (InitTechniqueManual() == TRUE)
            break;
        if (MenuHelpers_IsLinkActive() == TRUE)
            break;
    }
}

#define tListTaskId data[0]
#define tWindowId   data[1]

static bool8 InitTechniqueManual(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetTasks();
        gMain.state++;
        break;
    case 6:
        HandleInitBackgrounds();
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sMenuTechniqueManual_Gfx, 0, 0, 0);
        gMain.state++;
        break;
    case 7:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sMenuTechniqueManual_Tilemap, sTechniqueManualMenu->tilemap);
            gMain.state++;
        }
        break;
    case 8:
        LoadCompressedPalette(sMenuTechniqueManual_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 9:
        LoadMonIconPalettes();
        gMain.state++;
        break;
    case 10:
        DrawTechniqueManualHighlight(sSavedTechniqueManualData.selectedRow, TILE_HIGHLIGHT_SELECTED);
        gMain.state++;
        break;
    case 11:
        HandleInitWindows();
        gMain.state++;
        break;
    case 12:
        UpdateTechniqueManualList();
        gMain.state++;
        break;
    case 13:
        CreateScrollArrows();
        gMain.state++;
        break;
    case 14:
        taskId = CreateTask(Task_HandleTechniqueManualInput, 0);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, sSavedTechniqueManualData.scrollOffset, sSavedTechniqueManualData.selectedRow);
        gMain.state++;
        break;
    case 15:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 16:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_TechniqueManual);
        SetMainCallback2(CB2_TechniqueManual);
        return TRUE;
    }

    return FALSE;
}

static void HandleInitBackgrounds(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplatesForTechniqueManualMenu, ARRAY_COUNT(sBgTemplatesForTechniqueManualMenu));
    SetBgTilemapBuffer(2, sTechniqueManualMenu->tilemap);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(2);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void HandleInitWindows(void)
{
    u8 i;

    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    LoadMessageBoxGfx(0, 0xA, BG_PLTT_ID(13));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    LoadPalette((const u16[2]) {RGB(31, 0, 0), RGB(21, 0, 0)}, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(2));

    for (i = 0; i < ARRAY_COUNT(sWindowTemplates) - 1; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
    }

    // `* 2` because two tiles; `/ 2` because array is `u16`s
    CopyToWindowPixelBuffer(WIN_PROMPT_TEACH, sAButtonTechniqueManual_Gfx, TILE_SIZE_4BPP * 2, 0);
    CopyToWindowPixelBuffer(WIN_PROMPT_TEACH, &sAButtonTechniqueManual_Gfx[TILE_SIZE_4BPP * 2 / 2], TILE_SIZE_4BPP * 2, sWindowTemplates[WIN_PROMPT_TEACH].width);
    AddTextPrinterParameterized4(WIN_PROMPT_TEACH, FONT_NORMAL, 15, 0, 0, 0, sTextColor, 0, sText_PromptTeach);

    CopyToWindowPixelBuffer(WIN_PROMPT_CLOSE, sAButtonTechniqueManual_Gfx, TILE_SIZE_4BPP * 2, 0);
    CopyToWindowPixelBuffer(WIN_PROMPT_CLOSE, &sAButtonTechniqueManual_Gfx[TILE_SIZE_4BPP * 2 / 2], TILE_SIZE_4BPP * 2, sWindowTemplates[WIN_PROMPT_CLOSE].width);
    AddTextPrinterParameterized4(WIN_PROMPT_CLOSE, FONT_NORMAL, 15, 0, 0, 0, sTextColor, 0, sText_PromptClose);

    ScheduleBgCopyTilemapToVram(0);
}

static void UpdateTechniqueManualList(void)
{
    u16 i;

    for (i = 0; i < TM_COUNT; i++)
    {
        if (TmShouldDisplayName(i))
            sTechniqueManualMenu->items[i].name = gMovesInfo[sTM[i].move].name;
        else
            sTechniqueManualMenu->items[i].name = sText_UndiscoveredMove;
        sTechniqueManualMenu->items[i].id = i;
    }

    sTechniqueManualMenu->items[i].name = sText_CloseMenuItem;
    sTechniqueManualMenu->items[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate = sTmMenuTemplate;
    gMultiuseListMenuTemplate.items = sTechniqueManualMenu->items;
}

static void CreateScrollArrows(void)
{
    if (sTechniqueManualMenu->arrowTaskId == TASK_NONE)
    {
        sTechniqueManualMenu->arrowTaskId = AddScrollIndicatorArrowPairParameterized(
                SCROLL_ARROW_UP,
                sWindowTemplates[WIN_LIST].tilemapLeft * 8 + sWindowTemplates[WIN_LIST].width * 4,
                sWindowTemplates[WIN_LIST].tilemapTop * 8,
                (sWindowTemplates[WIN_LIST].tilemapTop + sWindowTemplates[WIN_LIST].height) * 8,
                sTmMenuTemplate.totalItems - sTmMenuTemplate.maxShowed,
                TAG_SCROLL_ARROW,
                TAG_SCROLL_ARROW,
                &sSavedTechniqueManualData.scrollOffset);
    }
}

static void DestroyScrollArrows(void)
{
    if (sTechniqueManualMenu->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sTechniqueManualMenu->arrowTaskId);
        sTechniqueManualMenu->arrowTaskId = TASK_NONE;
    }
}

static void DrawTechniqueManualHighlight(u16 cursorPos, u16 tileNum)
{
    FillBgTilemapBufferRect_Palette0(2,
            tileNum,
            sWindowTemplates[WIN_LIST].tilemapLeft,
            (cursorPos * 2) + 1,
            sWindowTemplates[WIN_LIST].width,
            2);
    ScheduleBgCopyTilemapToVram(2);
}

static void CB2_TechniqueManual(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_TechniqueManual(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}


static void Task_HandleTechniqueManualInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active && MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        u16 oldPosition = sSavedTechniqueManualData.selectedRow;
        s32 input = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, &sSavedTechniqueManualData.scrollOffset, &sSavedTechniqueManualData.selectedRow);

        if (oldPosition != sSavedTechniqueManualData.selectedRow)
        {
            // Moved cursor
            DrawTechniqueManualHighlight(oldPosition, TILE_HIGHLIGHT_NONE);
            DrawTechniqueManualHighlight(sSavedTechniqueManualData.selectedRow, TILE_HIGHLIGHT_SELECTED);
        }

        switch (input)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            gSpecialVar_Result = 0xFFFF;
            FadePaletteAndSetTaskToCloseTechniqueManual(taskId);
            break;
        default:
            // Selected Move
            if (TmIsMastered(input))
            {
                PlaySE(SE_SELECT);
                sTechniqueManualMenu->callbackOnUse = CB2_ChooseMonToTeachFromTechniqueManual;
                FadePaletteAndSetTaskToCloseTechniqueManual(taskId);
            }
            else
            {
                PlaySE(SE_BOO);
            }
            break;
        }
    }
}

static void DrawMoveInfo(s32 tmIndex)
{
    int i, y;

    FillWindowPixelBuffer(WIN_COUNTER_DESCS, PIXEL_FILL(0));
    for (i = 0; i < TM_SPECIES_COUNT; i++)
    {
        if (! (sTechniqueManualMenu->monSpriteIds[i] & 0x80))
        {
            FreeAndDestroyMonIconSprite(&gSprites[sTechniqueManualMenu->monSpriteIds[i]]);
            sTechniqueManualMenu->monSpriteIds[i] = 0xFF;
        }
    }

    if (tmIndex < 0 || tmIndex >= TM_COUNT)
    {
        // Assume this is the "Close Manual" menu item
        PutWindowTilemap(WIN_PROMPT_CLOSE);
    }
    else if (TmIsMastered(tmIndex))
    {
        PutWindowTilemap(WIN_PROMPT_TEACH);
    }
    else
    {
        FillBgTilemapBufferRect(
            sWindowTemplates[WIN_PROMPT_TEACH].bg,
            0,
            sWindowTemplates[WIN_PROMPT_TEACH].tilemapLeft,
            sWindowTemplates[WIN_PROMPT_TEACH].tilemapTop,
            sWindowTemplates[WIN_PROMPT_TEACH].width,
            sWindowTemplates[WIN_PROMPT_TEACH].height,
            sWindowTemplates[WIN_PROMPT_TEACH].paletteNum);
    }

    y = 1;

    // all digits have the same width
    const unsigned digitWidth = GetStringWidth(FONT_NORMAL, COMPOUND_STRING("0"), 0);
    const unsigned slashWidth = GetStringWidth(FONT_NORMAL, gText_Slash, 0);

    if (0 <= tmIndex && tmIndex < TM_COUNT)
    {
        const u8 type = sTM[tmIndex].species.type;

        if (type != TM_SPECIESCOUNTER_NONE)
        {
            const u8* taskDescription = sSpeciesDesc[type];
            if (sTM[tmIndex].species.descriptionOverride) {
                taskDescription = sTM[tmIndex].species.descriptionOverride;
            }
            AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, 1, y, 0, 0, sTextColor, 0, taskDescription);
            y += 32;
            ConvertUIntToDecimalStringN(gStringVar1, sTM[tmIndex].species.requirement, STR_CONV_MODE_RIGHT_ALIGN, 1);
            unsigned x = sWindowTemplates[WIN_COUNTER_DESCS].width * 8 - digitWidth;
            AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, x, y, 0, 0, sTextColor, 0, gStringVar1);
            x -= slashWidth;
            AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, x, y, 0, 0, sTextColor, 0, gText_Slash);

            x += sWindowTemplates[WIN_COUNTER_DESCS].tilemapLeft * 8 + 12;
            for (i = TM_SPECIES_COUNT - 1; i >= 0; i--)
            {
                x -= 24;
                u16 species = gSaveBlockTmPtr[tmIndex].species[i];
                if (species)
                    sTechniqueManualMenu->monSpriteIds[i] = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(species),
                        SpriteCB_MonIcon, x, y + sWindowTemplates[WIN_COUNTER_DESCS].tilemapTop * 8, 0);
            }

            y += 16;
        }

        for (i = 0; i < TM_COUNTERS_COUNT; i++)
        {
            const u8 type = sTM[tmIndex].counter[i].type;

            if (TM_COUNTER_NONE != type)
            {
                const u8* taskDescription = sCounterDesc[type];
                if (sTM[tmIndex].counter[i].descriptionOverride) {
                    taskDescription = sTM[tmIndex].counter[i].descriptionOverride;
                }
                AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, 1, y, 0, 0, sTextColor, 0, taskDescription);
                y += 16;

                const u8 requirement = sTM[tmIndex].counter[i].requirement;
                const u8 counter = gSaveBlockTmPtr[tmIndex].counters[i];

                ConvertUIntToDecimalStringN(gStringVar1, requirement, STR_CONV_MODE_RIGHT_ALIGN, 2);
                unsigned x = sWindowTemplates[WIN_COUNTER_DESCS].width * 8 - digitWidth * 2;
                AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, x, y, 0, 0, sTextColor, 0, gStringVar1);
                x -= slashWidth;
                AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, x, y, 0, 0, sTextColor, 0, gText_Slash);

                if (counter >= requirement)
                {
                    int tileOffset = ((y / 8) + 1) * sWindowTemplates[WIN_COUNTER_DESCS].width - 4;

                    // `* 2` because two tiles; `/ 2` because array is `u16`s
                    CopyToWindowPixelBuffer(WIN_COUNTER_DESCS, sCheckmarkTechniqueManual_Gfx, TILE_SIZE_4BPP * 2, tileOffset);
                    tileOffset += sWindowTemplates[WIN_COUNTER_DESCS].width - 1;
                    CopyToWindowPixelBuffer(WIN_COUNTER_DESCS, &sCheckmarkTechniqueManual_Gfx[TILE_SIZE_4BPP * 2 / 2], TILE_SIZE_4BPP * 2, tileOffset);
                }
                else
                {
                    x -= digitWidth * 2;
                    ConvertUIntToDecimalStringN(gStringVar1, counter, STR_CONV_MODE_RIGHT_ALIGN, 2);
                    AddTextPrinterParameterized4(WIN_COUNTER_DESCS, FONT_NORMAL, x, y, 0, 0, sTextColor, 0, gStringVar1);
                }

                y += 16;
            }
        }
    }

    ScheduleBgCopyTilemapToVram(0);
    CopyWindowToVram(WIN_COUNTER_DESCS, COPYWIN_GFX);
}

static void MoveTechniqueManualCursor(s32 tmIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
    }

    DrawMoveInfo(tmIndex);
}

static void FadePaletteAndSetTaskToCloseTechniqueManual(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_FreeDataAndExitTechniqueManual;
}

static void Task_FreeDataAndExitTechniqueManual(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(tListTaskId, &sSavedTechniqueManualData.scrollOffset, &sSavedTechniqueManualData.selectedRow);
        DestroyScrollArrows();
        ResetSpriteData();
        FreeAllSpritePalettes();

        if (sTechniqueManualMenu->callbackOnUse != NULL)
            SetMainCallback2(sTechniqueManualMenu->callbackOnUse);
        else
            SetMainCallback2(sSavedTechniqueManualData.callback);

        FreeAllWindowBuffers();
        Free(sTechniqueManualMenu);
        DestroyTask(taskId);
    }
}
