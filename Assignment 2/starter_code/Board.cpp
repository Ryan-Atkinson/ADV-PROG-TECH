#include "Board.h"
#include <iostream>
#include <string>

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
  std::cout<<"   ";
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

      // if no tile exists in this positon on the board

      if(this->board[i][j]==nullptr){
        std::cout<<"  ";

        //if a tile exists it prints the tile
      } else{

        std::cout<<this->board[i][j]->colour<<this->board[i][j]->shape;
      }
      std::cout<<"|";

    }
      std::cout<<std::endl;
  }


}

int Board::getMaxRow(){
  return this->row;
}

int Board::getMaxCol(){
  return this->col;
}


//checks if the cell can be added to the board

bool Board::add(int row, int column, Tile* piece) {

  this->board[row][column]=piece;
  return true;
}

void Board::setBoard(Tile*** board){
  this->board=board;
}

Tile*** Board::getBoard(){
  return this->board;
}
