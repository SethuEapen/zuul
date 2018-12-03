#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

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

bool Room::isValidRoom(char* room){
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(strcmp(it->first, room) == 0){
      return true;
    }
  }
}

Room* Room::getExitRoom(char* room){
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    if(strcmp(it->first, room) == 0){
      return it->second;
    }
  }
  return 0;//Returns nothing if it does not exist
}

void Room::getExitDirections(){
  map<const char*, Room*>::iterator it;
  for(it = this->exits.begin(); it != this->exits.end(); ++it){
    cout << it->first << ", ";
  }
  cout << endl;
}

void Room::addItem(Item* item){
  items.push_back(item);
}

bool Room::validItem(char* itemName){
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  return true;
    }
  }
  return false;
}

void Room::printItems(){
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    cout << (*it)->getName();
  }
}


Item* Room::takeItem(char* itemName){
  vector<Item*>::iterator it;
  for(it = items.begin(); it != items.end(); ++it){
    if(strcmp((*it)->getName(), itemName) == 0){
	  Item* i = (*it);
	  it:items.erase(it);
	  return (i);
    }
  }
  return NULL;
}
