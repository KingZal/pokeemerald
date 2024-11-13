NewBaltimoreCity_MapScripts::
	.byte 0


NewBaltimore_TM_Gift::
# 15 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 16 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_8
NewBaltimore_TM_Gift_7:
# 22 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_3
# 26 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBaltimore_TM_Gift_4
# 30 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
NewBaltimore_TM_Gift_1:
# 32 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	end

NewBaltimore_TM_Gift_2:
# 18 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 19 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_APARTMENT_1F, 9, 3
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_3:
# 23 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 24 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_TM_FLAMETHROWER
# 25 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_4:
# 27 "data/maps/NewBaltimoreCity/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_8:
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, NewBaltimore_TM_Gift_2
	goto NewBaltimore_TM_Gift_7


NewBaltimore_Outside_Trainer::
# 51 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 52 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 53 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
# 54 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_TEST_CALL_0x265
# 55 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_You_Did_It::
# 69 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 70 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done, MSGBOX_DEFAULT
# 72 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


rayquaza_call_test::
# 76 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 78 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox rayquaza_call_test_Text_0
# 79 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


Test_Call_Script::
# 83 "data/maps/NewBaltimoreCity/scripts.pory"
	lockall
# 84 "data/maps/NewBaltimoreCity/scripts.pory"
	pokenavcall Test_Call_Text
# 85 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
# 86 "data/maps/NewBaltimoreCity/scripts.pory"
	playse SE_RG_DEOXYS_MOVE
# 87 "data/maps/NewBaltimoreCity/scripts.pory"
	clearflag FLAG_TEST_CALL_0x265
# 88 "data/maps/NewBaltimoreCity/scripts.pory"
	warpsilent MAP_NEW_BALTIMORE_CITY_HOME, 9, 3
# 89 "data/maps/NewBaltimoreCity/scripts.pory"
	releaseall
	end


NewBaltimore_Trainer_Taraneh::
# 104 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 105 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
# 106 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
	end


# 132 "data/maps/NewBaltimoreCity/scripts.pory"

# 133 "data/maps/NewBaltimoreCity/scripts.pory"

# 134 "data/maps/NewBaltimoreCity/scripts.pory"
NewBaltimoreCity_EventScript_Houshang::
# 135 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_HOUSHANG, NBC_Text_HoushangIntro, NBC_Text_HoushangDefeat
# 136 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NBC_Text_HoushangPostBattle, MSGBOX_AUTOCLOSE
# 137 "data/maps/NewBaltimoreCity/scripts.pory"
	end

rayquaza_call_test_Text_0:
# 78 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Stupid snake...$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis::
# 36 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Boy do I love the smell of napalm\n"
	.string "in the morning, don't you?\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for setting shit on fire.$"

Mandy::
# 44 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Talk to Mandy first.$"

NewBaltimore_Trainer_EZ_HOE::
# 62 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

Test_Call_Text::
# 93 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Hi mom!$"

NewBaltimore_Trainer_Done::
# 97 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Congratulations!$"

Trainer_Taraneh_Intro::
# 112 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 118 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 122 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
