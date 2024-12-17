#ifndef SAVELOAD_H
#define SAVELOAD_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Player.H"
#include "Monster.H"
#include "Room.H"

void saveGame(const char* filename, int x, int y, Room* map[4][4], Player* player);
void loadGame(const char* filename, int* x, int* y, Room* map[4][4], Player* player);
void listSaves();
bool checkSaves();
#endif