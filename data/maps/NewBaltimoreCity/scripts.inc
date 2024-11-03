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
# 21 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_3
# 25 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBaltimore_TM_Gift_4
# 29 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
NewBaltimore_TM_Gift_1:
# 31 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	end

NewBaltimore_TM_Gift_2:
# 18 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 19 "data/maps/NewBaltimoreCity/scripts.pory"
	warp MAP_NEW_BALTIMORE_CITY_APARTMENT_1F, 9, 3
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_3:
# 22 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 23 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_TM_FLAMETHROWER
# 24 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_4:
# 26 "data/maps/NewBaltimoreCity/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_8:
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, NewBaltimore_TM_Gift_2
	goto NewBaltimore_TM_Gift_7


NewBaltimore_Outside_Trainer::
# 50 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 51 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 52 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
# 53 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_TEST_CALL_0x265
# 54 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_You_Did_It::
# 68 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 69 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 70 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done, MSGBOX_DEFAULT
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


rayquaza_call_test::
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 76 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox rayquaza_call_test_Text_0
# 78 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


Test_Call_Script::
# 82 "data/maps/NewBaltimoreCity/scripts.pory"
	lockall
# 83 "data/maps/NewBaltimoreCity/scripts.pory"
	pokenavcall Test_Call_Text
# 84 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
# 85 "data/maps/NewBaltimoreCity/scripts.pory"
	clearflag FLAG_TEST_CALL_0x265
# 86 "data/maps/NewBaltimoreCity/scripts.pory"
	releaseall
	end


NewBaltimore_Trainer_Taraneh::
# 101 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 102 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
# 103 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
	end


# 129 "data/maps/NewBaltimoreCity/scripts.pory"

# 130 "data/maps/NewBaltimoreCity/scripts.pory"

# 131 "data/maps/NewBaltimoreCity/scripts.pory"
NewBaltimoreCity_EventScript_Houshang::
# 132 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_HOUSHANG, NBC_Text_HoushangIntro, NBC_Text_HoushangDefeat
# 133 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NBC_Text_HoushangPostBattle, MSGBOX_AUTOCLOSE
# 134 "data/maps/NewBaltimoreCity/scripts.pory"
	end

rayquaza_call_test_Text_0:
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Stupid snake...$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis::
# 35 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Boy do I love the smell of napalm\n"
	.string "in the morning, don't you?\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for setting shit on fire.$"

Mandy::
# 43 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Talk to Mandy first.$"

NewBaltimore_Trainer_EZ_HOE::
# 61 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

Test_Call_Text::
# 90 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Hi mom!$"

NewBaltimore_Trainer_Done::
# 94 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Congratulations!$"

Trainer_Taraneh_Intro::
# 109 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 115 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 119 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
