NewBaltimoreCity_Home_MapScripts::
	.byte 0


NBC_Home_PC::
# 4 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 5 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	goto Home_Computer_On
	end


Home_Computer_On::
# 11 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 12 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	special DoPCTurnOnEffect
# 13 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	playse SE_PC_ON
# 14 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 15 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	special BedroomPC
# 16 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	waitstate
# 17 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	end


Home_Computer_Off::
# 22 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 23 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	playse SE_PC_OFF
# 24 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	special DoPCTurnOffEffect
# 25 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	end


NBC_Child_PC::
# 30 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lock
# 31 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	random 3
# 32 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	switch VAR_RESULT
# 33 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	case 0, NBC_Child_PC_3
# 35 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	case 1, NBC_Child_PC_4
# 37 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	case 2, NBC_Child_PC_5
NBC_Child_PC_1:
# 40 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	playse SE_PC_OFF
# 41 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	release
	end

NBC_Child_PC_3:
# 34 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox child_PC_1, MSGBOX_DEFAULT
	goto NBC_Child_PC_1

NBC_Child_PC_4:
# 36 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox child_PC_2, MSGBOX_DEFAULT
	goto NBC_Child_PC_1

NBC_Child_PC_5:
# 38 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox child_PC_3, MSGBOX_DEFAULT
	goto NBC_Child_PC_1


trainer_1::
# 66 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 67 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox trainer_1_Text_0
# 68 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	return


trainer_2::
# 72 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 73 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox trainer_2_Text_0
# 74 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	return


trainer_3::
# 78 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	lockall
# 79 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	msgbox trainer_3_Text_0
# 80 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	releaseall
	return


trainer_1_Text_0:
# 67 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "I'm number one.$"

trainer_2_Text_0:
# 73 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "I'm number two.$"

trainer_3_Text_0:
# 79 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "I'm number three.$"

child_PC_1::
# 46 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "You used to help Lynda with homework here.\p"
	.string ".............\l"
	.string "Better get going.$"

child_PC_2::
# 52 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "Lynda spent so much time researching\n"
	.string "different Pokemon here.\p"
	.string ".............\l"
	.string "Better get going.$"

child_PC_3::
# 59 "data/maps/NewBaltimoreCity_Home/scripts.pory"
	.string "Lynda's computer hasn't been used much \n"
	.string "since she moved out.\p"
	.string ".............\l"
	.string "Better get going.$"
