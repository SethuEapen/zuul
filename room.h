#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Room{
 public:
  Room();
  //Getters & Setters
  char* getName();
  char* getDescription();
  map<char*, Room*>* getExits();

 private:
  char name[50];
  char description[50];
  //vector<Item*> items;
  map<char*, Room*> exits;
};

#endif
