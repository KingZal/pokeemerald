NewBaltimoreCity_Home_Lobby_MapScripts::
	.byte 0


Home_Lobby_Greeter::
# 8 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	lock
# 9 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	faceplayer
# 10 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	msgbox lobby_elevator_broke, MSGBOX_DEFAULT
# 11 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	release
	end


lobby_elevator_broke::
# 3 "data/maps/NewBaltimoreCity_Home_Lobby/scripts.pory"
	.string "Don't bother with the elevator, it's not\n"
	.string "working.$"
