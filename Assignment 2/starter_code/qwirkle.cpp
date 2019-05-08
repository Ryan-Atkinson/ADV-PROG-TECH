
#include "LinkedList.h"
#include "Board.h"
#include "Player.h"
#include "Bag.h"
#include <iostream>
#include <string>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   bool gameInProgress = false;
   while (gameInProgress = false) {
     menu();
   }

   delete list;
   delete gameInProgress;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;
   }

   return EXIT_SUCCESS;
}

void menu(void) {
  // INPUT VARIABLE FOR MENU SELECTION
  int input = 0;

  std::cout << "Welcome to Qwirkle!" << std::endl;
  std::cout << "-------------------" << std::endl;
  std::cout << "Menu" << std::endl;
  std::cout << "----" << std::endl;
  std::cout << "1. New Game" << std::endl;
  std::cout << "2. Load Game" << std::endl;
  std::cout << "3. Show student information" << std::endl;
  std::cout << "4. Quit" << std::endl;
  std::cin >> input;

  // SWITCH FOR SELECTING MENU FUNCTIONS
  switch(input) {
    case '1' :
     std::cout << "New Game selected." << std::endl;
     gameInProgress = true;
     newGame();
     break;
    case '2' :
     std::cout << "Load Game selected." << std::endl;
     gameInProgress = true;
     loadGame();
     break;
    case '3' :
     std::cout << "Show Student Information selected." << std::endl;
     showInfo();
     break;
    case '4' :
     std::cout << "Quit selected." << std::endl;
     quit();
     break;
    default :
     std::cout << "Error. Invalid selection." << std::endl;
     std::cout << "Please choose again." << std::endl;
     std::cin >> input;
     break;
}

void newGame(void) {
  // GENERATES NEW GAME FOR PLAYERS
  string playerName;
  std::cout << "Starting a New Game" << std::endl;
while ()
  std::cout << "Enter a name for player 1 (uppercase characters only)" << endl;
  std::cin >> playerName;
  validateName(playerName);
  std::cout << "Enter a name for player 2 (uppercase characters only)" << endl;
  std::cin >> playerName;
  validateName(playerName);

  std::cout << "Let's Play!" << endl;
}

void loadGame(void) {
  // LOADS GAME FROM SAVE FILE FOR PLAYERS
}

void showInfo(void) {
  // DISPLAYS PLAYER INFORMATION
}

void quit(void) {
  // EXITS THE PROGRAM
  return EXIT_SUCCESS;
}

bool validateName(const std::string& playerName) {
  for (const char c : playerName) {
    if (!isalpha(c) || !isupper(c)) {
      return false;
    }
    return true;
  }
}
