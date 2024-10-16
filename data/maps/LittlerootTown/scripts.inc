LittlerootTown_EventScript_Debug_Pokemon::
# 4 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 5 "data/maps/LittlerootTown/scripts.pory"
	showmonpic SPECIES_DARKRAI, 10, 3
# 6 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_Debug_Pokemon_Text_0
# 7 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_DARKRAI, 20, ITEM_MASTER_BALL
# 8 "data/maps/LittlerootTown/scripts.pory"
	PlayFanfare MUS_SLOTS_JACKPOT
# 9 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 10 "data/maps/LittlerootTown/scripts.pory"
	hidemonpic
# 12 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 13 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


# 18 "data/maps/LittlerootTown/scripts.pory"

# 19 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_TWIN, 1
# 20 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_MOM, 4
# 21 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_RIVAL, 7
# 22 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_BIRCH, 8
# 23 "data/maps/LittlerootTown/scripts.pory"

# 24 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 25 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 26 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 27 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 28 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 29 "data/maps/LittlerootTown/scripts.pory"

# 30 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 31 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 35 "data/maps/LittlerootTown/scripts.pory"

# 36 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 37 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 38 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 39 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 40 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 41 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 42 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 43 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 44 "data/maps/LittlerootTown/scripts.pory"

# 45 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 46 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 47 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 48 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 49 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 50 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 51 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 52 "data/maps/LittlerootTown/scripts.pory"

# 53 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 54 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 55 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 56 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 57 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 58 "data/maps/LittlerootTown/scripts.pory"

# 59 "data/maps/LittlerootTown/scripts.pory"

# 60 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 61 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 62 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 63 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 64 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 65 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 66 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 67 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 68 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 69 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 70 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 71 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 72 "data/maps/LittlerootTown/scripts.pory"
	end
# 73 "data/maps/LittlerootTown/scripts.pory"

# 74 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 75 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 76 "data/maps/LittlerootTown/scripts.pory"
	return
# 77 "data/maps/LittlerootTown/scripts.pory"

# 78 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 79 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 80 "data/maps/LittlerootTown/scripts.pory"
	return
# 81 "data/maps/LittlerootTown/scripts.pory"

# 82 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 83 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 84 "data/maps/LittlerootTown/scripts.pory"
	return
# 85 "data/maps/LittlerootTown/scripts.pory"

# 86 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 87 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 88 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 89 "data/maps/LittlerootTown/scripts.pory"
	return
# 90 "data/maps/LittlerootTown/scripts.pory"

# 91 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 92 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 93 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 94 "data/maps/LittlerootTown/scripts.pory"
	return
# 95 "data/maps/LittlerootTown/scripts.pory"

# 96 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 97 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 98 "data/maps/LittlerootTown/scripts.pory"
	return
# 99 "data/maps/LittlerootTown/scripts.pory"

# 100 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 101 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 102 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 103 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 104 "data/maps/LittlerootTown/scripts.pory"
	return
# 105 "data/maps/LittlerootTown/scripts.pory"

# 106 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 107 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 108 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 109 "data/maps/LittlerootTown/scripts.pory"
	return
# 110 "data/maps/LittlerootTown/scripts.pory"

# 111 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 112 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 113 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 114 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 115 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 116 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 117 "data/maps/LittlerootTown/scripts.pory"
	return
# 118 "data/maps/LittlerootTown/scripts.pory"

# 119 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 120 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 121 "data/maps/LittlerootTown/scripts.pory"
	return
# 122 "data/maps/LittlerootTown/scripts.pory"

# 123 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 124 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 125 "data/maps/LittlerootTown/scripts.pory"
	return
# 126 "data/maps/LittlerootTown/scripts.pory"

# 127 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 128 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 129 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 130 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 131 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 132 "data/maps/LittlerootTown/scripts.pory"

# 133 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 134 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 135 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 136 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 137 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 138 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 139 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 140 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 141 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 142 "data/maps/LittlerootTown/scripts.pory"
	end
# 143 "data/maps/LittlerootTown/scripts.pory"

# 144 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 145 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 146 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 147 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 148 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 149 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 150 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 151 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 152 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 153 "data/maps/LittlerootTown/scripts.pory"
	end
# 154 "data/maps/LittlerootTown/scripts.pory"

# 155 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 156 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 157 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 158 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 159 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 160 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 161 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 162 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 163 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 164 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 165 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 166 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 167 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 168 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 169 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 170 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 171 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 172 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 173 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 174 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 175 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 176 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 177 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 178 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 179 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 180 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 181 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 182 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 183 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 184 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 185 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 186 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 187 "data/maps/LittlerootTown/scripts.pory"
	return
# 188 "data/maps/LittlerootTown/scripts.pory"

# 189 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 190 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 191 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 192 "data/maps/LittlerootTown/scripts.pory"

# 193 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 194 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 195 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 196 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 197 "data/maps/LittlerootTown/scripts.pory"

# 198 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 199 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 200 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 201 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 203 "data/maps/LittlerootTown/scripts.pory"

# 204 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 205 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 206 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 207 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 208 "data/maps/LittlerootTown/scripts.pory"

# 209 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 210 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 211 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 212 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 213 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 214 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 215 "data/maps/LittlerootTown/scripts.pory"

# 216 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 217 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 218 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 219 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 220 "data/maps/LittlerootTown/scripts.pory"

# 221 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 222 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 223 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 224 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 225 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 226 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 227 "data/maps/LittlerootTown/scripts.pory"

# 228 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 229 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 230 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 231 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 232 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 233 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 234 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 235 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 236 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 237 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 238 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 239 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 240 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 241 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 242 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 243 "data/maps/LittlerootTown/scripts.pory"
	end
# 244 "data/maps/LittlerootTown/scripts.pory"

# 245 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 246 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 247 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 248 "data/maps/LittlerootTown/scripts.pory"

# 249 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 250 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 251 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 252 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 253 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 254 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 255 "data/maps/LittlerootTown/scripts.pory"
	end
# 256 "data/maps/LittlerootTown/scripts.pory"

# 257 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 258 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 259 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 260 "data/maps/LittlerootTown/scripts.pory"
	end
# 261 "data/maps/LittlerootTown/scripts.pory"

# 262 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 263 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 264 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 265 "data/maps/LittlerootTown/scripts.pory"
	end
# 266 "data/maps/LittlerootTown/scripts.pory"

# 267 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 268 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 269 "data/maps/LittlerootTown/scripts.pory"
	end
# 270 "data/maps/LittlerootTown/scripts.pory"

# 271 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 272 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 273 "data/maps/LittlerootTown/scripts.pory"
	end
# 274 "data/maps/LittlerootTown/scripts.pory"

# 275 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 276 "data/maps/LittlerootTown/scripts.pory"
	lock
# 277 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 278 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 279 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 280 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 281 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 282 "data/maps/LittlerootTown/scripts.pory"
	release
# 283 "data/maps/LittlerootTown/scripts.pory"
	end
# 284 "data/maps/LittlerootTown/scripts.pory"

# 285 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 286 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 287 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 288 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 289 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 290 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 291 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 292 "data/maps/LittlerootTown/scripts.pory"
	release
# 293 "data/maps/LittlerootTown/scripts.pory"
	end
# 294 "data/maps/LittlerootTown/scripts.pory"

# 295 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 296 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 297 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 298 "data/maps/LittlerootTown/scripts.pory"
	release
# 299 "data/maps/LittlerootTown/scripts.pory"
	end
# 300 "data/maps/LittlerootTown/scripts.pory"

# 301 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 302 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 303 "data/maps/LittlerootTown/scripts.pory"
	release
# 304 "data/maps/LittlerootTown/scripts.pory"
	end
# 305 "data/maps/LittlerootTown/scripts.pory"

# 306 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 307 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 308 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 309 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 310 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 311 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 312 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 313 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 314 "data/maps/LittlerootTown/scripts.pory"
	end
# 315 "data/maps/LittlerootTown/scripts.pory"

# 316 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 317 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 318 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 319 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 320 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 321 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 322 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 323 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 324 "data/maps/LittlerootTown/scripts.pory"
	return
# 325 "data/maps/LittlerootTown/scripts.pory"

# 326 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 327 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 328 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 329 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 330 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 331 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 334 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 335 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 336 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 337 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 339 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 340 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 341 "data/maps/LittlerootTown/scripts.pory"

# 342 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 343 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 344 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 345 "data/maps/LittlerootTown/scripts.pory"

# 346 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 347 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 348 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 349 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 350 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 351 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 352 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 353 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 354 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 355 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 356 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 357 "data/maps/LittlerootTown/scripts.pory"

# 358 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 359 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 360 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 361 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 362 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 363 "data/maps/LittlerootTown/scripts.pory"

# 364 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 365 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 366 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 367 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 368 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 369 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 370 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 371 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 372 "data/maps/LittlerootTown/scripts.pory"
	end
# 373 "data/maps/LittlerootTown/scripts.pory"

# 374 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 375 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 376 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 377 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 378 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 379 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 380 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 381 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 382 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 383 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 384 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 385 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 386 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 387 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 388 "data/maps/LittlerootTown/scripts.pory"

# 389 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 390 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 391 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 392 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 393 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 394 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 395 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 396 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 397 "data/maps/LittlerootTown/scripts.pory"

# 398 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 399 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 400 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 401 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 402 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 403 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 404 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 405 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 406 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 407 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 408 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 409 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 410 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 411 "data/maps/LittlerootTown/scripts.pory"
	end
# 412 "data/maps/LittlerootTown/scripts.pory"

# 413 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 414 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 415 "data/maps/LittlerootTown/scripts.pory"
	end
# 416 "data/maps/LittlerootTown/scripts.pory"

# 417 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 418 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 419 "data/maps/LittlerootTown/scripts.pory"
	end
# 420 "data/maps/LittlerootTown/scripts.pory"

# 421 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 422 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 423 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 424 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 425 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 426 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 427 "data/maps/LittlerootTown/scripts.pory"
	end
# 428 "data/maps/LittlerootTown/scripts.pory"

# 429 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 430 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 431 "data/maps/LittlerootTown/scripts.pory"
	return
# 432 "data/maps/LittlerootTown/scripts.pory"

# 433 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 434 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 435 "data/maps/LittlerootTown/scripts.pory"
	return
# 436 "data/maps/LittlerootTown/scripts.pory"

# 437 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 438 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 439 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 440 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 441 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 442 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 443 "data/maps/LittlerootTown/scripts.pory"
	end
# 444 "data/maps/LittlerootTown/scripts.pory"

# 445 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 446 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 447 "data/maps/LittlerootTown/scripts.pory"
	return
# 448 "data/maps/LittlerootTown/scripts.pory"

# 449 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 450 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 451 "data/maps/LittlerootTown/scripts.pory"
	return
# 452 "data/maps/LittlerootTown/scripts.pory"

# 453 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 454 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 455 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 456 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 457 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 458 "data/maps/LittlerootTown/scripts.pory"
	end
# 459 "data/maps/LittlerootTown/scripts.pory"

# 460 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 461 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 462 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 463 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 464 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 465 "data/maps/LittlerootTown/scripts.pory"
	end
# 466 "data/maps/LittlerootTown/scripts.pory"

# 467 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 468 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 469 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 470 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 471 "data/maps/LittlerootTown/scripts.pory"
	end
# 472 "data/maps/LittlerootTown/scripts.pory"

# 473 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 474 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 475 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 476 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 477 "data/maps/LittlerootTown/scripts.pory"
	end
# 478 "data/maps/LittlerootTown/scripts.pory"

# 479 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 480 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 481 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 482 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 483 "data/maps/LittlerootTown/scripts.pory"
	end
# 484 "data/maps/LittlerootTown/scripts.pory"

# 485 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 486 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 487 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 488 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 489 "data/maps/LittlerootTown/scripts.pory"
	end
# 490 "data/maps/LittlerootTown/scripts.pory"

# 491 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 492 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 493 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 494 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 495 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 496 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 497 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 498 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 499 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 500 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 501 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 502 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 503 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 504 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 505 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 506 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 507 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 508 "data/maps/LittlerootTown/scripts.pory"
	end
# 509 "data/maps/LittlerootTown/scripts.pory"

# 510 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 511 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 512 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 513 "data/maps/LittlerootTown/scripts.pory"
	return
# 514 "data/maps/LittlerootTown/scripts.pory"

# 515 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 516 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 517 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 518 "data/maps/LittlerootTown/scripts.pory"
	return
# 519 "data/maps/LittlerootTown/scripts.pory"

# 520 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 521 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 522 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 523 "data/maps/LittlerootTown/scripts.pory"
	return
# 524 "data/maps/LittlerootTown/scripts.pory"

# 525 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 526 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 527 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 528 "data/maps/LittlerootTown/scripts.pory"
	return
# 529 "data/maps/LittlerootTown/scripts.pory"

# 530 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 531 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 532 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 533 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 534 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 535 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 536 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 537 "data/maps/LittlerootTown/scripts.pory"
	return
# 538 "data/maps/LittlerootTown/scripts.pory"

# 539 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 540 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 541 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 542 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 543 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 544 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 545 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 546 "data/maps/LittlerootTown/scripts.pory"
	return
# 547 "data/maps/LittlerootTown/scripts.pory"

# 548 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 549 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 550 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 551 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 552 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 553 "data/maps/LittlerootTown/scripts.pory"
	return
# 554 "data/maps/LittlerootTown/scripts.pory"

# 555 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 556 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 557 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 558 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 559 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 560 "data/maps/LittlerootTown/scripts.pory"
	return
# 561 "data/maps/LittlerootTown/scripts.pory"

# 562 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 563 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 564 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 565 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 566 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 567 "data/maps/LittlerootTown/scripts.pory"
	return
# 568 "data/maps/LittlerootTown/scripts.pory"

# 569 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 570 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 571 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 572 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 573 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 574 "data/maps/LittlerootTown/scripts.pory"
	return
# 575 "data/maps/LittlerootTown/scripts.pory"

# 576 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 577 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 578 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 579 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 580 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 581 "data/maps/LittlerootTown/scripts.pory"
	return
# 582 "data/maps/LittlerootTown/scripts.pory"

# 583 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 584 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 585 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 586 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 587 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 588 "data/maps/LittlerootTown/scripts.pory"
	return
# 589 "data/maps/LittlerootTown/scripts.pory"

# 590 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 591 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 592 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 593 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 594 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 595 "data/maps/LittlerootTown/scripts.pory"
	return
# 596 "data/maps/LittlerootTown/scripts.pory"

# 597 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 598 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 599 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 600 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 601 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 602 "data/maps/LittlerootTown/scripts.pory"
	return
# 603 "data/maps/LittlerootTown/scripts.pory"

# 604 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 605 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 606 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 607 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 608 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 609 "data/maps/LittlerootTown/scripts.pory"
	return
# 610 "data/maps/LittlerootTown/scripts.pory"

# 611 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 612 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 613 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 614 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 615 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 616 "data/maps/LittlerootTown/scripts.pory"
	return
# 617 "data/maps/LittlerootTown/scripts.pory"

# 618 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 619 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 620 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 621 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 622 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 623 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 624 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 625 "data/maps/LittlerootTown/scripts.pory"
	return
# 626 "data/maps/LittlerootTown/scripts.pory"

# 627 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 628 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 629 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 630 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 631 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 632 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 633 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 634 "data/maps/LittlerootTown/scripts.pory"
	return
# 635 "data/maps/LittlerootTown/scripts.pory"

# 636 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 637 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 638 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 639 "data/maps/LittlerootTown/scripts.pory"
	return
# 640 "data/maps/LittlerootTown/scripts.pory"

# 641 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/LittlerootTown/scripts.pory"
	return
# 645 "data/maps/LittlerootTown/scripts.pory"

# 646 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 647 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 648 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 649 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 650 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 651 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 652 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 653 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 654 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 655 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 656 "data/maps/LittlerootTown/scripts.pory"
	return
# 657 "data/maps/LittlerootTown/scripts.pory"

# 658 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 659 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 660 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 661 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 662 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 663 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 664 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 665 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 666 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 667 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 668 "data/maps/LittlerootTown/scripts.pory"
	return
# 669 "data/maps/LittlerootTown/scripts.pory"

# 670 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 671 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 672 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 673 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 674 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 675 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 676 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 677 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 678 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 679 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 680 "data/maps/LittlerootTown/scripts.pory"
	return
# 681 "data/maps/LittlerootTown/scripts.pory"

# 682 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 683 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 684 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 685 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 686 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 687 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 688 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 689 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 690 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 691 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 692 "data/maps/LittlerootTown/scripts.pory"
	return
# 693 "data/maps/LittlerootTown/scripts.pory"

# 694 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 695 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 696 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 697 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 698 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 699 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 700 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 701 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 702 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 703 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 704 "data/maps/LittlerootTown/scripts.pory"
	return
# 705 "data/maps/LittlerootTown/scripts.pory"

# 706 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 707 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 708 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 710 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 711 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 712 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 713 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 714 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 716 "data/maps/LittlerootTown/scripts.pory"
	return
# 717 "data/maps/LittlerootTown/scripts.pory"

# 718 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 719 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 720 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 721 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 722 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 723 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 724 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 725 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 726 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 727 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 728 "data/maps/LittlerootTown/scripts.pory"
	return
# 729 "data/maps/LittlerootTown/scripts.pory"

# 730 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 731 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 733 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 734 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 735 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 736 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 737 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 738 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 739 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 740 "data/maps/LittlerootTown/scripts.pory"
	return
# 741 "data/maps/LittlerootTown/scripts.pory"

# 742 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 743 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 744 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 745 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 746 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 747 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 748 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 749 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 750 "data/maps/LittlerootTown/scripts.pory"

# 751 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 755 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 756 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 757 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 758 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 759 "data/maps/LittlerootTown/scripts.pory"

# 760 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 761 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 762 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 763 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 764 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 765 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 766 "data/maps/LittlerootTown/scripts.pory"

# 767 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 768 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 769 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 770 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 771 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 773 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 774 "data/maps/LittlerootTown/scripts.pory"

# 775 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 777 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 778 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 779 "data/maps/LittlerootTown/scripts.pory"

# 780 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 782 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 783 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 784 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 785 "data/maps/LittlerootTown/scripts.pory"

# 786 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 787 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 790 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 791 "data/maps/LittlerootTown/scripts.pory"

# 792 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 793 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 794 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 795 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 796 "data/maps/LittlerootTown/scripts.pory"

# 797 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 798 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 799 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 801 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 802 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 803 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 804 "data/maps/LittlerootTown/scripts.pory"

# 805 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 806 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 807 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 809 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 810 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 811 "data/maps/LittlerootTown/scripts.pory"

# 812 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 813 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 814 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 815 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 817 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 818 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 819 "data/maps/LittlerootTown/scripts.pory"

# 820 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 822 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 823 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 824 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 826 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 827 "data/maps/LittlerootTown/scripts.pory"

# 828 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 832 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 834 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 835 "data/maps/LittlerootTown/scripts.pory"

# 836 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 838 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 839 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 842 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 843 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 844 "data/maps/LittlerootTown/scripts.pory"

# 845 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 846 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 847 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 849 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 850 "data/maps/LittlerootTown/scripts.pory"

# 851 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 854 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 856 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 857 "data/maps/LittlerootTown/scripts.pory"

# 858 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 859 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 862 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 863 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 864 "data/maps/LittlerootTown/scripts.pory"

# 865 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 866 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 867 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 869 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 870 "data/maps/LittlerootTown/scripts.pory"

# 871 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 874 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 875 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 876 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 878 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 879 "data/maps/LittlerootTown/scripts.pory"

# 880 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 881 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 883 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 885 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 886 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 887 "data/maps/LittlerootTown/scripts.pory"

# 888 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 889 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 890 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 891 "data/maps/LittlerootTown/scripts.pory"

# 892 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 893 "data/maps/LittlerootTown/scripts.pory"
	lock
# 894 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 895 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 896 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 897 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 898 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 899 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 900 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 901 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 902 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 903 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 904 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 905 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 906 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 907 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 908 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 909 "data/maps/LittlerootTown/scripts.pory"
	end
# 910 "data/maps/LittlerootTown/scripts.pory"

# 911 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 912 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 913 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 914 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 915 "data/maps/LittlerootTown/scripts.pory"
	release
# 916 "data/maps/LittlerootTown/scripts.pory"
	end
# 917 "data/maps/LittlerootTown/scripts.pory"

# 918 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 919 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 920 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 921 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 922 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 923 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 924 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 925 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 926 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 927 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 928 "data/maps/LittlerootTown/scripts.pory"
	return
# 929 "data/maps/LittlerootTown/scripts.pory"

# 930 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, bitch!\p"
# 932 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 933 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 934 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 935 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 936 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 938 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 939 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 940 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 941 "data/maps/LittlerootTown/scripts.pory"

# 942 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 943 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 944 "data/maps/LittlerootTown/scripts.pory"

# 945 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 946 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 947 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 948 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 949 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 950 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 951 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 952 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 953 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 955 "data/maps/LittlerootTown/scripts.pory"

# 956 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 957 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 959 "data/maps/LittlerootTown/scripts.pory"

# 960 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 961 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 962 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 963 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 964 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 965 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 966 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 967 "data/maps/LittlerootTown/scripts.pory"

# 968 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 969 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 972 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 973 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 975 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 976 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 977 "data/maps/LittlerootTown/scripts.pory"

# 978 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 981 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 982 "data/maps/LittlerootTown/scripts.pory"

# 983 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 985 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 986 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 987 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 989 "data/maps/LittlerootTown/scripts.pory"

# 990 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 991 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 993 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 994 "data/maps/LittlerootTown/scripts.pory"

# 995 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 996 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 997 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 998 "data/maps/LittlerootTown/scripts.pory"

# 999 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 1001 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 1002 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 1003 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 1004 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 1005 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 1006 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 1007 "data/maps/LittlerootTown/scripts.pory"

# 1008 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 1009 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 1011 "data/maps/LittlerootTown/scripts.pory"

# 1012 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 1015 "data/maps/LittlerootTown/scripts.pory"

# 1016 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 1019 "data/maps/LittlerootTown/scripts.pory"

# 1020 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 1022 "data/maps/LittlerootTown/scripts.pory"

# 1023 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 1024 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 1025 "data/maps/LittlerootTown/scripts.pory"

# 1026 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 1027 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 1028 "data/maps/LittlerootTown/scripts.pory"

# 1029 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 1030 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 1031 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1032 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1033 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1034 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1035 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 1036 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 1037 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1038 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

LittlerootTown_EventScript_Debug_Pokemon_Text_0:
# 6 "data/maps/LittlerootTown/scripts.pory"
	.string "Wow! Is that Darkrai?!$"
