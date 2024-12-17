#include "../headers/Monster.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void initializeMonster(Monster* monster,const char* name, int health, int strength) {
    strncpy(monster->name, name, sizeof(monster->name) - 1);
    monster->name[sizeof(monster->name) - 1] = '\0';  
    monster->health = health;
    monster->strength = strength;
    monster->isAlive = true;
}
int attackM(Monster* monster) {
    if (monster->isAlive) {
        return monster->strength;  
    }
    return 0;
}
void takeDamageM(Monster* monster, int damage) {
    if (monster->isAlive) {
        printf("________________________\n");
        printf("___YOU DEALT %d DAMAGE__\n", damage);
        monster->health -= damage;
        if (monster->health <= 0) {
            monster->health = 0;
            monster->isAlive = false; 
            //Random death message
            int no = rand()%3+1;
            if(no==1){
                printf("\n-You see an item among the dead creature's filthy body. It could be something useful.\n");
            }
            else if(no==2){
                printf("\n-The monster staggered and collapsed to the ground. You watched as its body slowly disappeared in the sewage.\n    At that moment, you noticed something floating on the sewage.\n");
            }
            else{
                printf("\n-Before the creature died, it opened its palm toward you, and you noticed it was holding an item.\n    When you looked into the creature's eyes before it passed, you understood how great its pain was. \n    Or are you empathizing with them? Remember, your only task is to clear the sewers of these filthy monsters.\n");
            }
            free(monster);
        }
    }
    else{
        free(monster);
    }
}
void displayMonsterStatus(Monster* monster,int i) {
    printf("_______________________________\n");
    printf("%d- Monster: %s\n", i,monster->name);
    printf("   Health: %d\n", monster->health);
    printf("   Strength: %d\n", monster->strength);
    if (monster->isAlive) {
        printf("   Status: Alive\n");
    } else {
        printf("   Status: Dead\n");
    }
}