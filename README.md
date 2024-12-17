

/***
 *         _______. ___________    __    ____  _______ .______         ____    __    ____  ___      .______          _______.
 *        /       ||   ____\   \  /  \  /   / |   ____||   _  \        \   \  /  \  /   / /   \     |   _  \        /       |
 *       |   (----`|  |__   \   \/    \/   /  |  |__   |  |_)  |        \   \/    \/   / /  ^  \    |  |_)  |      |   (----`
 *        \   \    |   __|   \            /   |   __|  |      /          \            / /  /_\  \   |      /        \   \    
 *    .----)   |   |  |____   \    /\    /    |  |____ |  |\  \----.      \    /\    / /  _____  \  |  |\  \----.----)   |   
 *    |_______/    |_______|   \__/  \__/     |_______|| _| `._____|       \__/  \__/ /__/     \__\ | _| `._____|_______/    
 *                                                                                                                           
 */


________________________________________________________________________________________________________________________________________________________________________________________________________________________
**How to Play?**

-When the program starts, you will have the options to start a new game or load a saved game. You can access old saves from the load game option. Once you enter the game, a menu will appear  where you can choose options by entering the corresponding number.

-Whenever you enter a room, you can choose the "look" option to observe the room. This will show you the monsters in the room and the possible paths you can take. If there are monsters in a room, you will not be able to proceed to the next room. After killing the monsters, you can collect items in the room by entering the "Items" section.

-"Food" items restore health but disappear from your inventory.
-"Weapon" items increase your damage and remain in your inventory.
-"Armor" items increase your health and remain in your inventory.

-From the "Inventory" section, you can use and manage your items.

-If you select the "Attack" option, a battle will start, and it will continue until either you or the monsters die. You can also access the inventory here and use items to heal.

-During combat or from the main menu, you can select the "Player Info" option to check your health, damage, and other stats.

-You can also check which room you're in by selecting the "Map" option.

-The "Move" option allows you to check the available paths and proceed to the next room. Be careful, as when moving to the next room, a random event may occur, and you could find yourself in the middle of a boss fight.

-The "Save" option allows you to save your progress. It cannot be used during combat. It will also save any items you haven't collected from the rooms you have cleared.

________________________________________________________________________________________________________________________________________________________________________________________________________________________
**GAME LOGIC**
-In the game, you can interact with the environment by picking up and discarding items, as well as moving between rooms. Some items are usable. You can find trash and jewels around the environment. Trash items affect your final game score, while jewels do not contribute to the score.
________________________________________________________________________________________________________________________________________________________________________________________________________________________
**CODE STRUCTURE**

-game.exe: The compiled executable file of the game. This is the file you run to start the game.

-Makefile: This file contains the instructions for building the project. It compiles the various C source files into the executable.


   _C Source Files_
-main.c: The main entry point of the game. This file initializes the game and contains the main game loop, which drives the gameplay.

-Item.c: Contains code related to items in the game. This could include item creation, inventory management, and interaction with the player.

-Monster.c: Defines the behavior of monsters within the game. This file likely includes functions for monster creation, movement, and interactions with the player or environment.

-Player.c: Handles player-related functionalities, such as player stats, movement, and interaction with other game elements (e.g., items, monsters).

-Room.c: Manages the different rooms or areas in the game. This could include the layout, room transitions, and environmental effects.

-SaveLoad.c: This file likely handles saving and loading game progress, allowing players to resume their game later.

   _Text Files_
bossdata.txt: A text document that may contain information related to the game’s boss, such as stats, abilities, or other related data.

itemdata.txt: This file likely stores data related to items in the game, such as item names, descriptions, and properties.

monsterdata.txt: Similar to the other text files, this document likely contains data about monsters, such as their stats, names, or behavior.

   _Header Files_
-Item.H: This header file likely contains the declarations for functions and data structures related to items in the game, such as item attributes, creation, and interactions with the player.

-Monster.H: The header file for the monster-related code, likely defining the monster structure, its properties (e.g., health, attack), and functions for managing monster behavior and interactions.

-Player.H: This header contains the declarations for player-related functions and variables, such as player stats (health, score), movement, and interactions with other game elements like items and monsters.

-Room.H: This header defines the functions and data structures for handling rooms in the game, including room layout, transitions, and interactions with objects within the room.

-SaveLoad.H: The header file related to saving and loading game progress. It likely contains function declarations for saving and loading game state, such as player data, room data, and inventory.


________________________________________________________________________________________________________________________________________________________________________________________________________________________
**FILE STRUCTURE**
/C_HW
│
├── src/                
│   ├── main.c          
│   ├── Item.        
│   ├── Player.c      
│   ├── Room.c
│   ├── Saveload.c
│   ├── Monster.c
|   └── Makefile.md
├──saves/
|   |...
│   
|
├── headers/                     
│   ├── Item.H        
│   ├── Player.H      
│   ├── Room.H
│   ├── Saveload.H
│   └── Monster.H
│         
└── README.md
