#include <stdio.h>
#include <stdlib.h>
#include "../headers/Item.H"

void initializeWeapon(Item* item, const char* name, int damage){
    item->type=WEAPON;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->damage=damage;
    item->heal=0; 
}
void initializeFood(Item* item, const char* name, int heal){
    item->type=FOOD;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->damage=0;
    item->heal=heal; 
}
void initializeJewel(Item* item, const char* name){
    item->type=JEWEL;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->damage=0;
    item->heal=0; 
}
void initializeTrash(Item* item, const char* name){
    item->type=TRASH;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->damage=0;
    item->heal=0; 
}
void initializeArmor(Item* item, const char* name, int heal){
    item->type=ARMOR;
    strncpy(item->name, name, sizeof(item->name) - 1);
    item->name[sizeof(item->name) - 1] = '\0';
    item->damage=0;
    item->heal=heal; 

}
void displayItem(Item* item) {
    
    printf("Item: %s -- Damage: %d -- Heal: %d \n", item->name, item->damage, item->heal);
    
}