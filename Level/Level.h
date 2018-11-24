#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <fstream>

class Level{
    int level = -1; //Level of the subclass
    public:
    Level(int level);
    ~Level();
    virtual Block* getNextBlock() = 0;
    int getScore(int linesCleared);
    int getLevel();
};

#endif
