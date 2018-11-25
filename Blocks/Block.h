#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <vector>   //why "" not <>
#include <iostream>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"

class Block {
    std::vector<GridCell*> blockCells;
    Grid *grid;
    char type;
    std::vector<int> xCoords;
    std::vector<int> yCoords;
    std::pair<int, int> origBottomLeft;
    std::pair<int, int> topLeft;
    std::pair<int, int> newBottomLeft; 
    void shiftCoordinates (std::vector<int> &, int shift);

    public:
    Block(Grid* g, std::vector<GridCell*> cells, char type);
    ~Block();
    bool moveLeft();  
    bool moveRight();
    bool moveDown();
    void rotate(std::string direction);
    void drop();
};

#endif
