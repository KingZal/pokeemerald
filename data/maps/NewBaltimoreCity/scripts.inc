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
# 20 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_3
# 24 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBaltimore_TM_Gift_4
# 28 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
NewBaltimore_TM_Gift_1:
# 30 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	end

NewBaltimore_TM_Gift_2:
# 18 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_3:
# 21 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 22 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_TM_FLAMETHROWER
# 23 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_4:
# 25 "data/maps/NewBaltimoreCity/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_8:
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, NewBaltimore_TM_Gift_2
	goto NewBaltimore_TM_Gift_7


NewBaltimore_Outside_Trainer::
# 49 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 50 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 51 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
# 52 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_You_Did_It::
# 62 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 63 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 64 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_Done, MSGBOX_DEFAULT
# 65 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_Trainer_Taraneh::
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 76 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
# 77 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
	end


# 103 "data/maps/NewBaltimoreCity/scripts.pory"


Route104_Text_LikeFillingMouthWithSeedsTakeThis::
# 34 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Boy do I love the smell of napalm\n"
	.string "in the morning, don't you?\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for setting shit on fire.$"

Mandy::
# 42 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Talk to Mandy first.$"

NewBaltimore_Trainer_EZ_HOE::
# 55 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

NewBaltimore_Trainer_Done::
# 68 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Congratulations!$"

Trainer_Taraneh_Intro::
# 83 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 89 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 93 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
