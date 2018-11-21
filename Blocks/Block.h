#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "vector"
#include <iostream>
#include "GridCell.h"

class Block {
    protected:
    std::vector<GridCell*> blockCells;
    public:
    virtual ~Block() = 0;
    virtual void moveLeft() = 0;  
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
    virtual void rotateCW() = 0;
    virtual void rotateCCW() = 0;
    virtual void drop() = 0;
};

#endif
