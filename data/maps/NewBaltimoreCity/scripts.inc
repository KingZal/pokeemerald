NewBaltimoreCity_MapScripts::
	.byte 0


NewBaltimore_TM_Gift::
# 15 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 16 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 17 "data/maps/NewBaltimoreCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FLAMETHROWER, NewBaltimore_TM_Gift_2
# 20 "data/maps/NewBaltimoreCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBaltimore_TM_Gift_3
# 24 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
NewBaltimore_TM_Gift_1:
# 26 "data/maps/NewBaltimoreCity/scripts.pory"
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
# 27 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	end

NewBaltimore_TM_Gift_2:
# 18 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 19 "data/maps/NewBaltimoreCity/scripts.pory"
	giveitem ITEM_TM_FLAMETHROWER
	goto NewBaltimore_TM_Gift_1

NewBaltimore_TM_Gift_3:
# 21 "data/maps/NewBaltimoreCity/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto NewBaltimore_TM_Gift_1


NewBaltimore_Outside_Trainer::
# 42 "data/maps/NewBaltimoreCity/scripts.pory"
	lock
# 43 "data/maps/NewBaltimoreCity/scripts.pory"
	faceplayer
# 44 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox NewBaltimore_Trainer_EZ_HOE, MSGBOX_DEFAULT
# 45 "data/maps/NewBaltimoreCity/scripts.pory"
	release
	return


NewBaltimore_Trainer_Taraneh::
# 57 "data/maps/NewBaltimoreCity/scripts.pory"
	trainerbattle_single TRAINER_TARANEH, Trainer_Taraneh_Intro, Trainer_Taraneh_Outro
# 58 "data/maps/NewBaltimoreCity/scripts.pory"
	msgbox Trainer_Taraneh_Post_Battle, MSGBOX_AUTOCLOSE
# 59 "data/maps/NewBaltimoreCity/scripts.pory"
	waitmessage
	end


# 85 "data/maps/NewBaltimoreCity/scripts.pory"


Route104_Text_LikeFillingMouthWithSeedsTakeThis::
# 31 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Boy do I love the smell of napalm\n"
	.string "in the morning, don't you?\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for setting shit on fire.$"

NewBaltimore_Trainer_EZ_HOE::
# 48 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "Easy come,\n"
	.string "Easy go,\l"
	.string "Easily I shoot you hoe.$"

Trainer_Taraneh_Intro::
# 65 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "There is a time and place\n"
	.string "for trainer battles.\p"
	.string "Any time, any place.$"

Trainer_Taraneh_Outro::
# 71 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "You got me!$"

Trainer_Taraneh_Post_Battle::
# 75 "data/maps/NewBaltimoreCity/scripts.pory"
	.string "I'd rematch you but I\n"
	.string "haven't figured it out yet.$"
