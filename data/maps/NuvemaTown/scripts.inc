NuvemaTown_MapScripts::
	.byte 0



NuvemaTown_EventScript_WelcomeSign::
	msgbox NuvemaTown_Text_WelcomeSign, MSGBOX_SIGN
	end

NuvemaTown_Text_WelcomeSign:
	.string "Nuvema Town\n"
	.string "“A town where various dots gather.”$"

NuvemaTown_EventScript_BiancaSign::
	msgbox NuvemaTown_Text_BiancaSign, MSGBOX_SIGN
	end
	
NuvemaTown_Text_BiancaSign:
	.string "Bianca's House$"

NuvemaTown_EventScript_CherenSign::
	msgbox NuvemaTown_Text_CherenSign, MSGBOX_SIGN
	end
	
NuvemaTown_Text_CherenSign:
	.string "Cheren's House$"

NuvemaTown_EventScript_HilbertSign::
	msgbox NuvemaTown_Text_HilbertSign, MSGBOX_SIGN
	end
	
NuvemaTown_Text_HilbertSign:
	.string "Hilbert's House$"

NuvemaTown_EventScript_LabSign::
	msgbox NuvemaTown_Text_LabSign, MSGBOX_SIGN
	end
	
NuvemaTown_Text_LabSign:
	.string "Juniper Pokémon Lab$"

NuvemaTown_EventScript_PlayerSign::
	msgbox NuvemaTown_Text_PlayerSign, MSGBOX_SIGN
	end
	
NuvemaTown_Text_PlayerSign:
	.string "{PLAYER}'s House$"

NuvemaTown_EventScript_HilbertDoor::
	msbox NuvemaTown_Text_HilbertDoor, MSBOX_SIGN
	end

NuvemaTown_Text_HilbertDoor:
	.string "The door is locked.$"
