_________________________________________________________________________________
#####  #####  #  #  #   #####   #####      #  #  #   #####   #####   #####
#      #      #  #  #   #       #   #      #  #  #   #   #   #   #   #    
#####  #####  #  #  #   #####   ####       #  #  #   #####   ####    #####
   #   #      #  #  #   #       #   #      #  #  #   #   #   #   #       #
#####  #####  #######   #####   #   #      #######   #   #   #   #   #####
__________________________________________________________________________________

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



**GAME LOGIC**
-In the game, you can interact with the environment by picking up and discarding items, as well as moving between rooms. Some items are usable. You can find trash and jewels around the environment. Trash items affect your final game score, while jewels do not contribute to the score.

**CODE STRUCTURE**

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