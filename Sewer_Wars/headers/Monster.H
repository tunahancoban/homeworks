#ifndef MONSTER_H
#define MONSTER_H
#include <stdbool.h>
#include "Item.H"

typedef struct {      
    char name[20];
    int health;
    int strength;   
    bool isAlive;          
} Monster;
void initializeMonster(Monster* monster,const char* name, int health, int strength);
int attackM(Monster* monster);
void takeDamageM(Monster* monster, int damage);
void displayMonsterStatus(Monster* monster, int i);

#endif