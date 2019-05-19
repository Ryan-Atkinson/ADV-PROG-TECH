

#include "TileCodes.h"
#include "Tile.h"
#include "Node.h"
#include "LinkedList.h"
#include "Board.h"
#include "Player.h"
#include "Bag.h"

#include <iostream>
#include <fstream>
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
   Bag* bag = new Bag();
   bool gameInProgress = false;
   if(gameInProgress==false)
   {
     showMenu();
     menuOption();

     // bag->shuffle();
     // bag->printBag();
     // bag->takeTile();
     // bag->printBag();

   }
   delete list;
   delete bag;
   // delete gameInProgress;


   return EXIT_SUCCESS;
}



void showMenu(){
  std::cout<<"\n";
  std::cout << "Welcome to Qwirkle!" << "\n";
  std::cout << "-------------------" << "\n";
  std::cout <<"Menu"<<"\n";
  std::cout <<"----"<<"\n";
  std::cout <<"1. New Game" << "\n";
  std::cout <<"2. Load Game" << "\n";
  std::cout <<"3. Show student information" << "\n";
  std::cout <<"4. Quit" << "\n";
  std::cout<<"\n";
}

bool menuOption(){
  // showMenu();
  bool gameInProgress;
  char input;

  std::cout<<"> ";
  std::cin >> input;
  if(std::cin.eof()){
    std::cout<<"Goodbye"<<"\n";
    exit(0);
  }


//if statement to look for input from user for menu function
  if(input=='1'){
    std::cout << "Creating A New Game" << "\n";
    gameInProgress = true;
    newGame();

  } else if (input=='2'){
    std::cout << "Loading The Game." << "\n";
    gameInProgress = true;
    loadGame();

  } else if (input=='3'){
    std::cout << "Show Student Information." << "\n";
    //displays student information and then returns to menu screen
    showInfo();
    menuOption();

  } else if (input=='4'){
    std::cout << "Quiting the menu" << "\n";
    //clears the screen with 50 end lines and exits the program without crashing
    std::cout << std::string( 50, '\n' );
    exit(0);

  }else{
    while((input != '1') && (input !='2') &&(input !='3')&&(input!='4'))
    {
    std::cout << "Invalid Input"<< "\n";
    menuOption();
    std::cout<<"> ";
    std::cin >>input;
  }
  }

  return gameInProgress;
}

void newGame(){
  //generate a new game
  //player name variables
  std::string playerName1;
  std::string playerName2;
  std::cout << "Starting a New Game" << "\n";
  std::cout << "Enter a name for Player 1 (uppercase characters only): " << "\n";
  std::cout<<"> ";
  //player 1 name input
  std::cin >>playerName1;
  //while loop to check for validity to player name (name must be uppercase!)
  while(validateName(playerName1)==false){
    std::cout <<"Uppercase characters only for playername!" <<"\n";
    std::cout<<"> ";
    std::cin >>playerName1;
  }
    std::cout << "Enter a name for Player 2 (uppercase characters only): " << "\n";
    std::cout<<"> ";
    std::cin >>playerName2;
  //while loop to check for validity to player name (name must be uppercase!)
  while(validateName(playerName2)==false){
    std::cout <<"Uppercase characters only for playername!" <<"\n";
    std::cout<<"> ";
    std::cin >>playerName2;
  }
  if(!std::cin.fail()){
    std::cout << "Let's Play!" << "\n";
    std::cout <<"<normal gameplay continues from here>" <<"\n";
  }
}


void loadGame(){
  //LOADS THE GAME FROM HERE FOR ALL PLAYERS

  std::string filename;
  std::cout <<"Enter a filename: "<<"\n";
  std::cout <<"> ";
  std::cin >>filename;
  //checks if input contains EOF character (^D)
  if(std::cin.eof()){
    std::cout<<"Goodbye"<<"\n";
  }

  // board();
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
    }else{
      return true;
    }

  }
  return true;
}
