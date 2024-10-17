NewBaltimoreCity_Pokemon_Center_MapScripts::
	.byte 0


# 3 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"

# 4 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"

# 5 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
NewBaltimore_PokemonCenter_1F_EventScript_Nurse::
# 6 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 7 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 8 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	waitmessage
# 9 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	waitbuttonpress
# 10 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	release
# 11 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	end
