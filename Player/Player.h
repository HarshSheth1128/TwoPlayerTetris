#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class Player{
    int score;
    Grid *grid;
    Level *level;
    Block *nextBlock;
    Block *currBlock;
    // xWindow *window;

    public:
    virtual ~Player() = 0;
    virtual std::vector<GridCell> getRow(int rowNum) = 0;
    virtual int getLevel() = 0;
    virtual int getScore() = 0;
    virtual Block* getNextBlock() = 0;
    virtual void setNextBlock(Block *) = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
    virtual void rotate(std::string direction) = 0;
    virtual void drop() = 0;

};

#endif