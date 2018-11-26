#include "gamePlayer.h"
#include "../Blocks/OBlock.h"
#include "../Blocks/JBlock.h"
#include "../Blocks/IBlock.h"
#include "../Blocks/SBlock.h"
#include "../Blocks/ZBlock.h"
#include "../Blocks/TBlock.h"


//GamePlayer::GamePlayer(xWindow &w){}
GamePlayer::GamePlayer(Grid* grid):grid(grid){}
GamePlayer::~GamePlayer(){}

std::vector<GridCell> GamePlayer::getRow(int rowNum){
  return grid->getRow(rowNum);
}

int GamePlayer::getLevel() {
  return 0;
}

//Harsh
int GamePlayer::getScore() {
  return 0;
}

Block* GamePlayer::getNextBlock() {
  /*try{

  }*/
  return nullptr;
}

void GamePlayer::setNextBlock(Block * b) {
  currBlock = b;
}

void GamePlayer::moveLeft() {
  currBlock->moveLeft();
}

void GamePlayer::moveRight() {
  currBlock->moveRight();
}

void GamePlayer::moveDown() {
  currBlock->moveDown();
}

void GamePlayer::rotate(std::string direction){
  currBlock->rotate(direction);
}

//Harsh

//When a block is dropped, we go through all the rows of the grid.
//If the row is full then we loop through the row
//When we loop through the row we call drop(x,y) on every block in the grid
//Drop will check to see if the cell is in the block, if it is it will delete it
//Every cell will shift one block downwards

//isFull(std::vector<GridCell> vec) checks to see if all the cells in
// the given vector are used up
// @param std::vector<GridCell> vec: a row vector given to the grid
bool isFull(std::vector<GridCell> vec){
  for(auto i: vec){
      if(!i.isUsed){
          return false;
      }
  }
  return true;
}

void GamePlayer::shiftCellsDown(int rowCleared){
  for(int y = rowCleared-1; y >= 3; y--){
    for(int x = 0; x < 11; x++){
      if(grid->getGridCell(x,y)->isUsed) {
        grid->getGridCell(x,y+1)->isUsed = true;
      } else {
        grid->getGridCell(x,y+1)->isUsed = false;
      }
      grid->getGridCell(x,y+1)->setType(grid->getGridCell(x,y)->getType());        
      /*if(y==16)std::cout << *(grid->getGridCell(x,y+1));
      if(y==16)std::cout << grid->getGridCell(x,y+1)->isUsed;*/
    }
  }
  /*for(auto i : blocksOnBoard){
    i->moveCellsDown();
  }*/
}

//If the block is empty (i.e has no cells) delete it
void GamePlayer::removeEmptyBlocks(){
  for(int i = 0; i < blocksOnBoard.size(); i++){
    if(blocksOnBoard.at(i)->numCells() == 0){
      blocksOnBoard.erase(blocksOnBoard.begin() + i);
    }
  }
}

void GamePlayer::drop() {
  while(currBlock->moveDown());
  blocksOnBoard.emplace_back(currBlock);
  //Go through each row
  for(int y = 17; y >=3; y--){

    //Check to see if the row is full
    if(isFull(grid->getRow(y))){
      //Go through every cell in the row

      for(auto i: grid->getRow(y)){

        //Go through every block on the board
        for(auto j: blocksOnBoard){

          //Call drop with the coordinates of the cell on the board
          //If the cell is in the block it will be removed from the block
          j->removeCellFromBlock(i.getX(), i.getY());
        }
        i.isUsed = false;
        i.setType(' ');
      }
      shiftCellsDown(y);
      //scoring
    }
  }
}

