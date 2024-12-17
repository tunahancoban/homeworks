#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "../headers/Player.H"
#include "../headers/Monster.H"
#include "../headers/Room.H"
#include "../headers/Saveload.H"
#include "../headers/Item.H"

bool isRightRoom=false;
bool isLeftRoom=false;
bool isForwardRoom=false;
bool isBackRoom=false;
int x;
int y;
bool didLook = false;
int chc;
int i;
bool exitStatus=true;
bool save=true;

void checkNextRooms(int x, int y, Room* map[4][4]){
    if (x+1<4 && map[x+1][y] != NULL) {
        isBackRoom=true;
    }
    if (x-1>= 0 && map[x-1][y] != NULL) {
        isForwardRoom=true;
    }
    if (y-1>=0 && map[x][y-1] != NULL) {
        isLeftRoom=true;
    }
    if (y+1<4 && map[x][y+1] != NULL) {
        isRightRoom=true;
    }
}
void lookRoom(Room* map[4][4]){
    checkNextRooms(x, y, map);
    describeRoom(isRightRoom, isLeftRoom, isForwardRoom, isBackRoom);
    displayRoom(map[x][y]);
}
void moveRoom(Room* map[4][4]){
    if(map[x][y]->status==EMPTY){
            checkNextRooms(x,y, map);
            if(isRightRoom){
                printf("1-Go right (1)\n");
            }
            if(isLeftRoom){
                printf("2-Go left (2)\n");
            }
            if(isForwardRoom){
                printf("3-Go forward (3)\n");
            }
            if(isBackRoom){
                printf("4-Go back (4)\n");
            }
            scanf("%d", &i);
            switch(i){
                case 1:
                    y++;
                    break;
                case 2:
                    y--;
                    break;
                case 3:
                    x--;
                    break;
                case 4:
                    x++;
                    break;
                default:             
            }
            if(i>=1 && i<=4){
            printf("______________________\n");
            printf("You are in a new room.\n");
            isRightRoom=false;
            isLeftRoom=false;
            isBackRoom=false;
            isForwardRoom=false;
            }
            else{
                printf("You entered an invalid number\n");
            }
            }
            else{
                printf("There are still monsters\n");   
            }
    
}
void openInventory(Player* player){
    displayInventory(player);
    printf("_______________________________________\n");
    printf("1- Use Item | 2- Drop the item | 3-Exit\n");
    scanf("%d", &chc);
        switch (chc)
        {
        case 1:
            printf("Enter the index of item: \n");
            scanf("%d", &i);
            useItem(player, i - 1);
            break;
        case 2:
            printf("Enter the index of item: \n");
            scanf("%d", &i);
            removeItem(player, i - 1);
            break;
        case 3:
            break;
        default:
            break;
        }
}
void pickUpItem(Room* map[4][4], Player* player){
    if (map[x][y]->status == EMPTY)
            {
                if (map[x][y]->items[0]!= NULL) {
                    printf("1- %s\n", map[x][y]->items[0]->name);
                }
                 if (map[x][y]->items[1]!= NULL) {
                    printf("2- %s\n", map[x][y]->items[1]->name);
                }
                if (map[x][y]->items[2] != NULL) {
                    printf("3- %s\n", map[x][y]->items[2]->name);
                }
                printf("________________________________\n");
                printf("Take an item(1-2-3) or exit(4): \n");
                scanf("%d", &i);
                switch(i)
                {
                case 1:
                    if (player->inventory.itemCount >= 10)
                    {
                        printf("Your inventory is full.\n");
                        break;
                    }
                    if (map[x][y]->items[0] == NULL) {
                        printf("There is no item\n");
                        break;
                    }
                    giveItem(map[x][y], player, i-1);
                    break;
                case 2:
                    if (player->inventory.itemCount >= 10)
                    {
                        printf("Your inventory is full.\n");
                        break;
                    }
                    if (map[x][y]->items[1] == NULL) {
                        printf("There is no item\n");
                        break;
                    }
                    giveItem(map[x][y], player, i-1);
                    break;
                case 3:
                    if (player->inventory.itemCount >= 10)
                    {
                        printf("Your inventory is full.\n");
                        break;
                    }
                    if (map[x][y]->items[2] == NULL) {
                        printf("There is no item\n");
                        break;
                    }
                    giveItem(map[x][y], player, i-1);
                    break;
                case 4:
                    break;
                default:
                    break;
                }
            }
            else{
                printf("There are still monsters in the sewer.\n");
            }
}
void startBattle(Room* map[4][4], Player* player){
    if(map[x][y]->status!=EMPTY){
    do{
        printf("\n________________________\n");
        displayMonsterStatus(map[x][y]->monster1,1);
        displayMonsterStatus(map[x][y]->monster2,2);
        displayMonsterStatus(map[x][y]->monster3,3);
        printf("1- ATTACK | 2-INVENTORY | 3-PLAYER STATS \n");
        scanf("%d",&i);
        if(i==1){
            printf("\n____________________________________________\n");
            printf("Choose a monster\n");
            scanf("%d", &i);
            if(i==1 && map[x][y]->monster1->isAlive==true && map[x][y]->monster1!=NULL){
                takeDamageM(map[x][y]->monster1, attackP(player));
                takeDamageP(player,attackM(map[x][y]->monster1)+attackM(map[x][y]->monster2)+attackM(map[x][y]->monster3));
            }      
            else if(i==2 && map[x][y]->monster2->isAlive==true && map[x][y]->monster2!=NULL){
                takeDamageM(map[x][y]->monster2, attackP(player));
                takeDamageP(player,attackM(map[x][y]->monster1)+attackM(map[x][y]->monster2)+attackM(map[x][y]->monster3));
            }    
            else if(i==3 && map[x][y]->monster3->isAlive==true && map[x][y]->monster3!=NULL){
                takeDamageM(map[x][y]->monster3, attackP(player));
                takeDamageP(player,attackM(map[x][y]->monster1)+attackM(map[x][y]->monster2)+attackM(map[x][y]->monster3));
            }    
            else{
                printf("This monster is dead\n");    
            }           
            displayRoom(map[x][y]);
            }
            else if(i==2){
                openInventory(player);
            }
            else if(i==3){
                displayPlayerStatus(player);
            }
    }while(player->isAlive && map[x][y]->status==FULL);
    }
    else{
        printf("There is no monster\n");
    }
}
void startBossFight(Player* player, Monster* monster){
     printf("\n__________BOSS___FIGHT__________\n\n");
    do
    {   
        displayMonsterStatus(monster, i);
       printf("1- ATTACK | 2-INVENTORY | 3-PLAYER STATUS \n");
       scanf("%d",&i);
       if(i==1){
        takeDamageM(monster, attackP(player));
        takeDamageP(player, attackM(monster));
       }else if(i==2){
        openInventory(player);
       }else if(i==3){
        displayPlayerStatus(player);
       }
       else{
        printf("KILL OR KILL, THERE IS NO OTHER OPTION! 1-2\n");
       }
    } while (player->isAlive && monster->isAlive);
    if (!player->isAlive) {
        printf("You died...\n");
    } else if (!monster->isAlive) {
        printf("Boss defeated!\n");
    }
}
void randomEventGenerator(Player* player){
    int no = rand()%100+1;
    if(no>0 && no<6){
        FILE *file = fopen("bossdata.txt", "r"); 
        char name[50]; 
        int health, damage;
        int currentLine=0;
        int i=1;
        while (fscanf(file, "%s %d %d", name, &health, &damage) == 3) {
        currentLine++;
        if (currentLine == i) {
            currentLine=0;
            break;
        }
        }
        Monster* bossRick= (Monster*) malloc(sizeof(Monster));
        initializeMonster(bossRick, name, health, damage);
        fclose(file);
        printf("\n-You saw a pickle in front of you. The pickle slowly turned its head toward you and said, \n  \"All I want is to get out of here, open the way.\"\n You told it that your mission was to kill all the monsters, including a talking pickle.\nThe pickle burped and said, \"Then lets get this over with.\"");
        startBossFight(player, bossRick);  
    }
    else if(no>5 && no <11){
        FILE *file = fopen("bossdata.txt", "r"); 
        char name[50]; 
        int health, damage;
        int currentLine=0;
        int i=1;
        while (fscanf(file, "%s %d %d", name, &health, &damage) == 3) {
        currentLine++;
        if (currentLine == i) {
            currentLine=0;
            break;
        }
        }
        Monster* gollum= (Monster*) malloc(sizeof(Monster));
        initializeMonster(gollum,name, health, damage);
        fclose(file);
        printf("\n-You heard a series of sounds from the shadows around you. Hissing noises like \"My precious\" grew louder as they approached.\n  A stone was thrown at you. In that moment of distraction, a creature leapt onto you, screaming, \"Give me back the ring, give me back the ring.\" \n    Whether the ring was in your possession or not, this creature had to die.");
        startBossFight(player, gollum); 
    }
    else if(no>10 && no<16 ){
        FILE *file = fopen("bossdata.txt", "r"); 
        char name[50]; 
        int health, damage;
        int currentLine=0;
        int i=3;
        while (fscanf(file, "%s %d %d", name, &health, &damage) == 3) {
        currentLine++;
        if (currentLine == i) {
            currentLine=0;
            break;
        }
        }
        Monster* narrator= (Monster*) malloc(sizeof(Monster));
        initializeMonster(narrator,name, health, damage);
        fclose(file);
        printf("\n-As you moved forward, you noticed someone crouched by the wall. A man in a suit was standing there.\n    A schizophrenic episode is the last thing you need right now. Did you really wear that stupid red jacket?\n    Or are you still under the influence of the movie you watched yesterday?\n   You're already walking around with a voice in your head—no need for another schizophrenic symptom. Punch the guy.");
        startBossFight(player, narrator);
    }
}
int main()
{
    srand(time(NULL));
    int choice;
    int game;
    Player player;
    Room *map[4][4];
    int mapLayout[4][4] = {
        {1, 0, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 0, 1, 1}};


    printf("*****************Sewer Wars: A New Stink*****************\n");
    do
    {
        printf("1. New Game\n");
        printf("2. Load Game\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("A new game is starting...\n");
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j<4; j++)
                {
                    if (mapLayout[i][j] == 1)
                    {
                        map[i][j] = (Room *)malloc(sizeof(Room));
                        map[i][j]->roomId = i * 4 + j;
                        generateRoom(map[i][j]);
                    }
                    else
                    {
                        map[i][j] = NULL;
                    }
                }
            }
            game = 1;
            initializePlayer(&player);
            save=false;
            break;
        case 2:
            if(checkSaves()){
                printf("The game is loading...\n");
                printf("Choose a save file (Enter 1-2-3) 4-Exit\n");
                listSaves();
                scanf("%d", &i);
                if(i==1){
                    loadGame("savefile1.txt", &x, &y, map, &player);
                    game = 2;
                    save=false;
                }else if(i==2){
                    loadGame("savefile2.txt", &x, &y, map, &player);
                    game = 2;
                    save=false;
                }else if(i==3){
                    loadGame("savefile3.txt", &x, &y, map, &player);
                    game = 2;
                    save=false;
                }else if(i==4){
                }
                else{
                    printf("Invalid option! Please enter 1 or 2 or 3 \n");
                }
            }
            else{
                printf("There is no save.\n");
                save=true;
            }
            break;
        default:
            printf("Invalid option! Please enter 1 or 2 \n");
            continue;
        }
    } while (save);
    if (game == 1)
    {
        printf("The monsters emerging from the sewers were spreading terror around.\nAlthough the police cleared these monsters from the streets, someone had to destroy the source of these creatures - the sewers.\nAnd you were chosen for this task. You put on your work suit, equipped yourself, and opened the manhole in front of you to descend into the sewer.\n");
        x = 0;
        y = 0;
    }
    do
    {
        printf("____________________________________________\n");
        printf("You are in the room. What do you want to do?\n");
        printf("1- Look | 2- Attack | 3- Move | 4- Inventory | 5- Items | 6- Player Info | 7- Save | 8- Exit | 9- Map\n");
        scanf("%d", &chc);       
        switch (chc)
        {
        case 1:
            lookRoom(map);
            break;
        case 2:
            startBattle(map,&player);
            break;
        case 3:
            if(map[x][y]->status==EMPTY){
                randomEventGenerator(&player);
            }
            moveRoom(map);   
         break;
        case 4:
            openInventory(&player);
            break;
        case 5:
            pickUpItem(map,&player);
            break;
        case 6:
            displayPlayerStatus(&player);
            break;
        case 7:
            printf("You have 3 save slots. Which one would you like to save to?(Enter 1-2-3) \nBe careful, if you save over an old slot, your previous progress might be lost.\n");
            listSaves();
            scanf("%d", &i);
            if(i==1){
                saveGame("savefile1.txt", x, y, map, &player);
            }else if(i==2){
                saveGame("savefile2.txt", x, y, map, &player);
            }else if(i==3){
                saveGame("savefile3.txt", x, y, map, &player);
            }else{
                printf("You entered an invalid value. Please enter a number between 1 and 3.\n");
            }
            break;
        case 8:
            exitStatus=false;
            break;
        case 9:
            for(int k=0;k<4;k++){
                for(int l=0; l<4;l++){
                    if(k==x && l==y){
                        printf("P");
                    }
                    else if(mapLayout[k][l]==1){
                        printf("#");
                    }
                    else{
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("    Forward\n       ^\nLeft<- | ->Right\n       v\n      Back\n");
            break;
        default:
            break;
        }

    } while (player.isAlive && exitStatus);
    if(player.isAlive==false){
        printf("\n-You collapse to the ground in pain. Your death happens in this filthy water.\n    Slowly, your eyes close. I guess I chose the wrong soul for the task.\n    Well, it's time to find another soul to complete the mission.\n");
        printf("\n_____YOU FAILED_______\n");
        calculatePoint(&player);
        printf("Your Score: %d", player.point);
    }else{
        calculatePoint(&player);
        printf("Your Score: %d", player.point);
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j] != NULL)
            {
                free(map[i][j]); 
            }
        }
    }
    return 0;
}
