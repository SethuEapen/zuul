#include <iostream>
#include <cstring>
#include "room.h"
#include "player.h"
#include "parser.h"

using namespace std;

int main()
{
  //initialization of variables
  Parser parser;//creating a new parser object to use those fuctions
  vector<Room*> rooms;
  char str[50];
  bool running = true;
  //Room INIT
  Room* room = new Room();
  strcpy(room->getName(), "Room 1");
  strcpy(room->getDescription(), "You are in room 1. This is a useless room go die");
  Room* room2 = new Room();
  strcpy(room2->getName(), "Room 2");
  strcpy(room2->getDescription(), "You are in room 2.");
  //Room Directions
  room->getExits()->insert(pair<const char*, Room*>("east", room2));
  room2->getExits()->insert(pair<const char*, Room*>("west", room));
  Player* p = new Player(room);//creating player
  Item* item = new Item((char*)"New Item");
  room->addItem(item);
  while(running){//main run roop
    cin.get(str, 50);
    cin.clear();
    cin.ignore(10000, '\n');
    if(!parser.processCommand(str, p)){
      running = false;
    }
  }
  delete room;
  delete room2;
  return 0;
}
