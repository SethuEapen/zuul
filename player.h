#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

class Player{
 public:
  Player(Room*);
  //Getters & Setters
  char* getName();
  Room* getCurrentRoom();
  vector<Item*>* getItems();
  void setCurrentRoom(Room*);
  void addItem(Item*);
  Item* takeItem(char*);
  void printInventory();
  bool validItem(char*);
private:
  char name[50];
  vector<Item*> items;
  Room* currentRoom;
};

#endif
