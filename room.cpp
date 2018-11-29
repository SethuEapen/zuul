#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

Room::Room(){
}

char* Room::getName(){
  return name;
}

char* Room::getDescription(){
  return description;
}

vector<Item*>* Room::getItems(){
  return &items;	
}

map<const char*, Room*>* Room::getExits(){
  return &exits;
}
