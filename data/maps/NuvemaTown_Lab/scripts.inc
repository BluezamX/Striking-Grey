.set LOCALID_AIDE1, 1
.set LOCALID_AIDE2, 2
.set LOCALID_BIANCA, 3
.set LOCALID_SIVO, 4

NuvemaTown_Lab_MapScripts::
	.byte 0

NuvemaTown_Lab_EventScript_Bianca::
	lock
	faceplayer
	goto_if_unset FLAG_NUVEMATOWN_LAB_INTRODUCTION NuvemaTown_Lab_EventScript_BiancaGetStarter
	goto_if_set FLAG_NUVEMATOWN_LAB_INTRODUCTION NuvemaTown_Lab_EventScript_BiancaAfterGetStarter
	end

NuvemaTown_Lab_EventScript_BiancaGetStarter::
	msgbox NuvemaTown_Lab_Text_Introduction1, MSGBOX_DEFAULT
	turnobject LOCALID_SIVO, DIR_WEST
	msgbox NuvemaTown_Lab_Text_Introduction2, MSGBOX_DEFAULT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_SIVO, NuvemaTown_Lab_Movement_SivoExcitedWest
	waitmovement 0
	msgbox NuvemaTown_Lab_Text_SivoGreetings, MSGBOX_DEFAULT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_SIVO, DIR_NORTH
	msgbox NuvemaTown_Lab_Text_Introduction3, MSGBOX_DEFAULT
	applymovement LOCALID_BIANCA, NuvemaTown_Lab_Movement_BiancaExcitedSouth
	waitmovement 0
	msgbox NuvemaTown_Lab_Text_Introduction4, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEMON_GET
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	msgbox NuvemaTown_Lab_Text_Introduction5, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, NuvemaTown_Lab_EventScript_SivoSnivy
	case 1, NuvemaTown_Lab_EventScript_SivoTepig
	case 2, NuvemaTown_Lab_EventScript_SivoOshawott
	end

NuvemaTown_Lab_Text_Introduction1:
	.string "Prof. Bianca: Ah, {PLAYER}!\n"
	.string "I'm glad you're here.\p"
	.string "As you know, today is the big day.\p"
	.string "You'll finally embark on your\n"
	.string "adventure.\p"
	.string "However, you won't be doing it alone!$"

NuvemaTown_Lab_Text_Introduction2:
	.string "Prof. Bianca: This is Sivo, the son of\n"
	.string "Gym Leader Cheren. He arrived this\l"
	.string "morning.\p"
	.string "It came as a bit of a surprise to me,\n"
	.string "but Cheren has sent him here.\p"
	.string "He thought it would be fitting for his\n"
	.string "son to start his journey in Nuvema Town.$"

NuvemaTown_Lab_Movement_SivoExcitedWest:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

NuvemaTown_Lab_Text_SivoGreetings:
	.string "Sivo: Nice to meet you, {PLAYER}.\p"
	.string "I grew up with my father's stories of\n"
	.string "how he fought bad guys across Unova.\l"
	.string "I can't wait to forge my own destiny!$"
	
NuvemaTown_Lab_Text_Introduction3:
	.string "Prof. Bianca: Very well said, Sivo!\p"
	.string "Your father and I had a big adventure\n"
	.string "along with our friend Hilbert...\p"
	.string "Even though it's been 20 years,\n"
	.string "it doesn't feel like that long ago!$"

NuvemaTown_Lab_Movement_BiancaExcitedSouth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

NuvemaTown_Lab_Text_Introduction4:
	.string "Prof. Bianca: I have one more thing to\n"
	.string "say before you get to pick your very\l"
	.string "first Pokémon.\p"
	.string "Never forget that you two are on\n"
	.string "this journey together.\p"
	.string "You need to be there for each other as\n"
	.string "both friends and rivals.\p"
	.string "That way, you'll get the most out of\n"
	.string "this experience of a lifetime!\p"
	.string "Now, {PLAYER}, who will you pick as your\n"
	.string "very first Pokémon partner?$"
	
NuvemaTown_Lab_Text_Introduction5:
	.string "Prof. Bianca: If you want, you can\n"
	.string "give your Pokémon a nickname in the\l"
	.string "Summary screen.$"

NuvemaTown_Lab_EventScript_SivoSnivy::
	msgbox NuvemaTown_Lab_Text_SivoSnivy, MSGBOX_DEFAULT
	call NuvemaTown_Lab_EventScript_BeforeBattle
	end

NuvemaTown_Lab_Text_SivoSnivy:
	.string "Sivo: I'll take Tepig!$"

NuvemaTown_Lab_EventScript_SivoTepig::
	msgbox NuvemaTown_Lab_Text_SivoTepig, MSGBOX_DEFAULT
	call NuvemaTown_Lab_EventScript_BeforeBattle
	end

NuvemaTown_Lab_Text_SivoTepig:
	.string "Sivo: I'll take Oshawott!$"

NuvemaTown_Lab_EventScript_SivoOshawott::
	msgbox NuvemaTown_Lab_Text_SivoOshawott, MSGBOX_DEFAULT
	call NuvemaTown_Lab_EventScript_BeforeBattle
	end
	
NuvemaTown_Lab_Text_SivoOshawott:
	.string "Sivo: I'll take Snivy!$"

NuvemaTown_Lab_EventScript_BeforeBattle::
	applymovement LOCALID_SIVO, NuvemaTown_Lab_Movement_SivoExcitedNorth
	waitmovement 0
	turnobject LOCALID_SIVO, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox NuvemaTown_Lab_Text_Introduction6, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, NuvemaTown_Lab_EventScript_StartSivoBattleSnivy
	case 1, NuvemaTown_Lab_EventScript_StartSivoBattleTepig
	case 2, NuvemaTown_Lab_EventScript_StartSivoBattleOshawott
	release
	end

NuvemaTown_Lab_Movement_SivoExcitedNorth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

NuvemaTown_Lab_Text_Introduction6:
	.string "Sivo: Now, let's have our very first\n"
	.string "Pokémon battle, {PLAYER}!\l"
	.string "Prof. Bianca: No, not inside-$"

NuvemaTown_Lab_EventScript_StartSivoBattleSnivy::
	trainerbattle_no_intro TRAINER_SIVO_NUVEMATOWN_LAB_SNIVY, NuvemaTown_Lab_SivoDefeated
	goto NuvemaTown_Lab_EventScript_AfterRivalBattle
	end

NuvemaTown_Lab_EventScript_StartSivoBattleTepig::
	trainerbattle_no_intro TRAINER_SIVO_NUVEMATOWN_LAB_TEPIG, NuvemaTown_Lab_SivoDefeated
	goto NuvemaTown_Lab_EventScript_AfterRivalBattle
	end

NuvemaTown_Lab_EventScript_StartSivoBattleOshawott::
	trainerbattle_no_intro TRAINER_SIVO_NUVEMATOWN_LAB_OSHAWOTT, NuvemaTown_Lab_SivoDefeated
	goto NuvemaTown_Lab_EventScript_AfterRivalBattle
	end

NuvemaTown_Lab_SivoDefeated:
	.string "Wow! That was amazing!\n"
	.string "{PLAYER}, you're a really good trainer!$"

NuvemaTown_Lab_EventScript_AfterRivalBattle::
	msgbox NuvemaTown_Lab_Text_Introduction7, MSGBOX_DEFAULT
	turnobject LOCALID_SIVO, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_SIVO, NuvemaTown_Lab_Movement_SivoExcitedNorth
	waitmovement 0
	msgbox NuvemaTown_Lab_Text_GivePokedex, MSGBOX_DEFAULT
	call NuvemaTown_Lab_EventScript_ReceivePokedex
	applymovement LOCALID_SIVO, NuvemaTown_Lab_Movement_SivoExcitedNorth
	msgbox NuvemaTown_Lab_Text_Introduction8, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_SIVO, NuvemaTown_Lab_Movement_SivoLeaves
	waitmovement 0
	removeobject LOCALID_SIVO
	setflag FLAG_NUVEMATOWN_LAB_INTRODUCTION
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox NuvemaTown_Lab_Text_Introduction9, MSGBOX_DEFAULT
	release
	end

NuvemaTown_Lab_Text_Introduction7:
	.string "Prof. Bianca: -the lab...\l"
	.string "Sivo: Next time, I'll beat you\n"
	.string "for sure, {PLAYER}!\p"
	.string "Prof. Bianca: Next time, don't have\n"
	.string "Pokémon battles indoors! They can\l"
	.string "get very messy.$"

NuvemaTown_Lab_Text_GivePokedex:
	.string "Sivo: Sorry, professor!\l"
	.string "Prof. Bianca: That's alright. You're\n"
	.string "both great trainers already!\p"
	.string "Before you go, I have one more thing\n"
	.string "for you. It's a Pokédex, a device that\l"
	.string "records info on all Pokémon you see!\p"
	.string "It can tell you lots of stuff about\n"
	.string "Pokémon from the moment you see them.\p"
	.string "To really get in-depth info, you'll\n"
	.string "have to catch them, however.\p"
	.string "Some trainers even make it their\n"
	.string "mission to catch all of the Pokémon in\l"
	.string "the Pokédex!$"

NuvemaTown_Lab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message NuvemaTown_Lab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	playfanfare MUS_OBTAIN_ITEM
	message NuvemaTown_Lab_Text_ReceivedPokeballs
	giveitem ITEM_POKE_BALL, 5
	waitfanfare
	waitmessage
	closemessage
	applymovement LOCALID_BIANCA, NuvemaTown_Lab_Movement_BiancaWalkToSivo
	waitmovement 0
	turnobject LOCALID_BIANCA, DIR_SOUTH
	return

NuvemaTown_Lab_Movement_BiancaWalkToSivo:
	walk_right
	step_end

NuvemaTown_Lab_Text_ReceivedPokedex:
	.string "{PLAYER} received the Pokédex!$"

NuvemaTown_Lab_Text_ReceivedPokeballs:
	.string "{PLAYER} received 5 Pokéballs!$"

NuvemaTown_Lab_Text_Introduction8:
	.string "Sivo: Thank you very much, professor\n"
	.string "Bianca!\p"
	.string "I have to go train and become strong\n"
	.string "enough to earn my first Gym Badge!$"
	
NuvemaTown_Lab_Movement_SivoLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NuvemaTown_Lab_Text_Introduction9:
	.string "Prof. Bianca: Headstrong and fierce,\n"
	.string "just like his father...\p"
	.string "{PLAYER}! I recommend you head over to\n"
	.string "Striaton City.\p"
	.string "There, you'll be able to earn\n"
	.string "your very first Gym Badge!$"

NuvemaTown_Lab_EventScript_BiancaAfterGetStarter::
	lock
	faceplayer
	msgbox NuvemaTown_Lab_Text_BiancaAfterGetStarter, MSGBOX_DEFAULT
	release
	end

NuvemaTown_Lab_Text_BiancaAfterGetStarter:
	.string "Seeing you head out into the world\n"
	.string "brings back so many memories...\p"
	.string "If I can give you one piece of advice:\n"
	.string "It's important to listen to others,\l"
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
	.string "I heard professor Bianca's father\n"
	.string "used to be quite tough on her.\l"
	.string "Nowadays their bond is great, however!$"
