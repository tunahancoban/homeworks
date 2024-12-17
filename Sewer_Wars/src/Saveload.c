#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include "../headers/Saveload.H"

void saveGame(const char* filename, int x, int y, Room* map[4][4], Player* player) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "../saves/%s", filename); 

    FILE* file = fopen(filepath, "wb"); 
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    // Save player data
    fwrite(player, sizeof(Player), 1, file);
    
    for (int i = 0; i < player->inventory.itemCount; i++) {
        if (player->inventory.items[i] != NULL) {
            int itemExists = 1;
            fwrite(&itemExists, sizeof(int), 1, file);
            fwrite(player->inventory.items[i], sizeof(Item), 1, file);
        } else {
            int itemExists = 0;
            fwrite(&itemExists, sizeof(int), 1, file);
        }
    }
    if (player->usedArmor != NULL) {
        int usedArmorExists = 1;
        fwrite(&usedArmorExists, sizeof(int), 1, file);
        fwrite(player->usedArmor, sizeof(Item), 1, file);
    } 
    else {
        int usedArmorExists = 0;
        fwrite(&usedArmorExists, sizeof(int), 1, file);
    }
    
    if (player->usedItem != NULL) {
        int usedItemExists = 1;
        fwrite(&usedItemExists, sizeof(int), 1, file);
        fwrite(player->usedItem, sizeof(Item), 1, file);
    } 
    else {
        int usedItemExists = 0;
        fwrite(&usedItemExists, sizeof(int), 1, file);
    } 
    
    // Save x and y positions
    fwrite(&x, sizeof(int), 1, file);
    fwrite(&y, sizeof(int), 1, file);

    // Save map data
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (map[i][j] != NULL) {
                int exists = 1;
                fwrite(&exists, sizeof(int), 1, file);
                fwrite(map[i][j], sizeof(Room), 1, file);

                
                for (int l = 0; l < 3; l++){
                    if (map[i][j]->items[l] != NULL){
                        int itemExistsRoom = 1;
                        fwrite(&itemExistsRoom, sizeof(int), 1, file);
                        fwrite(map[i][j]->items[l], sizeof(Item), 1, file);
                    }
                    else{
                        int itemExists = 0;
                        fwrite(&itemExists, sizeof(int), 1, file);
                    }
                }
                 // Save monsters in the room
                for (int k = 0; k < 3; k++) {
                    Monster* monster = (k == 0) ? map[i][j]->monster1 : (k == 1) ? map[i][j]->monster2 : map[i][j]->monster3;
                    if (monster != NULL) {
                        int monsterExists = 1;
                        fwrite(&monsterExists, sizeof(int), 1, file);
                        fwrite(monster, sizeof(Monster), 1, file);                     
                    } else {
                        int monsterExists = 0;
                        fwrite(&monsterExists, sizeof(int), 1, file);
                    }
                }
            } else {
                int exists = 0;
                fwrite(&exists, sizeof(int), 1, file);
            }
        }
    }
    fclose(file);
    printf("Game saved successfully!\n");
}
void loadGame(const char* filename, int* x, int* y, Room* map[4][4], Player* player) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "../saves/%s", filename); 
    FILE* file = fopen(filepath, "rb"); 
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }

    // Load player data
    fread(player, sizeof(Player), 1, file);
    

    // Load items in player's inventory
    for (int i = 0; i < player->inventory.itemCount; i++) {
        int itemExists;
        fread(&itemExists, sizeof(int), 1, file);
        if (itemExists) {
            player->inventory.items[i] = (Item*)malloc(sizeof(Item));
            fread(player->inventory.items[i], sizeof(Item), 1, file);
        } else {
            player->inventory.items[i] = NULL;
        }
    }
    int usedArmorExists;
    fread(&usedArmorExists, sizeof(int), 1, file);
    if (usedArmorExists) {
        player->usedArmor = (Item*)malloc(sizeof(Item));
        fread(player->usedArmor, sizeof(Item), 1, file);
    } else {
        player->usedArmor = NULL;
    }

    int usedItemExists;
    fread(&usedItemExists, sizeof(int), 1, file);
    if (usedItemExists) {
        player->usedItem = (Item*)malloc(sizeof(Item));
        fread(player->usedItem, sizeof(Item), 1, file);
    } else {
        player->usedItem = NULL;
    }

    // Load x and y positions
    fread(x, sizeof(int), 1, file);
    fread(y, sizeof(int), 1, file);

    // Load map data
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int exists;
            fread(&exists, sizeof(int), 1, file);
            if (exists) {
                map[i][j] = (Room*)malloc(sizeof(Room));
                fread(map[i][j], sizeof(Room), 1, file);

                for(int l=0; l<3; l++){
                    int itemExistsRoom;
                    fread(&itemExistsRoom, sizeof(int), 1, file);
                    if (itemExistsRoom) {
                            map[i][j]->items[l]= (Item*)malloc(sizeof(Item));
                            fread(map[i][j]->items[l], sizeof(Item), 1, file);
                    }else {
                           map[i][j]->items[l]= NULL;
                    }
                }
                // Load monsters in the room
                for (int k = 0; k < 3; k++) {
                    int monsterExists;
                    fread(&monsterExists, sizeof(int), 1, file);
                    if (monsterExists) {
                        Monster* monster = (Monster*)malloc(sizeof(Monster));
                        fread(monster, sizeof(Monster), 1, file);
                        if (k == 0) map[i][j]->monster1 = monster;
                        if (k == 1) map[i][j]->monster2 = monster;
                        if (k == 2) map[i][j]->monster3 = monster;
                    } else {
                        if (k == 0) map[i][j]->monster1 = NULL;
                        if (k == 1) map[i][j]->monster2 = NULL;
                        if (k == 2) map[i][j]->monster3 = NULL;
                    }
                }
            } else {
                map[i][j] = NULL;
            }
        }
    }

    fclose(file);
    printf("Game loaded successfully!\n");
}
void listSaves() {
    DIR *dir;
    int i=1;
    struct dirent *entry;
    dir = opendir("../saves");
    if (dir == NULL) {
        perror("Couldn't be opened.\n");
        return;
    }
    printf("Save files:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") != NULL) {
            printf("%d) %s\n",i,entry->d_name);
            i++;
        }
    }
    closedir(dir);
}
bool checkSaves(){
    DIR *dir;
    struct dirent *entry;
    dir = opendir("../saves");
    if (dir == NULL) {
        perror("Couldn't be opened.\n");
        closedir(dir);
        return false;
    }
    printf("Save files:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") != NULL) {
            closedir(dir);
            return true;
        }
    }
    closedir(dir);
    return false;
}