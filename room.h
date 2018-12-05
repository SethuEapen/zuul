//imports
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;
class Item; //andrew did this and didnt get any errors and it also fixed my issue

class Room{
 public:
  Room();//constructor
  //Getters & Setters
  char* getName();
  char* getDescription();
  vector<Item*>* getItems();
  map<const char*, Room*>* getExits();
  bool isValidRoom(char*);
  Room* getExitRoom(char*);
  void getExitDirections();
  void addItem(Item*);
  bool validItem(char* itemName);
  Item* takeItem(char*);
  void printItems();
 private:
  char name[50];
  char description[1000];
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
