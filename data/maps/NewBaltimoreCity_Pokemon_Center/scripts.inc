NewBaltimoreCity_Pokemon_Center_MapScripts::
# 2 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewBaltimore_PokemonCenter_OnTransition
# 3 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


NewBaltimore_PokemonCenter_OnTransition::
# 7 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	setrespawn HEAL_LOCATION_NEW_BALTIMORE_CITY
	end


PokeCenter_Employee_Simple::
# 12 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	setvar VAR_0x800B, 1
# 13 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 14 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	waitmessage
# 15 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	waitbuttonpress
# 16 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	release
	end


Pokemart_Employee::
# 21 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	lock
# 22 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	faceplayer
# 23 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	msgbox Pokemart_Employee_Text_0, MSGBOX_YESNO
# 24 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Pokemart_Employee_1
# 33 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	msgbox Pokemart_Employee_Text_2, MSGBOX_NPC
	return

Pokemart_Employee_1:
# 25 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 26 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	special HealPlayerParty
# 27 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	msgbox Pokemart_Employee_Text_1
# 28 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	waitmessage
# 29 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	release
	end


# 49 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"


Pokemart_Employee_Text_0:
# 23 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	.string "Want me to heal your party?$"

Pokemart_Employee_Text_1:
# 27 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	.string "Come again soon.$"

Pokemart_Employee_Text_2:
# 33 "data/maps/NewBaltimoreCity_Pokemon_Center/scripts.pory"
	.string "Okay.$"
