#include <stdio.h>
#include <stdlib.h>
#include "../headers/Player.H"
#include "../headers/Item.H"
bool isUsed=false;
void initializePlayer(Player* player) {
    player->health = 200;
    player->strength = 20;
    player->inventory.itemCount = 0;
    player->isAlive = true;
    player->armorHealth=0;
    player->usedItem=NULL;
    player->usedArmor=NULL;
    player->point=0;
    return;
}
bool addItem(Player* player, Item* item) {
    if(player->inventory.itemCount<10){
        player->inventory.items[player->inventory.itemCount]=item;
        player->inventory.itemCount++;
        return true;
    }
    return false;
}
bool useItem(Player* player, int index){
    if(player->inventory.items[index]->type==WEAPON){
        player->usedItem=player->inventory.items[index];
        return 1;
    }
    else if(player->inventory.items[index]->type==FOOD){
        heal(player, player->inventory.items[index]->heal);
        removeItem(player,index);
        return 1;
    }
    else if(player->inventory.items[index]->type==JEWEL){
        printf("You cannot use this jewel\n");
        return 1;
    }
    else if(player->inventory.items[index]->type==TRASH){
        printf("You cannot use this trash\n");
        return 1;
    }
    else if(player->inventory.items[index]->type==ARMOR){ 
        player->usedArmor=player->inventory.items[index];
        player->armorHealth=player->usedArmor->heal;
        return 1;
    }
    return 0;
}
bool removeItem(Player* player, int index) {
    if (player->usedItem == player->inventory.items[index]) {
        player->usedItem = NULL;
    }
    if (player->usedArmor == player->inventory.items[index]) {
        player->usedArmor = NULL;
        isUsed=false;
    }
   
    for (int i = index; i < player->inventory.itemCount - 1; i++) {
        player->inventory.items[i] = player->inventory.items[i+1];
        free(player->inventory.items[i+1]);
    }
    player->inventory.itemCount--;
    return true;
}
void displayInventory(Player* player) {
    printf("_______________________________\n");
    printf("Inventory (%d items):\n", player->inventory.itemCount);
    for (int i = 0; i < player->inventory.itemCount; i++) {
        printf("%d- %s Health:%d Damage:%d  \n",i+1,player->inventory.items[i]->name,player->inventory.items[i]->heal, player->inventory.items[i]->damage);
    }
    return;
}
int attackP(Player* player){
    if(player->usedItem!=NULL){
        return (player->strength + player->usedItem->damage);
    }
    return player->strength;

}
void takeDamageP(Player* player, int damage) {
    if(player->isAlive){
        printf("______________________\n");
        printf("__YOU TOOK %d DAMAGE__\n", damage);
        if((player->health+player->armorHealth)-damage <=0){
            player->health=0;
            player->isAlive=false;
        }
        else{
            player->health-=damage;
        }
    }
}
void heal(Player* player, int healthAmount){
    if(player->isAlive){
        player->health+=healthAmount;
    }
}
int calculateHP(Player* player){
    
    return player->health + player->armorHealth;
}
void displayPlayerStatus(Player* player) {
    printf("_______________________________\n");
    printf("Player Status: %s\n", player->isAlive ? "Alive" : "Dead");
    printf("Health: %d\n", calculateHP(player));
    printf("Strength: %d\n", attackP(player));
    if(player->usedItem!=NULL){
        printf("Used Weapon: %s   Damage:%d \n", player->usedItem->name, player->usedItem->damage);
    }
    if(player->usedArmor!=NULL){
        printf("Used Armor: %s   Health:%d \n", player->usedArmor->name, player->usedArmor->heal);
    }
    calculatePoint(player);
    printf("Your Score: %d\n", player->point);
}
void calculatePoint(Player* player){
    int currentPoint=0;
    for(int i=0;i<player->inventory.itemCount; i++){
        if(player->inventory.items[i]->type==TRASH){
            currentPoint+=10;
        }
    }
    player->point=currentPoint;
    currentPoint=0;
    return;
}
