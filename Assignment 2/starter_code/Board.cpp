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

//checks if the cell can be added to the board

bool Board::add(int row, int column, Tile* piece) {
  bool tileAdded=false;

  //checks to see if the row and column are validate on the board
  if(row>=0 && row<this->row && column>=0 && column<this->col){

    if(this->board[row][column]==nullptr){
      bool anyTileExists= false;

      int currRow=0;
      int currCol=0;

      //checks to see if there are any tiles on teh board,
      //if not it's the first turn and the player can place anything anywhere
      while(!anyTileExists && currRow<this->row && currCol<this->row){
        if(this->board[currRow][currCol]!=nullptr){
          anyTileExists=true;

        }
        currRow++;
        currCol++;
      }

      //if tile exist on a border, as to check if adjecent tiles are compatable
      if(anyTileExists){


        //if there is actually an adjcent tile in again off the cells
        bool tileExist=false;

        //cehcsk if the neighbours are compatable
        bool north=false;
        bool east = false;
        bool south= false;
        bool west=false;

        //if the tile is not against the north border
        if(row>0){
          //if tile is compatable with the adjcent north tile
          if(this->board[row-1][column] ==nullptr){
            north=true;

          } else if (this->board[row-1][column]->colour ==piece->colour || this->board[row-1][column]->shape ==piece->shape){
            tileExist=true;
            north=true;
          }
        } else{
          north=true;
        }

        //if the tile is not against the south border
        if(row<this->row){
            //if tile is compatable with the adjcent south tile
          if(this->board[row+1][column] ==nullptr){
            south=true;

          } else if (this->board[row+1][column]->colour ==piece->colour || this->board[row+1][column]->shape ==piece->shape){
            tileExist=true;
            south=true;
          }
        } else{
          south=true;
        }

        //if this piece is not against the east border
        if(column<this->col){
            //if piece is compatable with the adjcent east tile
          if(this->board[row][column+1] ==nullptr){
            east=true;

          } else if (this->board[row][column+1]->colour ==piece->colour || this->board[row][column+1]->shape ==piece->shape){
            tileExist=true;
            east=true;
          }
        } else{
          east=true;
        }

        //if piece is not against the west border
        if(column>0){
            //if piece is compatable with the adjcent west tile
          if(this->board[row][column-1] ==nullptr){
            west=true;

          } else if (this->board[row][column-1]->colour ==piece->colour || this->board[row][column-1]->shape ==piece->shape){
            tileExist=true;
            west=true;
          }
        } else{
          west=true;
        }

        //if all adjcent tiles are compatable then the piece is added
        if(tileExist && north && east && south && west){
          this->board[row][column]=piece;
          tileAdded=true;
        }

      } else{
        this->board[row][column]=piece;
        tileAdded=true;
      }
    }


  }
  if(tileAdded){
    std::cout<<"Colour: "<<this->board[row][column]->colour<<std::endl;
  }

  return tileAdded;
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
