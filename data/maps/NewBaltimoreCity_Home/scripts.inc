NewBaltimoreCity_Home_MapScripts::
	.byte 0


NBC_Home_PC::
# 4 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 5 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	goto Home_Computer_On
	end


Home_Computer_On::
# 10 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 11 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	playse SE_PC_ON
# 12 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 13 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	special BedroomPC
# 14 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	waitstate
# 15 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	end


Home_Computer_Off::
# 20 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 21 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	playse SE_PC_OFF
# 22 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	special DoPCTurnOffEffect
# 23 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	end


trainer_1::
# 28 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 29 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox trainer_1_Text_0
# 30 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	return


trainer_2::
# 34 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 35 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox trainer_2_Text_0
# 36 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	return


trainer_3::
# 40 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 41 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox trainer_3_Text_0
# 42 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	return


trainer_1_Text_0:
# 29 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "I'm number one.$"

trainer_2_Text_0:
# 35 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "I'm number two.$"

trainer_3_Text_0:
# 41 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "I'm number three.$"
