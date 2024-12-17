#ifndef ITEM_H
#define ITEM_H
#include <string.h>

typedef enum {
    WEAPON,
    FOOD,
    JEWEL,
    TRASH,
    ARMOR
} ItemType;

typedef struct {
    ItemType type;
    char name[30];
    int heal;
    int damage;
} Item;

void initializeWeapon(Item* item, const char* name, int damage);
void initializeFood(Item* item, const char* name, int heal);
void initializeJewel(Item* item, const char* name);
void initializeTrash(Item* item, const char* name);
void initializeArmor(Item* item, const char* name, int heal);
void displayItem(Item* item);
#endif