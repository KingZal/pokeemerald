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
# 15 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_3
# 19 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBaltimore_TM_Gift_4
# 23 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
NewBaltimore_TM_Gift_1:
# 25 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	end

NewBaltimore_TM_Gift_2:
# 10 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 11 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_APARTMENT_1F, 9, 3
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_3:
# 16 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_TM_FLAMETHROWER
# 18 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_4:
# 20 "data/maps/NewBaltimoreCity/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_8:
# 8 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, NewBaltimore_TM_Gift_2
	goto NewBaltimore_TM_Gift_7


NewBaltimore_Outside_Trainer::
# 52 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 53 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 54 "data/maps/NewBaltimoreCity/scripts.pory"
	random 3
# 55 "data/maps/NewBaltimoreCity/scripts.pory"
	switch VAR_RESULT
# 56 "data/maps/NewBaltimoreCity/scripts.pory"
	case 0, NewBaltimore_Outside_Trainer_3
# 58 "data/maps/NewBaltimoreCity/scripts.pory"
	case 1, NewBaltimore_Outside_Trainer_4
# 60 "data/maps/NewBaltimoreCity/scripts.pory"
	case 2, NewBaltimore_Outside_Trainer_5
NewBaltimore_Outside_Trainer_1:
# 63 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Outside_Trainer_3:
# 57 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE
	goto NewBaltimore_Outside_Trainer_1

NewBaltimore_Outside_Trainer_4:
# 59 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done
	goto NewBaltimore_Outside_Trainer_1

NewBaltimore_Outside_Trainer_5:
# 61 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Intro
	goto NewBaltimore_Outside_Trainer_1


NewBaltimore_Outside_Sketchy_Trainer::
# 67 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 68 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 70 "data/maps/NewBaltimoreCity/scripts.pory"
	switch VAR_TEMP_0
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	case 0, NewBaltimore_Outside_Sketchy_Trainer_3
# 74 "data/maps/NewBaltimoreCity/scripts.pory"
	case 1, NewBaltimore_Outside_Sketchy_Trainer_4
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	case 2, NewBaltimore_Outside_Sketchy_Trainer_5
# 80 "data/maps/NewBaltimoreCity/scripts.pory"
	case 3, NewBaltimore_Outside_Sketchy_Trainer_6
# 83 "data/maps/NewBaltimoreCity/scripts.pory"
	case 4, NewBaltimore_Outside_Sketchy_Trainer_7
NewBaltimore_Outside_Sketchy_Trainer_1:
# 93 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Outside_Sketchy_Trainer_3:
# 72 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_0
# 73 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_4:
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_1
# 76 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_5:
# 78 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_2
# 79 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 3
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_6:
# 81 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_3
# 82 "data/maps/NewBaltimoreCity/scripts.pory"
	setvar VAR_TEMP_0, 4
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_7:
# 84 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 85 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_4
# 90 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_HOME, 9, 3
# 91 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto NewBaltimore_Outside_Sketchy_Trainer_1


NewBaltimore_You_Did_It::
# 115 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 116 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 117 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done, MSGBOX_DEFAULT
# 118 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_Berry_Fan::
# 122 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 123 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 124 "data/maps/NewBaltimoreCity/scripts.pory"
	specialvar VAR_RESULT, PlayerHasBerries
# 125 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq NewBaltimore_Berry_Fan_2
# 131 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Berry_Fan_Text_1
# 132 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY
NewBaltimore_Berry_Fan_1:
# 134 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Berry_Fan_2:
# 126 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 127 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Berry_Fan_Text_0
# 128 "data/maps/NewBaltimoreCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto NewBaltimore_Berry_Fan_1


rayquaza_call_test::
# 138 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 139 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 140 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox rayquaza_call_test_Text_0
# 141 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


Test_Call_Script::
# 145 "data/maps/NewBaltimoreCity/scripts.pory"
	lockall
# 146 "data/maps/NewBaltimoreCity/scripts.pory"
	pokenavcall Test_Call_Text
# 147 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
# 148 "data/maps/NewBaltimoreCity/scripts.pory"
	clearflag FLAG_TEST_CALL_0x265
# 149 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_HOME, 9, 3
# 150 "data/maps/NewBaltimoreCity/scripts.pory"
	releaseall
	end


NewBaltimore_Trainer_Taraneh::
# 165 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 166 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
	end


# 192 "data/maps/NewBaltimoreCity/scripts.pory"

# 193 "data/maps/NewBaltimoreCity/scripts.pory"

# 194 "data/maps/NewBaltimoreCity/scripts.pory"
NewBaltimoreCity_EventScript_Houshang::
# 195 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_HOUSHANG, NBC_Text_HoushangIntro, NBC_Text_HoushangDefeat
# 196 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NBC_Text_HoushangPostBattle, MSGBOX_AUTOCLOSE
# 197 "data/maps/NewBaltimoreCity/scripts.pory"
	end

NewBaltimore_Outside_Sketchy_Trainer_Text_0:
# 72 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I ain't sayin' nuthin.$"

NewBaltimore_Outside_Sketchy_Trainer_Text_1:
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I didn't see nuthin.$"

NewBaltimore_Outside_Sketchy_Trainer_Text_2:
# 78 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "So maybe I was at Tommy Joe's that\n"
	.string "night. So what?$"

NewBaltimore_Outside_Sketchy_Trainer_Text_3:
# 81 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Fine, I'll 'fess up. Sonny did it!$"

NewBaltimore_Outside_Sketchy_Trainer_Text_4:
# 85 "data/maps/NewBaltimoreCity/scripts.pory"
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
# 127 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "The inner machinations of my berries\n"
	.string "are an enigma.$"

NewBaltimore_Berry_Fan_Text_1:
# 131 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Berries are an important part of any\n"
	.string "trainer's diet. Here, take one!$"

rayquaza_call_test_Text_0:
# 140 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Stupid snake...$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis::
# 29 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Boy do I love the smell of napalm\n"
	.string "in the morning, don't you?\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for setting shit on fire.$"

Mandy::
# 37 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Talk to Mandy first.$"

NewBaltimore_Trainer_EZ_HOE::
# 100 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

Test_Call_Text::
# 154 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Hi mom!$"

NewBaltimore_Trainer_Done::
# 158 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Congratulations!$"

Trainer_Taraneh_Intro::
# 172 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 178 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 182 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
