LittlerootTown_Brendans_Secret_MapScripts::
	.byte 0


LittlerootTown_Brendan_SecretRoomEntrance::
# 4 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
	lockall
# 6 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
	msgbox LittlerootTown_Brendan_SecretRoomEntrance_Text_0
# 7 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Move_Me
# 8 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
	releaseall
	return


# 11 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"

# 12 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
Move_Me:
# 13 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
    walk_down
# 14 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
    step_end

LittlerootTown_Brendan_SecretRoomEntrance_Text_0:
# 6 "data/maps/LittlerootTown_Brendans_Secret/scripts.pory"
	.string "You are not ready yet.$"
