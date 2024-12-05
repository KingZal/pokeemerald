NewBaltimoreCity_ApartmentShipTest_MapScripts::
	.byte 0


sign_player_home::
# 4 "data/maps/NewBaltimoreCity_ApartmentShipTest/scripts.pory"
	lockall
# 5 "data/maps/NewBaltimoreCity_ApartmentShipTest/scripts.pory"
	msgbox label_player_home
# 6 "data/maps/NewBaltimoreCity_ApartmentShipTest/scripts.pory"
	releaseall
	return


label_player_home::
# 9 "data/maps/NewBaltimoreCity_ApartmentShipTest/scripts.pory"
	.string "APT 123\n"
	.string "{PLAYER}$"
