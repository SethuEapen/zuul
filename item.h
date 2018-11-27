#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

class Item{
public:
  Item();
  //Getters & Setters
  char* getName();
  Room* getRoom();
private:
  char name[50];
  Room* currentRoom;
  
};

#endif
