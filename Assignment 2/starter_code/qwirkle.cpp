
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

void board();
bool menuOption();
void showMenu();
void newGame();
void loadGame();
void showInfo();
bool validateName(const std::string& playerName);


int main() {
   LinkedList* list = new LinkedList();
   bool gameInProgress = false;
   while(!gameInProgress)
   while(!gameInProgress)
   {

     menuOption();
   }
   delete list;
   // delete gameInProgress;


   return EXIT_SUCCESS;
}

void board(){
  const char row = 6;
  const char col = 6;
  //2D array to store the lines '|' on the board
  char boardArr [row][col];

  //The numbers on top of the board
  std::cout <<"   0  1  2  3  4  5" <<"\n";
  std::cout <<"  -------------------";

  //print the board
  for (int i=0;i<row;++i)
  {
    //print numbers from 0 to 5 on top of board

    for(int j=0;j<col;++j)
    {
      boardArr[i][j] = {'|'};
    }
  }
  //print array as grid
  for(int i =0;i<row;++i)
  {
      std::cout <<"\n";

    for(int j=0;j<col;++j)
    {
      if(j==0){
        //prints the ASCII character from A to F on the side of the board
        std::cout <<(char)('A'+i)<<" ";
      }
        std::cout <<boardArr[i][j];
        //spaces inbetween the "|" lines
        std::cout<<"  "; //we can try and use the empty spaces as a way to input the user tiles

    }
    //Printing the last line at the end of the board on the far right
    std::cout<<"|";
  }

  std::cout <<"\n";

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
    std::cout << std::string( 50, '\n' );
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
  std::string playerName;
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
  board();
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
