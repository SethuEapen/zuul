#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

class Parser{
 public:
  bool processCommand(char*, Player*);
};

#endif
