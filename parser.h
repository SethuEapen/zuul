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
  boolean prosessCommand(char* str);
 private:
  void toLower(char* str);
};

#endif
