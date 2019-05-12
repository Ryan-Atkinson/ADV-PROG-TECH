
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
   while(gameInProgress = false)
   {
     menu();
   }
   delete list;
   delete gameInProgress;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}

void menu(void){
  int input =0;

  std::cout << "Welcome to Qwirkle!" << std::endl;
  std::cout << "-------------------" << std::endl;
  std::cout << "Menu" << std::endl;
  std::cout << "----" << std::endl;
  std::cout <<"1. New Game" << std::endl;
  std::cout <<"2. Load Game" << std::endl;
  std::cout <<"3. Show student information" << std::endl;
  std::cout <<"4. Quit" << std::endl;
  std::cin >> input;

  //switch statement
  switch(input){
    case '1' :
    std::cout << "Creating A New Game" << std::endl;
    gameInProgress = true;
    newGame();
    break;
    case '2' :
    std::cout << "Loading The Game." << std::endl;
    gameInProgress = true;
    loadGame();
    break;
    case '3' :
    std::cout << "Show Student Information." << std::endl;
    showInfo();
    break;
    case '4' :
    std::cout << "Quiting the menu" << std::endl;
    quit();
    break;
    default :
    std::cout << "Error Invalid Selection." <<std::endl;
    std::cout << "Please choose again." <<std::endl;
    std::cin >> input;
    break;

}

void newGame(void){
  //generate a new game
  string playerName;
  std::cout << "starting a New Game" << std::endl;
  while()
  std::cout << "Enter a name for Player 1 (uppercase characters only): " << std::end;
  std::cin >>playerName;
  validateName(playerName);
  std::cout <<"Enter a name for Player 2 (uppercase characters only): " <<std::endl;
  std::cin >>playerName;
  validateName(playerName);

  std::cout "Let's Play!" << std::endl;
}

void loadGame(void){
  //LOADS THE GAME FROM HERE FOR ALL PLAYERS
}

void showInfo(void){
  //DISPLAYS PLAYER INFORMATION
  std::cout <<"---------------------------------" << std::endl;
  std::cout <<"Name: Duc Minh Chau" << std::endl;
  std::cout <<"Student ID: S3656289" << std::endl;
  std::cout <<"Email: S3656289@student.rmit.edu.au" << std::endl;

  std::cout <<"Name: Ryan Atkinson" << std::endl;
  std::cout <<"Student ID: " << std::endl;
  std::cout <<"Email: " << std::endl;

  std::cout <<"Name: Eleni" << std::endl;
  std::cout <<"Student ID: " << std::endl;
  std::cout <<"Email: " << std::endl;
}

void quit(void){
  //EXITS THE PROGRAM
  return EXIT_SUCCESS;
}

bool validateName(const std::string& playerName){
  for (const char c : playerName){
    if(!isalpha(c) || !isupper(c)){
      return false;
    }
    return true;
  }
}
