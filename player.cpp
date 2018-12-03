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

void Player::setCurrentRoom(Room* newRoom){
  currentRoom = newRoom;
}

void Player::addItem(Item* item){
  items.push_back(item);
}

Item* Player::takeItem(char* itemName){
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
      Item* i = (*it);
	  it = items.erase(it);
	  return (i);
    }
  }
  return 0;
}

void Player::printInventory(){
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    cout << (*it)->getName();
  }
  cout << endl;
}
