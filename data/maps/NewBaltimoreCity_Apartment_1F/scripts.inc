NewBaltimoreCity_Apartment_1F_MapScripts::
	.byte 0


NewBaltimore_Apartment_Trainer::
# 4 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"
	lock
# 5 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"
	faceplayer
# 6 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"
	setflag FLAG_BUDDY_0x264
# 7 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"
	msgbox NewBaltimore_Apartment_Narrow_Head, MSGBOX_DEFAULT
# 8 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"
	release
	return


# 17 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"


NewBaltimore_Apartment_Narrow_Head::
# 11 "data/maps/NewBaltimoreCity_Apartment_1F/scripts.pory"
	.string "It's like,\n"
	.string "My heads numb,\l"
	.string "Today...$"
