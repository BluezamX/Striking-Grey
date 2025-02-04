NuvemaTown_CherensHouse_MapScripts::
	.byte 0

NuvemaTown_CherensHouse_EventScript_Father::
	lock
	faceplayer
	msgbox NuvemaTown_CherensHouse_Text_Father, MSGBOX_DEFAULT
	release
	end

NuvemaTown_CherensHouse_Text_Father:
	.string "I can't believe you and your mother\n"
	.string "have only lived here for 5 years.\p"
	.string "It feels like I've known you both for\n"
	.string "decades already...$"

NuvemaTown_CherensHouse_EventScript_Mother::
	lock
	faceplayer
	goto_if_unset FLAG_NUVEMATOWN_LAB_INTRODUCTION NuvemaTown_CherensHouse_EventScript_Mother1
	goto_if_set FLAG_NUVEMATOWN_LAB_INTRODUCTION NuvemaTown_CherensHouse_EventScript_Mother2
	end

NuvemaTown_CherensHouse_EventScript_Mother1::
	msgbox NuvemaTown_CherensHouse_Text_Mother1, MSGBOX_DEFAULT
	release
	end

NuvemaTown_CherensHouse_Text_Mother1:
	.string "My grandson just arrived!\n"
	.string "However, he only dropped by for tea,\l"
	.string "and now he's waiting in the Lab.\p"
	.string "Oh? You hadn't heard that Sivo is\n"
	.string "leaving today as well?$"

NuvemaTown_CherensHouse_EventScript_Mother2::
	goto_if_unset FLAG_CHEREN_MOM NuvemaTown_CherensHouse_EventScript_Mother3
	goto_if_set FLAG_CHEREN_MOM NuvemaTown_CherensHouse_EventScript_Mother4
	end

NuvemaTown_CherensHouse_EventScript_Mother3::
	msgbox NuvemaTown_CherensHouse_Text_Mother3, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL, 1
	setflag FLAG_CHEREN_MOM
	release
	end

NuvemaTown_CherensHouse_Text_Mother3:
	.string "Sivo just dropped by.\n"
	.string "I gave him a Great Ball for good luck.\l"
	.string "Do you want one as well?$"

NuvemaTown_CherensHouse_EventScript_Mother4::
	msgbox NuvemaTown_CherensHouse_Text_Mother4, MSGBOX_DEFAULT
	release
	end

NuvemaTown_CherensHouse_Text_Mother4:
	.string "You remind me of my dear Cheren...\n"
	.string "You're just as headstrong.$"

NuvemaTown_CherensHouse_EventScript_Upstairs::
	lock
	msgbox NuvemaTown_CherensHouse_Text_Upstairs, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, NuvemaTown_CherensHouse_Movement_South
	release
	end

NuvemaTown_CherensHouse_Text_Upstairs:
	.string "...\n"
	.string "I shouldn't go up there...$"

NuvemaTown_CherensHouse_Movement_South:
	walk_down
	step_end
