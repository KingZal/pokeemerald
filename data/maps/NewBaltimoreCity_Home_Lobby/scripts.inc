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


Home_Lobby_Greeter::
# 61 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	lock
# 62 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	faceplayer
# 63 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	goto_if_unset FLAG_BUDDY_0x264, Home_Lobby_Greeter_2
# 73 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox Home_Lobby_Greeter_Text_0, MSGBOX_DEFAULT
Home_Lobby_Greeter_1:
# 75 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	release
	end

Home_Lobby_Greeter_2:
# 64 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox lobby_elevator_broke, MSGBOX_DEFAULT
# 65 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 66 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 67 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 68 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 69 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	playse SE_BANG
# 70 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto Home_Lobby_Greeter_1


EntranceAlthea_Text_0:
# 37 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "S-sorry, you weren't supposed to hear\n"
	.string "that...$"

Home_Lobby_Greeter_Text_0:
# 73 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
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
