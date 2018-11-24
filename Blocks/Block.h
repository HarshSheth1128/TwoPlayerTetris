#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "vector"
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

class Block {
    std::vector<GridCell*> blockCells;
    Grid* grid;
    char type;
    public:
    Block(Grid* g, std::vector<GridCell*> cells, char type);
    ~Block();
    bool moveLeft();  
    bool moveRight();
    bool moveDown();
    void rotateCW();
    void rotateCCW();
    void drop();
};

#endif