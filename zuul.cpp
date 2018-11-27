#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

int main()
{
  vector<Room*> rooms;
  Room* room = new Room();
  cin >> room->getName();
  cout << room->getName();
  delete room;
}
