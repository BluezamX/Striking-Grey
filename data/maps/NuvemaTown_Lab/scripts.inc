.set LOCALID_AIDE1, 1
.set LOCALID_AIDE2, 2
.set LOCALID_BIANCA, 3
.set LOCALID_SIVO, 4

NuvemaTown_Lab_MapScripts::
	.byte 0

NuvemaTown_Lab_EventScript_BiancaGetStarter::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_Introduction1, MSGBOX_DEFAULT
	turnobject LOCALID_SIVO, DIR_WEST
	msgbox NuvemaTown_Lab_Text_Introduction2, MSGBOX_DEFAULT
	applymovement LOCALID_SIVO, NuvemaTown_Lab_Movement_SivoExcited
	msgbox NuvemaTown_Lab_Text_SivoGreetings, MSGBOX_DEFAULT
	turnobject LOCALID_SIVO, DIR_NORTH
	msgbox NuvemaTown_Lab_Text_Introduction3, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEMON_GET
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NuvemaTown_Lab_Text_Introduction1:
	.string "Prof. Bianca: Ah, {PLAYER}!\n"
	.string "I'm glad you're here.\n"
	.string "As you know, today is the big day.\l"
	.string "You'll finally embark on your\n"
	.string "adventure.\l"
	.string "However, you won't be doing it alone!$"

NuvemaTown_Lab_Text_Introduction2:
	.string "Prof. Bianca: This is Sivo, the son of\n"
	.string "Gym Leader Cheren.\l"
	.string "It came as a surprise to me, but\n"
	.string "Cheren has sent him here to leave on\n"
	.string "his very own journey, just like you.$"

NuvemaTown_Lab_Movement_SivoExcited:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

NuvemaTown_Lab_Text_SivoGreetings:
	.string "Sivo: Nice to meet you, {PLAYER}.\l"
	.string "I grew up with my father's stories\n"
	.string "of how he fought bad guys and traveled\n"
	.string "Unova. I can't wait to forge my own\n"
	.string "destiny!$"
	
NuvemaTown_Lab_Text_Introduction3:
	.string "Prof. Bianca: Very well said, Sivo!\l"
	.string "Your father and I really had a big\n"
	.string "adventure, along with our friend\n"
	.string "Hilbert...\l"
	.string "Now, before I'll let you choose your\n"
	.string "very first Pokémon, I have one more\n"
	.string "thing to say. Never forget that you two\n"
	.string "are on this journey together.\l"
	.string "You need to be there for each other as\n"
	.string "friends and rivals to each get the\n"
	.string "most out of this experience of a lifetime!\l"
	.string "Now, {PLAYER}, who will you pick as your\n"
	.string "very first Pokémon partner?$"

NuvemaTown_Lab_EventScript_BiancaAfterGetStarter::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_BiancaAfterGetStarter, MSGBOX_DEFAULT
	release
	end

NuvemaTown_Lab_Text_BiancaAfterGetStarter:
	.string "Seeing you head out into the world\n"
	.string "brings back so many memories...\l"
	.string "If I can give you one piece of advice:\n"
	.string "It's important to listen to others,\n"
	.string "But you alone can choose your path!$"

NuvemaTown_Lab_EventScript_Sivo::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_Sivo, MSGBOX_DEFAULT
	turnobject LOCALID_SIVO, DIR_NORTH
	release
	end

NuvemaTown_Lab_Text_Sivo:
	.string "???: Prof. Bianca is waiting for you.$"

NuvemaTown_Lab_EventScript_Aide1::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_Aide1, MSGBOX_DEFAULT
	turnobject LOCALID_AIDE1, DIR_WEST
	release
	end

NuvemaTown_Lab_Text_Aide1:
	.string "A while back, we renovated the lab.\n"
	.string "Now we aides can live here as well!\l"
	.string "It saves us a lot of time commuting.$"

NuvemaTown_Lab_EventScript_Aide2::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_Aide2, MSGBOX_DEFAULT
	release
	end

NuvemaTown_Lab_Text_Aide2:
	.string "I heard Professor Bianca's father\n"
	.string "used to be quite tough on her.\l"
	.string "Nowadays their bond is great, however!$"
