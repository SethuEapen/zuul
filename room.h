#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class Room{
 public:
  Room();
  //Getters & Setters
  char* getName();
  char* getDescription();
  vector<Item*>* getItems();
  map<const char*, Room*>* getExits();

 private:
  char name[50] = "Default Name";
  char description[50] = "Default Description";
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
