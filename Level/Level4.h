#ifndef __LEVEL4_H__
#define __LEVEL4_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level4 : public Level{
    int numBlocksSinceClear = 0; //How many blocks have been placed sinced cleared
    Grid *g; //Reference to the grid to place a * cell
    public:
    Level4(Grid* g); //This Level also adds a random cell in the middle of the board
                     //and also makes generated blocks heavy.
    ~Level4();
    char getNextBlock() override; //Returns a char
    int getScore(int linesCleared) override; //Sets numBlocksSinceClear to 0 and calculates score
};

#endif
