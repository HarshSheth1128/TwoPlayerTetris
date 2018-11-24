#ifndef __LEVEL2_H__
#define __LEVEL2_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level2 : public Level{
    public:
    Level2();
    ~Level2();
    Block* getNextBlock() override; //Returns an empty block with level char
};

#endif
