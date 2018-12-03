#include <iostream>
#include <string.h>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"
#include "parser.h"

using namespace std;

char* Parser::substr(char* str, int start, int end){
  char* sub = new char[end-start+1];//allocate to heap (andrew told me to do it like this)
  int x = 0;
  for(int i = start; i < end; i++){
    sub[x] = str[i];
    x++;
  }
  return sub;
}

bool Parser::processCommand(char* str, Player* player){
  if(strncmp(str, "go ", 3) == 0){//I took this idea from andrew chesters code
    char* direction = substr(str, 3, strlen(str) + 1);
    if(player->getCurrentRoom()->isValidRoom(direction)){//finds the pair of the desired direction
      player->setCurrentRoom(player->getCurrentRoom()->getExitRoom(direction));
      cout << player->getCurrentRoom()->getDescription() << endl;
      delete direction;
    }
    else{
      cout << "That is not a valid direction" << endl;
    }
  }
  else if(strncmp(str, "exits", 5) == 0){
    player->getCurrentRoom()->getExitDirections();
  }
  else if(strncmp(str, "inventory", 9) == 0){
    player->printInventory();
  }
  else if(strncmp(str, "exit", 4) == 0){
    return false;
  }
  return true;
}
