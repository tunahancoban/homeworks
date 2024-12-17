#include "../headers/Room.h"
#include "../headers/Monster.H"
#include "../headers/Player.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateRoom(Room* room){
    FILE *file = fopen("monsterdata.txt", "r");
    if (file == NULL) {
        printf("The file could not be opened.!\n");
        return;
    }
    char name[50]; 
    int health, damage;
    fscanf(file, "%s %d %d", name, &health, &damage);
    room->monster1 = (Monster*) malloc(sizeof(Monster));
    initializeMonster(room->monster1, name, health, damage);

    fscanf(file, "%s %d %d", name, &health, &damage);
    room->monster2 = (Monster*) malloc(sizeof(Monster));
    initializeMonster(room->monster2, name, health, damage);

    fscanf(file, "%s %d %d", name, &health, &damage);
    room->monster3 = (Monster*) malloc(sizeof(Monster));
    initializeMonster(room->monster3, name, health, damage);

    for(int i=0;i<3;i++){
        room->items[i]=(Item*) malloc(sizeof(Item));
        generateItem(room,i);
    }
    room->status=FULL;
    fclose(file);
}
void displayRoom(Room* room){
    checkRoom(room);
    if(room->status==EMPTY){
        printf("\nThis room is empty! \n");
    }
    else{
        displayMonsterStatus(room->monster1, 1);
        displayMonsterStatus(room->monster2, 2);
        displayMonsterStatus(room->monster3, 3);
    }
}
void setStatus(Room* room){
    room->status=EMPTY;
}
void checkRoom(Room* room){
    if(room->monster1->isAlive == false && room->monster2->isAlive == false && room->monster3->isAlive == false ){
        setStatus(room);
    }
}
void describeRoom(bool right, bool left, bool forward, bool back){
    if (right){
        printf("-You see an opening on the right side, you can crawl through it.\n");
    }
    else{
        printf("-When you turn to your right, you notice the path is blocked by stones.\n");
    }
    if (left){
        printf("-The bars on the left side are broken, you can pass through the gap between them.\n");
    }
    else{
        printf("-When you turn to your left, you notice a disgusting smell coming from there. You wouldnt want to go that way.\n");
    }
    if (forward){
        printf("-You see the passage ahead, you can cross by wading through the sewage up to your waist.\n");
    }
    else{
        printf("-The entrance ahead is closed with a metal door. There could be much worse things inside, so you decide not to look.\n");
    }
    if (back){
        printf("-When you turn to the back, there is a hole. Be careful when crossing, you wouldn't want those sharp metal parts to cut you.\n");
    }
    else{
        printf("-You hear cursed sounds coming from the room behind you.\nYou're not a wizard, you're here only to kill monsters. Focus on your task.\n");
    }

}
void generateItem(Room* room, int i) { 
    FILE *file = fopen("itemdata.txt", "r");
    if (file == NULL) {
        printf("The file could not be opened.!\n");
        return;
    }
    int number = rand()%11+1;
    int itemNo;
    char name[30];
    int value;
    char type[20];
    int currentLine=0;

    while (fscanf(file, "%d %s %d %s", &itemNo, name, &value, type) == 4) {
        currentLine++;
        if (currentLine == number) {
            currentLine=0;
            break;
        }
    }
    
    if (strcmp(type, "FOOD") == 0) {
        Item* item1 = (Item*) malloc(sizeof(Item));
        initializeFood(item1, name, value);
        room->items[i]=item1;
    } else if (strcmp(type, "WEAPON") == 0){
        Item* item2 = (Item*) malloc(sizeof(Item));
        initializeWeapon(item2, name, value);
        room->items[i]=item2;
    } else if (strcmp(type, "JEWEL") == 0){
        Item* item3 = (Item*) malloc(sizeof(Item));
        initializeJewel(item3, name);
        room->items[i]=item3;
    } else if (strcmp(type, "TRASH") == 0){
        Item* item4 = (Item*) malloc(sizeof(Item));
        initializeTrash(item4, name);
        room->items[i]=item4;
    } else if (strcmp(type, "ARMOR") == 0){
        Item* item5 = (Item*) malloc(sizeof(Item));
        initializeArmor(item5, name, value);
        room->items[i]=item5;
    }
    fclose(file);
}
void giveItem(Room* room, Player* player, int i){
    if(room->items[i]!=NULL){
        addItem(player, room->items[i]);
        room->items[i]=NULL;
    }
}