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
	switch VAR_RESULT
# 70 "data/maps/NewBaltimoreCity/scripts.pory"
	case 0, NewBaltimore_Outside_Sketchy_Trainer_3
# 72 "data/maps/NewBaltimoreCity/scripts.pory"
	case 1, NewBaltimore_Outside_Sketchy_Trainer_4
# 74 "data/maps/NewBaltimoreCity/scripts.pory"
	case 2, NewBaltimore_Outside_Sketchy_Trainer_5
# 76 "data/maps/NewBaltimoreCity/scripts.pory"
	case 3, NewBaltimore_Outside_Sketchy_Trainer_6
NewBaltimore_Outside_Sketchy_Trainer_1:
# 79 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Outside_Sketchy_Trainer_3:
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_0
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_4:
# 73 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_1
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_5:
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_2
	goto NewBaltimore_Outside_Sketchy_Trainer_1

NewBaltimore_Outside_Sketchy_Trainer_6:
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Outside_Sketchy_Trainer_Text_3
	goto NewBaltimore_Outside_Sketchy_Trainer_1


NewBaltimore_You_Did_It::
# 93 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 94 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 95 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done, MSGBOX_DEFAULT
# 96 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_Berry_Fan::
# 100 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 101 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 102 "data/maps/NewBaltimoreCity/scripts.pory"
	specialvar VAR_RESULT, PlayerHasBerries
# 103 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq NewBaltimore_Berry_Fan_2
# 107 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Berry_Fan_Text_1
# 108 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY
NewBaltimore_Berry_Fan_1:
# 110 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return

NewBaltimore_Berry_Fan_2:
# 104 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Berry_Fan_Text_0
	goto NewBaltimore_Berry_Fan_1


rayquaza_call_test::
# 114 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 115 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 116 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox rayquaza_call_test_Text_0
# 117 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


Test_Call_Script::
# 121 "data/maps/NewBaltimoreCity/scripts.pory"
	lockall
# 122 "data/maps/NewBaltimoreCity/scripts.pory"
	pokenavcall Test_Call_Text
# 123 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
# 124 "data/maps/NewBaltimoreCity/scripts.pory"
	clearflag FLAG_TEST_CALL_0x265
# 125 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_HOME, 9, 3
# 126 "data/maps/NewBaltimoreCity/scripts.pory"
	releaseall
	end


NewBaltimore_Trainer_Taraneh::
# 141 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 142 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
# 143 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
	end


# 169 "data/maps/NewBaltimoreCity/scripts.pory"

# 170 "data/maps/NewBaltimoreCity/scripts.pory"

# 171 "data/maps/NewBaltimoreCity/scripts.pory"
NewBaltimoreCity_EventScript_Houshang::
# 172 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_HOUSHANG, NBC_Text_HoushangIntro, NBC_Text_HoushangDefeat
# 173 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NBC_Text_HoushangPostBattle, MSGBOX_AUTOCLOSE
# 174 "data/maps/NewBaltimoreCity/scripts.pory"
	end

NewBaltimore_Outside_Sketchy_Trainer_Text_0:
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I ain't sayin' nuthin.$"

NewBaltimore_Outside_Sketchy_Trainer_Text_1:
# 73 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I didn't see nuthin.$"

NewBaltimore_Outside_Sketchy_Trainer_Text_2:
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "So maybe I was at Tommy Joe's that\n"
	.string "night. So what?$"

NewBaltimore_Outside_Sketchy_Trainer_Text_3:
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Fine, I'll 'fess up. Sonny did it!$"

NewBaltimore_Berry_Fan_Text_0:
# 104 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "The inner machinations of my berries\n"
	.string "are an enigma.$"

NewBaltimore_Berry_Fan_Text_1:
# 107 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Berries are an important part of any\n"
	.string "trainer's diet. Here, take one!$"

rayquaza_call_test_Text_0:
# 116 "data/maps/NewBaltimoreCity/scripts.pory"
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
# 86 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

Test_Call_Text::
# 130 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Hi mom!$"

NewBaltimore_Trainer_Done::
# 134 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Congratulations!$"

Trainer_Taraneh_Intro::
# 149 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 155 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 159 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
