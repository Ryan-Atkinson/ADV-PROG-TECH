
#include "Game.h"

//defineing constant scores

#define TWO_LINE_SCORE 2
#define ONE_LINE_SCORE 1
#define QWRIKLE_SCORE 6



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
  if(tileRow>=0 && tileRow<maxRow && tileCol>=0 && tileCol<maxCol && tileBoard[tileRow][TileCol]){

        bool north=false;
        bool east=false;
        bool west=false;
        bool south=false;

        //counts the number of tiles
        //can not add over 6 tiles in a row
        int numNorth=0;
        int numEast=0;
        int numWest=0;
        int numSouth=0;

        //if the tile is not against the north border
        if(tileRow>0){

          //if a tile exists in the north
          if(tileBoard[tileRow-1][tileCol]!=nullptr){
            if (tileBoard[tileRow-1][tileCol]->colour ==piece->colour
              || tileBoard[tileRow-1][tileCol]->shape ==piece->shape){
                north=true;
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

            } else{
              north=true;
            }
          }



        //if the tile is not against the south border
        if(tileRow<maxRow && north){

          if(tileBoard[tileRow+1][tileCol]!=nullptr){
          if (tileBoard[tileRow+1][tileCol]->colour ==piece->colour
             || tileBoard[tileRow+1][tileCol]->shape ==piece->shape){
               south=true;

               //checks if there is 6 tiles in this direction
               int currRow=row+1;
               int currCol=tileCol;
               while(tileBoard[currRow][currCol]!=nullptr &&
                 currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

                 numSouth++;
                 currRow++;
               }

               //there is a qwirkle in south direction so a piece can be placed there
               if(numSouth=>6){
                 south=false;
               }
             }
           } else{
             south=true;
           }

        }

        //if this piece is not against the east border
        if(tileCol<maxCol && south && north){
            //if piece is compatable with the adjcent east tile
            if(tileBoard[tileRow][tileCol+1]!=nullptr){
            if (tileBoard[tileRow][tileCol+1]->colour ==piece->colour
             || tileBoard[tileRow][tileCol+1]->shape ==piece->shape){
               east=true;
               //checks if there is 6 tiles in this direction
               int currRow=row;
               int currCol=tileCol+1;
               while(tileBoard[currRow][currCol]!=nullptr &&
                 currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

                 numEast++;
                 currCol++;
               }

               //there is a qwirkle in south direction so a piece can be placed there
               if(numEast=>6){
                 east=false;
               }
          }
        } else{
          east=true;
        }
      }

        //if piece is not against the west border
        if(tileCol>0 && east && north & south){
            //if piece is compatable with the adjcent west tile
            if(tileBoard[tileRow][tileCol-1]!=nullptr){
           if (tileBoard[tileRow][tileCol-1]->colour ==piece->colour
            || tileBoard[tileRow][tileCol-1]->shape ==piece->shape){
              west=true;

               //checks if there is 6 tiles in this direction
               int currRow=row;
               int currCol=tileCol-1;
               while(tileBoard[currRow][currCol]!=nullptr &&
                 currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

                 numWest++;
                 currCol--;
               }

               //there is a qwirkle in west direction so a piece can be placed there
               if(numWest=>6){
                 west=false;
               }
            }
          } else{
            west=true;
          }

        }

        //if all adjcent tiles are compatable then the piece is added
        if(north && east && south && west){
          int addToScore=0;
          //if there are tiles in some direction
          if(numNorth<0 || numSouth<0 || numEast<0 || numWest<0){

            if((numNorth+numSouth)<6 && (numEast+numWest)<6){


              if((numNorth+numSouth)==5){
                std::cout<<"QWIRKLE!!"<<std::endl;
              //  if(currentPlayer.compare(player1->getName())==0){
                addToScore+=QWIRKLE_SCORE;

              }

            if((numWest+numEast==5)){
              std::cout<<"QWIRKLE!!"<<std::endl;
              addToScore+=QWIRKLE_SCORE;

            }

            //  finds if the tile is next two lines

            //finds the number of actual adjcent tiles
            int numAdj=0;
            if(numNorth<0){
              numAdj++;
            }
            if (numSouth<0){
              numAdj++;
            }
            if(numEast<0){
              numAdj++
            }

            if(numWest<0){
              numAdj++;
            }
            if( numAdj<=2){
              addToScore+=TWO_LINE_SCORE;
            } else{
              addTOSCORE+=ONE_LINE_SCORE;
            }

            this->board->add(tileRow,tileMax, )


          }

          }

          this->board->add
          tileBoard[tileRow][tileCol]=piece;
          tileAdded=true;
        }

        }
      }
    }


  }
  if(tileAdded){
    std::cout<<"Colour: "<<tileBoard[row][tileCol]->colour<<std::endl;
  }


  reutrn tileAdded;
}




bool hasGameEnded();
