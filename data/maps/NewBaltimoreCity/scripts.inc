NewBaltimoreCity_MapScripts::
	.byte 0


NewBaltimore_TM_Gift::
# 6 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 7 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 8 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_8
NewBaltimore_TM_Gift_7:
# 14 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_3
# 18 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBaltimore_TM_Gift_4
# 22 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
NewBaltimore_TM_Gift_1:
# 24 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	end

NewBaltimore_TM_Gift_2:
# 10 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 11 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_APARTMENT_1F, 9, 3
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_3:
# 15 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 16 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_TM_FLAMETHROWER
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_4:
# 19 "data/maps/NewBaltimoreCity/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_8:
# 8 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, NewBaltimore_TM_Gift_2
	goto NewBaltimore_TM_Gift_7


NewBaltimore_Outside_Trainer::
# 51 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 52 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 53 "data/maps/NewBaltimoreCity/scripts.pory"
	random 3
# 54 "data/maps/NewBaltimoreCity/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/NewBaltimoreCity/scripts.pory"
	case 0, NewBaltimore_Outside_Trainer_3
# 57 "data/maps/NewBaltimoreCity/scripts.pory"
	case 1, NewBaltimore_Outside_Trainer_4
# 59 "data/maps/NewBaltimoreCity/scripts.pory"
	case 2, NewBaltimore_Outside_Trainer_5
NewBaltimore_Outside_Trainer_1:
# 62 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Outside_Trainer_3:
# 56 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE
	goto NewBaltimore_Outside_Trainer_1

NewBaltimore_Outside_Trainer_4:
# 58 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done
	goto NewBaltimore_Outside_Trainer_1

NewBaltimore_Outside_Trainer_5:
# 60 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Intro
	goto NewBaltimore_Outside_Trainer_1


NewBaltimore_Outside_Sketchy_Trainer::
# 66 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 67 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 69 "data/maps/NewBaltimoreCity/scripts.pory"
	switch VAR_TEMP_0
# 70 "data/maps/NewBaltimoreCity/scripts.pory"
	case 0, NewBaltimore_Outside_Sketchy_Trainer_3
# 73 "data/maps/NewBaltimoreCity/scripts.pory"
	case 1, NewBaltimore_Outside_Sketchy_Trainer_4
# 76 "data/maps/NewBaltimoreCity/scripts.pory"
	case 2, NewBaltimore_Outside_Sketchy_Trainer_5
# 79 "data/maps/NewBaltimoreCity/scripts.pory"
	case 3, NewBaltimore_Outside_Sketchy_Trainer_6
# 82 "data/maps/NewBaltimoreCity/scripts.pory"
	case 4, NewBaltimore_Outside_Sketchy_Trainer_7
NewBaltimore_Outside_Sketchy_Trainer_1:
# 91 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Outside_Sketchy_Trainer_3:
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_0
# 72 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_4:
# 74 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_1
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_5:
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_2
# 78 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 3
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_6:
# 80 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_3
# 81 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 4
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_7:
# 83 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 84 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_4
# 89 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto NewBaltimore_Outside_Sketchy_Trainer_1


NewBaltimore_You_Did_It::
# 113 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 114 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 115 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done, MSGBOX_DEFAULT
# 116 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_Berry_Fan::
# 120 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 121 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 122 "data/maps/NewBaltimoreCity/scripts.pory"
	specialvar VAR_RESULT, PlayerHasBerries
# 123 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq NewBaltimore_Berry_Fan_2
# 129 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Berry_Fan_Text_1
# 130 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY
NewBaltimore_Berry_Fan_1:
# 132 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Berry_Fan_2:
# 124 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 125 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Berry_Fan_Text_0
# 126 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto NewBaltimore_Berry_Fan_1


rayquaza_call_test::
# 136 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 137 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 138 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox rayquaza_call_test_Text_0
# 139 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


Test_Call_Script::
# 143 "data/maps/NewBaltimoreCity/scripts.pory"
	lockall
# 144 "data/maps/NewBaltimoreCity/scripts.pory"
	pokenavcall Test_Call_Text
# 145 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
# 146 "data/maps/NewBaltimoreCity/scripts.pory"
	clearflag FLAG_TEST_CALL_0x265
# 147 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_HOME, 9, 3
# 148 "data/maps/NewBaltimoreCity/scripts.pory"
	releaseall
	end


NewBaltimore_Trainer_Taraneh::
# 163 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 164 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
# 165 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
	end


# 191 "data/maps/NewBaltimoreCity/scripts.pory"

# 192 "data/maps/NewBaltimoreCity/scripts.pory"

# 193 "data/maps/NewBaltimoreCity/scripts.pory"
NewBaltimoreCity_EventScript_Houshang::
# 194 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_HOUSHANG, NBC_Text_HoushangIntro, NBC_Text_HoushangDefeat
# 195 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NBC_Text_HoushangPostBattle, MSGBOX_AUTOCLOSE
# 196 "data/maps/NewBaltimoreCity/scripts.pory"
	end

NewBaltimore_Outside_Sketchy_Trainer_Text_0:
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I ain't sayin' nuthin.$"

NewBaltimore_Outside_Sketchy_Trainer_Text_1:
# 74 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I didn't see nuthin.$"

NewBaltimore_Outside_Sketchy_Trainer_Text_2:
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "So maybe I was at Tommy Joe's that\n"
	.string "night. So what?$"

NewBaltimore_Outside_Sketchy_Trainer_Text_3:
# 80 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Fine, I'll 'fess up. Sonny did it!$"

NewBaltimore_Outside_Sketchy_Trainer_Text_4:
# 84 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Well for Tauros fans there is, of\n"
	.string "course, cause for celebration tonight\l"
	.string "after a sixth championship that came\l"
	.string "harder than the others - but there's\l"
	.string "some anxiousness as well. Who knows how\l"
	.string "all of this will play out, but it's\l"
	.string "certainly possible that tonight we have\l"
	.string "seen the last of the Unova Tauros as\l"
	.string "we've known them. And whether it ends\l"
	.string "here, or sometime in the near future,\l"
	.string "it'll be noteworthy not only for the\l"
	.string "breakup of one of the great teams in\l"
	.string "Pokemon history, but because given the\l"
	.string "current structure of the Pokemon\l"
	.string "League, it may be quite a while before\l"
	.string "we see anything like this again.$"

NewBaltimore_Berry_Fan_Text_0:
# 125 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "The inner machinations of my berries\n"
	.string "are an enigma.$"

NewBaltimore_Berry_Fan_Text_1:
# 129 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Berries are an important part of any\n"
	.string "trainer's diet. Here, take one!$"

rayquaza_call_test_Text_0:
# 138 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Stupid snake...$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis::
# 28 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Boy do I love the smell of napalm\n"
	.string "in the morning, don't you?\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for setting shit on fire.$"

Mandy::
# 36 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Talk to Mandy first.$"

NewBaltimore_Trainer_EZ_HOE::
# 98 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

Test_Call_Text::
# 152 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Hi mom!$"

NewBaltimore_Trainer_Done::
# 156 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Congratulations!$"

Trainer_Taraneh_Intro::
# 171 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 177 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 181 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
