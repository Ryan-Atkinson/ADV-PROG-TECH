
#include "Game.h"
#include "TileCodes.h"

#include <iostream>

#include <string>


//defineing constant scores

#define TWO_LINE_SCORE 2
#define ONE_LINE_SCORE 1
#define QWIRKLE_SCORE 6
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4



Game::Game(Player* player1, Player* player2): player1(player1), player2(player2){
  tileBag= new Bag();
  board= new Board(26,26);
  currentPlayer= player1->getName();
  player1->drawTile(tileBag);
  player2->drawTile(tileBag);
}

Game::Game(Player* player1, Player* player2, Bag* bag, Board* board, Player* currentPlayer): player1(player1), player2(player2), tileBag(bag), board(board){
  this->currentPlayer=currentPlayer->getName();
  player1->drawTile(tileBag);
  player2->drawTile(tileBag);
  }
Game::~Game(){

}

Board* Game::getBoard(){
  return this->board;
}
Player* Game::getPlayer1(){
  return this->player1;
}
Player* Game::getPlayer2(){
  return this->player2;
}
Bag* Game::getTileBag(){
  return this->tileBag;
}

Player* Game::getOtherPlayer(){
  Player* player;
  if(currentPlayer.compare(this->player1->getName())==0){
    player=this->player2;
  } else{
    player=this->player1;
  }

  return player;
}


bool Game::replaceTile(std::string tile){
  return false;
}

void Game::changeCurrentPlayer(){
  if(currentPlayer.compare(this->player1->getName())==0){
    currentPlayer=player2->getName();
  } else{
    currentPlayer=player1->getName();
  }

}

Player* Game::getCurrentPlayer(){
  Player* player;
  if(currentPlayer.compare(this->player1->getName())==0){
    player=this->player1;
  } else{
    player=this->player2;
  }

  return player;
}

bool Game::addTileToBoard(std::string tile, int tileRow, int tileCol){
  bool tileAdded=false;


  //if current player hand has this tile


  //add tile to board

  //if successful, remove from players hand
  //add tile to players hand

  // have to validate this string somewhere

  //if this tile is a valid tile
  int shape = tile[1] -'0';

  if ((tile[0]==RED || tile[0]==ORANGE || tile[0]==YELLOW || tile[0]==GREEN || tile[0]==BLUE || tile[0]==PURPLE) &&
  (shape==CIRCLE || shape==STAR_4 ||  shape==DIAMOND ||  shape==SQUARE ||  shape==STAR_6 ||  shape==CLOVER)){
    Tile* tilePiece = new Tile(tile[0], shape);



    Tile*** tileBoard = this->board->getBoard();

    int maxRow =this->board->getMaxRow();
    int maxCol=this->board->getMaxCol();



  //checks to see if the row and column are validate on the board
  if(tileRow>=0 && tileRow<maxRow && tileCol>=0 && tileCol<maxCol && tileBoard[tileRow][tileCol]==nullptr){


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
        if (tileBoard[tileRow-1][tileCol]->colour ==tilePiece->colour
          || tileBoard[tileRow-1][tileCol]->shape ==tilePiece->shape){

            north=true;

          //checks if there is 6 tiles in this direction
          numNorth= numOfTiles(tileRow-1, tileCol, NORTH);

          //there is a qwirkle in north direction so a piece can be placed there
          if(numNorth>=6){
            north=false;
          }

        }

      //there is a nullptr, so the tile is empty
      }else{
        north=true;
      }
    }



    //if the tile is not against the south border
    if(tileRow<maxRow && north){

      if(tileBoard[tileRow+1][tileCol]!=nullptr){
        if (tileBoard[tileRow+1][tileCol]->colour ==tilePiece->colour
          || tileBoard[tileRow+1][tileCol]->shape ==tilePiece->shape){
             //adjcent tile is compatable with current tile
             south=true;

             //checks if there is 6 tiles in this direction
             numSouth= numOfTiles(tileRow+1, tileCol, SOUTH);

             //there is a qwirkle in south direction so a piece can be placed there
             if(numSouth>=6){
               south=false;
             }
           }

         //if there is a nullptr
       } else{
         south=true;
       }

    }

    //if this piece is not against the east border
    if(tileCol<maxCol && south && north){
      //if piece is compatable with the adjcent east tile
      if(tileBoard[tileRow][tileCol+1]!=nullptr){
        if (tileBoard[tileRow][tileCol+1]->colour ==tilePiece->colour
          || tileBoard[tileRow][tileCol+1]->shape ==tilePiece->shape){
             // //adjcent tile is compatable with current tile
             east=true;

             //checks if there is 6 tiles in this direction
              numEast= numOfTiles(tileRow, tileCol+1, EAST);

             //there is a qwirkle in south direction so a piece can't be placed there
             if(numEast>=6){
               east=false;
         }
       }

      //if there is a nullptr
    } else{
      east=true;
    }
  }

    //if piece is not against the west border
    if(tileCol>0 && east && north && south ){
        //if piece is compatable with the adjcent west tile
        if(tileBoard[tileRow][tileCol-1]!=nullptr){
          if (tileBoard[tileRow][tileCol-1]->colour ==tilePiece->colour
            || tileBoard[tileRow][tileCol-1]->shape ==tilePiece->shape){
              west=true;

               //checks if there is 6 tiles in this direction
               numWest= numOfTiles(tileRow, tileCol-1, WEST);

               //there is a qwirkle in west direction so a piece can't be placed there
               if(numWest>=6){
                 west=false;
           }
        }

        //if there is a nullptr
      } else{
        west=true;
      }

    }

    //if all adjcent tiles are compatable then the piece is added
    if(north && east && south && west && (numNorth+numSouth)<6 && (numEast+numWest)<6){
      std::cout<<"num west"<<numWest<<std::endl;
      std::cout<<"num east"<<numEast<<std::endl;

      std::cout<<"num south"<<numSouth<<std::endl;
      std::cout<<"num north"<<numNorth<<std::endl;
    //  std::cout<<"num west"<<numWest<<std::endl;
      //finds the total score for this move
      int score= findScore(numNorth, numSouth, numEast, numWest);

      //adds the score the current player
      getCurrentPlayer()->addPoints(score);
      std::cout<<"score: "<<score<<std::endl;

      //add tile to the board
      this->board->add(tileRow,tileCol, tilePiece);
      tileAdded=true;

      //remove tile for players hand
      //currently not working
      //getCurrentPlayer()->removeTile(*tilePiece);
    } else{
      std::cout<< "Invalid Input: Can't place tile there"<<std::endl;
    }

  } else{
    std::cout<<"Invalid Input: That cell isn't avaliable"<<std::endl;
  }

  } else{
    std::cout<<"Invalid Input: Tile doesn't exist"<<std::endl;
  }

  return tileAdded;
}

int Game::numOfTiles(int tileRow, int tileCol, int direction){
  int numTiles=0;

  Tile*** tileBoard = this->board->getBoard();

  int maxRow =this->board->getMaxRow();
  int maxCol=this->board->getMaxCol();

  int currRow=tileRow;
  int currCol=tileCol;
  std::cout<<"Line 262: tileBoard:"<<tileBoard[currRow][currCol]->colour<<std::endl;
  while(tileBoard[currRow][currCol]!=nullptr && currRow>=0 && currCol>=0 && currRow<maxRow && currCol<maxCol){

    numTiles++;
    if(direction==NORTH){
      currRow--;
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

int Game::findScore(int numNorth, int numSouth, int numEast, int numWest){
  int addToScore=0;
  //if there are tiles in some direction
  if(numNorth>0 || numSouth>0 || numEast>0 || numWest>0){


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
    if(numNorth>0){
      numAdj++;
    }
    if (numSouth>0){
      numAdj++;
    }
    if(numEast>0){
      numAdj++;
    }

    if(numWest>0){
      numAdj++;
    }
    if( numAdj>=2){
      addToScore+=TWO_LINE_SCORE;
    } else{
      addToScore+=ONE_LINE_SCORE;
    }
  }

    return addToScore;
}


bool Game::hasGameEnded(){
  return false;

}
