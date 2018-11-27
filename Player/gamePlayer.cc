#include "Player.h"
#include "gamePlayer.h"
#include "../Blocks/OBlock.h"
#include "../Blocks/JBlock.h"
#include "../Blocks/IBlock.h"
#include "../Blocks/SBlock.h"
#include "../Blocks/ZBlock.h"
#include "../Blocks/TBlock.h"
#include "../Blocks/LBlock.h"
#include "../Level/Level.h"
#include "../Level/Level0.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Level/Level3.h"
#include "../Level/Level4.h"
#include <sstream>
#include <string>


//GamePlayer::GamePlayer(xWindow &w){}
GamePlayer::GamePlayer(Grid* grid, Level *level):grid(grid), level(level){}

GamePlayer::~GamePlayer(){
  delete grid;
  delete level;
  delete nextBlock;
  delete currBlock;
}

std::vector<GridCell>* GamePlayer::getRow(int rowNum){
  return grid->getRow(rowNum);
}

int GamePlayer::getLevel() {
  return level->getLevel();
}

int GamePlayer::getScore() {
  return score;
}

char GamePlayer::getNextBlock() {
  return level->getNextBlock();
}

void GamePlayer::setNextBlock(char b) {
  switch (b)
  {
    case 'S':
      currBlock = new SBlock(grid);
      break;
    case 'Z':
      currBlock = new ZBlock(grid);
      break;
    case 'T':
      currBlock = new TBlock(grid);
      break;
    case 'L':
      currBlock = new LBlock(grid);
      break;
    case 'J':
      currBlock = new JBlock(grid);
      break;
    case 'O':
      currBlock = new OBlock(grid);
      break;
    case 'I':
      currBlock = new IBlock(grid);
      break;
  }
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
bool isFull(std::vector<GridCell>* vec){
  for(auto i: *vec){
      if(!i.isUsed){
          return false;
      }
  }
  return true;
}

//Shift all cells above rowCleared down by one
void GamePlayer::shiftCellsDown(int rowCleared){
  for(int y = rowCleared-1; y >= 3; y--){
    for(int x = 0; x < 11; x++){
      if(grid->getGridCell(x,y)->isUsed) {
        grid->getGridCell(x,y+1)->isUsed = true;
      } else {
        grid->getGridCell(x,y+1)->isUsed = false;
      }
      grid->getGridCell(x,y+1)->setType(grid->getGridCell(x,y)->getType());        
    }
  }
  //Set the block cells to one cell below the current
  for(auto i : blocksOnBoard){
    i->moveCellsDown();
  }
  
}

//If the block is empty (i.e has no cells) delete it
void GamePlayer::removeEmptyBlocks(){
  for(int i = 0; i < blocksOnBoard.size(); i++){
    if(blocksOnBoard.at(i)->numCells() == 0){
      blocksOnBoard.erase(blocksOnBoard.begin() + i);
      i--;
    }
  }
}

void GamePlayer::drop() {
  while(currBlock->moveDown());
  blocksOnBoard.emplace_back(currBlock);
  int numRowsCleared;
  //Go through each row
  for(int y = 17; y >=3; y--){
    //Check to see if the row is full
    
    if(isFull(grid->getRow(y))){
      //Go through every cell in the row
      
      std::vector<GridCell>* row = grid->getRow(y);
      for(int i = 0; i < 11; i++){

        //Go through every block on the board
        for(auto j: blocksOnBoard){
          //Call drop with the coordinates of the cell on the board
          //If the cell is in the block it will be removed from the block
          j->removeCellFromBlock(row->at(i).getX(), row->at(i).getY());
        }

        //Set each cell in the full row to false
        //Set the character to ' '
        row->at(i).isUsed = false;
        row->at(i).setType(' ');
      }
      
      //Remove any blocks that may have been emptied
      removeEmptyBlocks();

      //Move all cells above current row down one
      shiftCellsDown(y);

      //Increment numRowsCleared;
      numRowsCleared++;

      //Start from a row lower if the row you are on got cleared
      y++;
    }
  }
  //Add to the score
  score += level->getScore(numRowsCleared);
}

void GamePlayer::print(){
  std::cout << "Level:    " << getLevel() << std::endl;
  std::cout << "Score:    " << getScore() << std::endl;
  std::cout << "-----------" << std::endl;
  for(int y = 0; y < 18; y++){
    for(int x = 0; x <11; x++){
      std::cout << *(grid->getGridCell(x,y));
    }
    std::cout << std::endl;
  }
  std::cout << "-----------" << std::endl;
  std::cout << "Next:" << std::endl;

}

