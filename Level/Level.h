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
    virtual Block* getNextBlock() = 0; //Returns an empty block with level char
    virtual int getScore(int linesCleared); //Returns score based on lines cleared
    int getLevel(); //Returns the current level
};

#endif
