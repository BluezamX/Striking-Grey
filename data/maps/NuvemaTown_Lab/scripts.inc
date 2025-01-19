.set LOCALID_AIDE, 1

NuvemaTown_Lab_MapScripts::
	.byte 0

NuvemaTown_Lab_EventScript_Aide1::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_Aide1, MSGBOX_DEFAULT
	turnobject LOCALID_AIDE, DIR_WEST
	release
	end

NuvemaTown_Lab_Text_Aide1:
	.string "A while back, we renovated the entire lab.\n"
	.string "Now we aides can live here as well!\l"
	.string "It saves us a lot of time commuting.$"
