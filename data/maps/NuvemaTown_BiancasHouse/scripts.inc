NuvemaTown_BiancasHouse_MapScripts::
	.byte 0

NuvemaTown_BiancasHouse_EventScript_Husband::
	lock
	faceplayer
	msgbox NuvemaTown_BiancasHouse_Text_Husband, MSGBOX_DEFAULT
	release
	end

NuvemaTown_BiancasHouse_Text_Husband:
	.string "Today's the day, {PLAYER}!\n"
	.string "You're finally headed out on your\l"
	.string "adventure.\p"
	.string "Just know that my dear Bianca\n"
	.string "will always be here to help you!$"

NuvemaTown_BiancasHouse_EventScript_Upstairs::
	lock
	msgbox NuvemaTown_BiancasHouse_Text_Upstairs, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, NuvemaTown_BiancasHouse_Movement_South
	release
	end

NuvemaTown_BiancasHouse_Text_Upstairs:
	.string "...\n"
	.string "I shouldn't go up there...$"

NuvemaTown_BiancasHouse_Movement_South:
	walk_down
	step_end
