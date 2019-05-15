
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

using std::cout;
using std::endl;
using std::string;
using std::cin;

bool menu();
void newGame();
void loadGame();
void showInfo();
int quit();
bool validateName(const std::string& playerName);


int main() {
   LinkedList* list = new LinkedList();
   bool gameInProgress = false;
   while(gameInProgress == false)
   {
     bool menu();
   }
   delete list;
   // delete gameInProgress;

   cout << "TODO: Implement Qwirkle!" << endl;

   return EXIT_SUCCESS;
}

bool menu(){
  bool gameInProgress;
  int input;

  cout << "Welcome to Qwirkle!" << endl;
  cout << "-------------------" << endl;
  cout << "Menu" << endl;
  cout << "----" << endl;
  cout <<"1. New Game" << endl;
  cout <<"2. Load Game" << endl;
  cout <<"3. Show student information" << endl;
  cout <<"4. Quit" << endl;
  cin >> input;

//if statement to look for input from user for menu function
  if(input==1){
    cout << "Creating A New Game" << endl;
    gameInProgress = true;
    newGame();
  } else if (input==2){
    cout << "Loading The Game." << endl;
    gameInProgress = true;
    loadGame();

  } else if (input==3){
    std::cout << "Show Student Information." << endl;
    showInfo();

  } else if (input==4) {

    cout << "Quiting the menu" << endl;
    quit();

  } else{
    cout << "Error Invalid Selection." << endl;
    cout << "Please choose again." << endl;
    cin >> input;

  }
  return gameInProgress;

}

void newGame(){
  //generate a new game
  // string playerName;
  // cout << "starting a New Game" << endl;
  // // while()
  // cout << "Enter a name for Player 1 (uppercase characters only): " << endl;
  // std::cin >>playerName;
  // validateName(playerName);
  // cout <<"Enter a name for Player 2 (uppercase characters only): " << endl;
  // std::cin >>playerName;
  // validateName(playerName);
  //
  // cout << "Let's Play!" << endl;
}

void loadGame(){
  //LOADS THE GAME FROM HERE FOR ALL PLAYERS
}

void showInfo(){
  //DISPLAYS PLAYER INFORMATION
  cout <<"---------------------------------" << endl;
  cout <<"Name: Duc Chau" << endl;
  cout <<"Student ID: S3656289" << endl;
  cout <<"Email: S3656289@student.rmit.edu.au" << endl;

  cout <<"Name: Ryan Atkinson" << endl;
  cout <<"Student ID: S3646447 " << endl;
  cout <<"Email: S3646447@student.rmit.edu.au" << endl;

  cout <<"Name: Eleni Cook" << endl;
  cout <<"Student ID: S3722194" << endl;
  cout <<"Email: S3722194@student.rmit.edu.au" << endl;
}

int quit(){
  //EXITS THE PROGRAM
  return EXIT_SUCCESS;
}

bool validateName(const std::string& playerName){
  // for (const char c : playerName){
  //   if(!isalpha(c) || !isupper(c)){
  //     return false;
  //   }
  //
  // }
  return true;
}
