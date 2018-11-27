#include <iostream>
#include <cstring>
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

map<char*, Room*>* Room::getExits(){
  return &exits;
}
