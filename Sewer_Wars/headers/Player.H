#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "Item.H"

typedef struct 
{
    Item* items[10];
    int itemCount;
} Inventory;

typedef struct {      
    int health;
    int strength;   
    Inventory inventory;
    Item* usedItem;
    bool isAlive;      
    Item* usedArmor; 
    int armorHealth;
    int point;
} Player;

void initializePlayer(Player* player);
bool useItem(Player* player, int index);
bool addItem(Player* player, Item* item);
bool removeItem(Player* player, int index);
void displayInventory(Player* player);
int attackP(Player* player);
void takeDamageP(Player* player, int damage);
void heal(Player* player, int healthAmount);
void displayPlayerStatus(Player* player);
void calculatePoint(Player* player);
#endif