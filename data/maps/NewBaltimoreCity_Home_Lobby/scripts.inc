NewBaltimoreCity_Home_Lobby_MapScripts::
	.byte 0


Home_Lobby_Greeter::
# 10 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	lock
# 11 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 2
# 12 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 2
# 13 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 14 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 2
# 15 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	delay 100
# 16 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	faceplayer
# 17 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox lobby_elevator_broke, MSGBOX_DEFAULT
# 18 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 19 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 5
# 21 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 22 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox Mandy, MSGBOX_DEFAULT
# 23 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	closemessage
# 24 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	playse SE_BANG
# 25 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	waitmovement 6
# 26 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 27 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	release
	end


lobby_elevator_broke::
# 5 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "Don't bother with the elevator, it's not\n"
	.string "working.$"
