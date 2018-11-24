#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level1 : public Level{
    public:
    Level1();
    ~Level1();
    Block* getNextBlock() override; //Returns an empty block with level char
};

#endif
