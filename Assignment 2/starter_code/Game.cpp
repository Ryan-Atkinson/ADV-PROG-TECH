
#include "Game.h"



Game(Player* player1, Player* player2): player1(player1), player2(player2){
  tileBag= new Bag();
  board= new Board(26,26);
}
~Game(){

}

void addPlayer(Player* player){

}
bool replaceTile(std::string tile){

}

void changeCurrentPlayer(){

}
bool addTileToBoard(std::string tile, int tileRow, int tileCol){



  //add tile to board

  //if successful, remove from players hand
  //add tile to players hand


  Tile*** tileBoard = this->board->getBoard;

  int maxRow =this->board->getMaxRow();
  int maxCol=this->board->getMaxCol();



  bool tileAdded=false;

  //checks to see if the row and column are validate on the board
  if(tileRow>=0 && tileRow<maxRow && tileCol>=0 && tileCol<macCol){


        bool north=true;
        bool east=true;
        bool west=true;
        bool south=true;


        //counts the number of tiles
        //can not add over 6 tiles in a row
        int numNorth=0;
        int numEast=0;
        int numWest=0;
        int numSouth=0;


        //if the tile is not against the north border
        if(tileRow>0){

            //if a tile exists in the north
          } if (tileBoard[tileRow-1][tileCol]->colour ==piece->colour
             || tileBoard[tileRow-1][tileCol]->shape ==piece->shape){

            //checks if there is 6 tiles in this direction
            int currRow=row-1;
            int currCol=tileCol;
            while(tileBoard[currRow][currCol]!=nullptr &&
              currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

              numNorth++;
              currRow--;
            }

            //there is a qwirkle in north direction so a piece can be placed there
            if(numNorth=>6){
              north=false;
            }

          }
        }

        //if the tile is not against the south border
        if(tileRow<maxRow && north){


          if (tileBoard[tileRow+1][tileCol]->colour ==piece->colour
             || tileBoard[tileRow+1][tileCol]->shape ==piece->shape){

               //checks if there is 6 tiles in this direction
               int currRow=row+1;
               int currCol=tileCol;
               while(tileBoard[currRow][currCol]!=nullptr &&
                 currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

                 numSouth++;
                 currRow++;
               }

               //there is a qwirkle in south direction so a piece can be placed there
               if(numNorth=>6){
                 south=false;
               }

        }

        //if this piece is not against the east border
        if(tileCol<maxCol && south && north){
            //if piece is compatable with the adjcent east tile
            if (tileBoard[tileRow][tileCol+1]->colour ==piece->colour
             || tileBoard[tileRow][tileCol+1]->shape ==piece->shape){
               //checks if there is 6 tiles in this direction
               int currRow=row;
               int currCol=tileCol+1;
               while(tileBoard[currRow][currCol]!=nullptr &&
                 currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

                 numSouth++;
                 currCol++;
               }

               //there is a qwirkle in south direction so a piece can be placed there
               if(numNorth=>6){
                 east=false;
               }
          }
        } else{
          east=true;
        }

        //if piece is not against the west border
        if(tileCol>0 && east && north & south){
            //if piece is compatable with the adjcent west tile
          if(tileBoard[tileRow][tileCol-1] ==nullptr){
            west=true;

          } else if (tileBoard[tileRow][tileCol-1]->colour ==piece->colour
            || tileBoard[tileRow][tileCol-1]->shape ==piece->shape){
            tileExist=true;
            west=true;
          }
        } else{
          west=true;
        }

        //if all adjcent tiles are compatable then the piece is added
        if(tileExist && north && east && south && west){
          tileBoard[tileRow][tileCol]=piece;
          tileAdded=true;
        }

      } else{
        tileBoard[tileRow][tileCol]=piece;
        tileAdded=true;
      }
    }


  }
  if(tileAdded){
    std::cout<<"Colour: "<<tileBoard[row][tileCol]->colour<<std::endl;
  }

}
bool hasGameEnded();
