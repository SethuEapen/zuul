#include <iostream>
#include <string.h>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"
#include "parser.h"

using namespace std;

bool Parser::processCommand(char* str, Player* player){
  if(strncmp(str, "go", 3) == 0){//I took this idea from andrew chesters code
    char* direction = substr(str, 3, strlen(str) - 1);
	pair<const char*, Room*>* p = player->getCurrentRoom()->getExits()->find(direction);//finds the pair of the desired direction
	if(p != NULL){
	  player->getCurrentRoom() = player->getCurrentRoom()->getExits()->get(direction);
	  return false;
	}
	return true;
  }
}
