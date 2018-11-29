#include <iostream>
#include <cstring>
#include "room.h"
#include "player.h"

using namespace std;

int main()
{
  vector<Room*> rooms;
  Room* room = new Room();
  strcpy(room->getName(), "Room 1");
  cout << room->getName();
  Player* p = new Player(room);
  Room* room2 = new Room();
  strcpy(room2->getName(), "Room 2");
  room->getExits()->insert(pair<const char*, Room*>("east", room2));
  room2->getExits()->insert(pair<const char*, Room*>("west", room));
  delete room;
  delete room2;
}
