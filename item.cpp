#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* setName){
  name = setName;
}

char* Item::getName(){
  return name;
}
