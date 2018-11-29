#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

int main()
{
  vector<Room*> rooms;
  Room* room = new Room();
  strcpy(room->getName(), "Room 1");
  cout << room->getName();
  Room* room2 = new Room();
  strcpy(room2->getName(), "Room 2");
  room->getExits()->insert(pair<const char*, Room*>("East", room2));
  room2->getExits()->insert(pair<const char*, Room*>("East", room));
  delete room;
  delete room2;
}
