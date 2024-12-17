#ifndef ROOM_H
#define ROOM_H
#include "Monster.H"
#include "Item.H"
#include "Player.H"
typedef enum {
    EMPTY,
    FULL
} Status;
typedef struct{
    Status status;
    Monster* monster1;
    Monster* monster2;
    Monster* monster3;
    int monsterCount;
    int roomId;
    Item* items[3];
}Room;
void generateRoom(Room* room);
void displayRoom(Room* room);
void describeRoom(bool right, bool left, bool forward, bool back);
void setStatus(Room* room);
void checkRoom(Room* room);
void generateItem(Room* room, int i);
void giveItem(Room* room, Player* player, int i);

#endif