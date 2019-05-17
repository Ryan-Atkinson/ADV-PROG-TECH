
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "TileCodes.h"
#include "Board.h"
#include "Player.h"
#include "Bag.h"

#include <iostream>
#include <string>

#define EXIT_SUCCESS    0


bool menuOption();
void showMenu();
void newGame();
void loadGame();
void showInfo();
bool validateName(const std::string& playerName);


int main() {
   LinkedList* list = new LinkedList();
   bool gameInProgress = false;
   //while(!gameInProgress)
   while(!gameInProgress)
   {
     menuOption();
   }
   delete list;
   // delete gameInProgress;


   return EXIT_SUCCESS;
}

void showMenu(){
  std::cout << "Welcome to Qwirkle!" << "\n";
  std::cout << "-------------------" << "\n";
  std::cout <<"Menu"<<"\n";
  std::cout <<"----"<<"\n";
  std::cout <<"1. New Game" << "\n";
  std::cout <<"2. Load Game" << "\n";
  std::cout <<"3. Show student information" << "\n";
  std::cout <<"4. Quit" << "\n";
}

bool menuOption(){
  showMenu();
  bool gameInProgress;
  int input;
  std::cin >> input;

//if statement to look for input from user for menu function
  if(input==1){
    std::cout << "Creating A New Game" << "\n";
    gameInProgress = true;
    newGame();
  } else if (input==2){
    std::cout << "Loading The Game." << "\n";
    gameInProgress = true;
    loadGame();

  } else if (input==3){
    std::cout << "Show Student Information." << "\n";
    showInfo();

  } else if (input==4) {

    std::cout << "Quiting the menu" << "\n";
    std::cout << string( 50, '\n' );
    exit(0);

  } else{
    std::cout << "Error Invalid Selection." << "\n";
    std::cout << "Please choose again." << "\n";
    std::cin >> input;

  }
  return gameInProgress;

}

void newGame(){
  //generate a new game
  string playerName;
  std::cout << "Starting a New Game" << "\n";
  // while()
  std::cout << "Enter a name for Player 1 (uppercase characters only): " << "\n";
  std::cin >>playerName;
  if(validateName(playerName)==false){
    std::cout <<"Uppercase characters only for playername!" <<"\n";
    std::cin >>playerName;
  }else{
    std::cout << "Enter a name for Player 2 (uppercase characters only): " << "\n";
    std::cin >>playerName;
  }
  if(validateName(playerName)==false){
    std::cout <<"Uppercase characters only for playername!" <<"\n";
    std::cin >>playerName;
  }
    std::cout << "Let's Play!" << "\n";
    std::cout <<"<normal gameplay continues from here>" <<"\n";

}


void loadGame(){
  //LOADS THE GAME FROM HERE FOR ALL PLAYERS
}

void showInfo(){
  //DISPLAYS PLAYER INFORMATION
  std::cout <<"---------------------------------" << "\n";
  std::cout <<"Name: Duc Chau" << "\n";
  std::cout <<"Student ID: S3656289" << "\n";
  std::cout <<"Email: S3656289@student.rmit.edu.au" << "\n";

  std::cout <<"Name: Ryan Atkinson" << "\n";
  std::cout <<"Student ID: S3646447 " << "\n";
  std::cout <<"Email: S3646447@student.rmit.edu.au" << "\n";

  std::cout <<"Name: Eleni Cook" << "\n";
  std::cout <<"Student ID: S3722194" << "\n";
  std::cout <<"Email: S3722194@student.rmit.edu.au" << "\n";
}


bool validateName(const std::string& playerName){
  for (const char c : playerName){
    if(!isalpha(c) || !isupper(c)){
      return false;
    }

  }
  return true;
}
