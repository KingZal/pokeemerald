NewBaltimoreCity_Home_Lobby_MapScripts::
# 2 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OnTransition
# 3 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBaltimoreCity_Home_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

NewBaltimoreCity_Home_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, EntranceAlthea
	.2byte 0


OnTransition::
# 12 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	goto_if_set FLAG_LAVENDER_0x266, OnTransition_1
	return

OnTransition_1:
# 13 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setvar VAR_TEMP_0, 1
	return


EntranceAlthea::
# 18 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	applymovement 2, Common_Movement_FaceUp
# 23 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox receptionist_opening_rage, MSGBOX_DEFAULT
# 24 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	delay 40
# 25 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 26 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	delay 5
# 28 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, lobby_first_move
# 29 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	delay 25
# 30 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 2
# 31 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	delay 5
# 32 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	playse SE_BOO
# 33 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 34 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 2
# 35 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 36 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	delay 40
# 37 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox EntranceAlthea_Text_0, MSGBOX_DEFAULT
# 38 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 39 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_LAVENDER_0x266
# 40 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setvar VAR_TEMP_0, 1
	return


lobby_first_move::
# 44 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	walk_up
# 45 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	walk_up
# 46 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	walk_up
# 47 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	step_end
	return


znh_hidden::
# 61 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	lockall
# 62 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox zora_neale_hurston
# 63 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	releaseall
	return


Home_Lobby_Greeter::
# 72 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	lock
# 73 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	faceplayer
# 74 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, Home_Lobby_Greeter_2
# 92 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox Home_Lobby_Greeter_Text_0, MSGBOX_DEFAULT
# 93 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	playse SE_M_BELLY_DRUM
Home_Lobby_Greeter_1:
# 95 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	release
	end

Home_Lobby_Greeter_2:
# 75 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox lobby_elevator_broke, MSGBOX_DEFAULT
# 76 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 77 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 78 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 79 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 80 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	playse SE_BANG
# 81 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 82 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE01_GET
# 83 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE02_GET
# 84 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE03_GET
# 85 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE04_GET
# 86 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE05_GET
# 87 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE06_GET
# 88 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE07_GET
# 89 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	setflag FLAG_BADGE08_GET
	goto Home_Lobby_Greeter_1


EntranceAlthea_Text_0:
# 37 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "S-sorry, you weren't supposed to hear\n"
	.string "that...$"

Home_Lobby_Greeter_Text_0:
# 92 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "It's still not working.$"

lobby_elevator_broke::
# 50 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "Don't bother with the elevator, it's not\n"
	.string "working.$"

receptionist_opening_rage::
# 54 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "What would you have me do?\n"
	.string "Dye my hair and insist I'm white?\p"
	.string "You know what I'd look like with\nBLONDE hair Althea?\p LIKE A GRILLED CHEESE SANDWICH!$"

zora_neale_hurston::
# 66 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "IF YOU ARE SILENT ABOUT YOUR PAIN,\n"
	.string "THEY'LL KILL YOU AND SAY YOU ENJOYED IT.$"
