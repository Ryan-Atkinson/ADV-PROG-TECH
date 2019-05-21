
#include "Game.h"


//defineing constant scores

#define TWO_LINE_SCORE 2
#define ONE_LINE_SCORE 1
#define QWRIKLE_SCORE 6
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4



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

Player* getCurrentPlayer(){
  Player* player;
  if(currentPlayer.compare(this->player1->getName())==0){
    player=this->player1
  } else{
    player=this->player2;
  }

  return player;
}

bool addTileToBoard(std::string tile, int tileRow, int tileCol){
    bool tileAdded=false;
  //if current player hand has this tile


  //add tile to board

  //if successful, remove from players hand
  //add tile to players hand

  // have to validate this string somewhere

  //if this tile is a valid tile
  if ((tile[0]=='R' || tile[0]=='Y' || tile[0]=='G' || tile[0]=='B' || tile[0]=='P') &&
  (tile[1]==1 || tile[1]==2 ||  tile[1]==3 ||  tile[1]==4 ||  tile[1]==5 ||  tile[1]==6)){
    Tile tilePiece = new Tile(tile[0], tile[1]);



    Tile*** tileBoard = this->board->getBoard;

    int maxRow =this->board->getMaxRow();
    int maxCol=this->board->getMaxCol();



  //checks to see if the row and column are validate on the board
  if(tileRow>=0 && tileRow<maxRow && tileCol>=0 && tileCol<maxCol && tileBoard[tileRow][TileCol]==nullptr){


    //are the tiles in these ceels compatable with the current tile
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
    }



    //if the tile is not against the south border
    if(tileRow<maxRow && north){

      if(tileBoard[tileRow+1][tileCol]!=nullptr){
      if (tileBoard[tileRow+1][tileCol]->colour ==piece->colour
         || tileBoard[tileRow+1][tileCol]->shape ==piece->shape){
           south=true;

           //checks if there is 6 tiles in this direction
           int numEast= numOfTiles(tileRow+1, tileCol, SOUTH);
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

            int numEast= numOfTiles(tileRow, tileCol+1, EAST);
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
    if(tileCol>0 && east && north && south ){
        //if piece is compatable with the adjcent west tile
        if(tileBoard[tileRow][tileCol-1]!=nullptr){
       if (tileBoard[tileRow][tileCol-1]->colour ==piece->colour
        || tileBoard[tileRow][tileCol-1]->shape ==piece->shape){
          west=true;

           //checks if there is 6 tiles in this direction
           int numWest= numOfTiles(tileRow, tileCol-1, WEST);

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
    if(north && east && south && west && && (numNorth+numSouth)<6 && (numEast+numWest)<6)){
      int score= findScore(numNorth, numSouth, numEast, numWest);
      getCurrentPlayer()->addPoints(score);
      tileAdded=true;
      this->board->add(tileRow,tileMax, tilePiece);
      getCurrentPlayer()->removeTile(tilePiece);
    } else{
      std::cout<< "Invalid Input: Can't place tile there"
    }

  } else{
    std::cout<<"Invalid Input: That cell isn't avaliable"<<std::endl;
  }
  } else{
    std::cout<<"Invalid Input: Tile doesn't exist"<<std::endl;
  }

  return tileAdded;
}

int numOfTiles(int tileRow, int tileCol, int direction){
  int numTiles=0;

  Tile*** tileBoard = this->board->getBoard;

  int maxRow =this->board->getMaxRow();
  int maxCol=this->board->getMaxCol();

  int currRow=tileRow;
  int currCol=tileCol;
  while(tileBoard[currRow][currCol]!=nullptr &&
    currRow>=0 && currCol>=0 && currRow>maxRow && curCol>maxCol && numNorth<6){

    numTiles++;
    if(direction==NORTH){
      curRow--;
    } else if (direction==EAST){
      currCol++;

    } else if (direction==SOUTH){
      currRow++;

    } else if (direction ==WEST){
      currCol--;
    }

  }
  return numTiles;



}

int findScore(int numNorth, int numSouth, int numEast, int numWest){
  int addToScore=0;
  //if there are tiles in some direction
  if(numNorth<0 || numSouth<0 || numEast<0 || numWest<0){


      if((numNorth+numSouth)==5){
        std::cout<<"QWIRKLE!!"<<std::endl;

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
      addToScore+=ONE_LINE_SCORE;
    }

    return addToScore;
}


int findNumberOfAdjcent(int north, int south, int west, int east){



}


bool hasGameEnded(){

}
