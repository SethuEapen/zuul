#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(Room* startRoom){
  currentRoom = startRoom;
}

char* Player::getName(){
  return name;
}

Room* Player::getCurrentRoom(){
  return currentRoom;	
}

vector<Item*>* Player::getItems(){
  return &items;	
}