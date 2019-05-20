#include "Board.h"
#include <iostream>

Board::Board(int row, int col) : row(row), col(col) {

  this->board= new Tile**[this->row];
  for(int i = 0; i < this->row; i++){
    this->board[i] = new Tile*[this->col];
  }





  // for (int row = 0; row < 6; row++) {
  //   for (int col = 0; col < 6; col++) {
  //     array[row][col] = '  ';
  //   }
  // }

}

Board::~Board(){
  for(int i = 0; i < this->row; i++){
      delete[] this->board[i];
  }

  delete[] this->board;
}

void Board::printBoard(){

  //prints the column numbers
  std::cout<<"  ";
  for(int i =0; i<col;i++){
    if(i<10){
      std::cout<<i<<"  ";
    } else{
      std::cout<<i<<" ";
    }

  }
  std::cout<<std::endl;

  //prints the dashs
  std::cout<<"  ";
  for(int i =0; i<col;i++){
    std::cout<<"---";
  }
  std::cout<<"-";
  std::cout<<std::endl;


  for(int i =0; i<row; i++){
    std::cout<<(char)('A'+i)<<" ";
    std::cout<<"|";
    for(int j=0; j<col;j++){

      if(this->board[i][j]==nullptr){
        std::cout<<"  ";
      } else{
        std::cout<<this->board[i][j]->colour<<this->board[i][j]->colour;
      }
      std::cout<<"|";

    }
      std::cout<<std::endl;
  }


}

bool Board::add(int row, int column, Tile& piece) {
  // if (array[row][col] == '  ') {
  //   array[row][col] = piece;
  return true;


}
// Board::Board(const int row,const int col){
//   const char row = 6;
//   const char col = 6;
//   //2D array to store the lines '|' on the board
//   char boardArr [row][col];
//
//   //The numbers on top of the board
//   std::cout <<"   0  1  2  3  4  5" <<"\n";
//   std::cout <<"  -------------------";
//
//   //print the board
//   for (int i=0;i<row;++i)
//   {
//     //print numbers from 0 to 5 on top of board
//
//     for(int j=0;j<col;++j)
//     {
//       boardArr[i][j] = {'|'};
//     }
//   }
//   //print array as grid
//   for(int i =0;i<row;++i)
//   {
//       std::cout <<"\n";
//
//     for(int j=0;j<col;++j)
//     {
//       if(j==0){
//         //prints the ASCII character from A to F on the side of the board
//         std::cout <<(char)('A'+i)<<" ";
//       }
//         std::cout <<boardArr[i][j];
//         //spaces inbetween the "|" lines
//         std::cout<<"  "; //we can try and use the empty spaces as a way to input the user tiles
//
//     }
//
//     //Printing the last line at the end of the board on the far right
//     std::cout<<"|";
//   }
//
//   std::cout <<"\n";
