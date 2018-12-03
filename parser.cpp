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
  else if(strncmp(str, "take ", 5) == 0){
	char* ItemName = substr(str, 5, strlen(str) + 1);
	if(player->getCurrentRoom()->validItem(ItemName)){
		player->addItem(player->getCurrentRoom()->takeItem(ItemName));
		cout << "You now have " << ItemName << endl;
	}
	else{
		cout << "Not a valid item!" << endl;
	}
  }
  else if(strncmp(str, "drop ", 5) == 0){
	char* ItemName = substr(str, 5, strlen(str) + 1);
	if(player->validItem(ItemName)){
		player->getCurrentRoom()->addItem(player->takeItem(ItemName));
		cout << "You dropped the " << ItemName << endl;
	}
	else{
		cout << "Not a valid item!" << endl;
	}
  }
  else if(strcmp(str, "exits") == 0){
    player->getCurrentRoom()->getExitDirections();
  }
  else if(strcmp(str, "inventory") == 0){
    player->printInventory();
  }
  else if(strcmp(str, "room items") == 0){
    player->getCurrentRoom()->printItems();
  }
  else if(strcmp(str, "exit") == 0){
    return false;
  }
  else{
	cout << "That is not a valid command" << endl;
  }
  return true;
}
