#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "vector"
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

class Block {
    protected:
    std::vector<GridCell*> blockCells;
    Grid* grid;
    char type;
    public:
    Block(Grid* g, std::vector<GridCell*> cells, char type);
    virtual ~Block() = 0;
    void moveLeft();  
    void moveRight();
    void moveDown();
    virtual void rotateCW() = 0;
    virtual void rotateCCW() = 0;
    virtual void drop() = 0;
};

#endif
