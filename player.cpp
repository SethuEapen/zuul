#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

Player::Player(){
}

char* Room::getName(){
  return name;
}

Room* getCurrentRoom(){
  return currentRoom;	
}

vector<Item*>* getItems(){
  return &item;	
}