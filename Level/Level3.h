#ifndef __LEVEL3_H__
#define __LEVEL3_H__

#include <iostream>
#include "../Blocks/Block.h"
#include <string>
#include "Level.h"

class Level3 : public Level{
    public:
    Level3(); //This Level also ads a heavy decorator
    ~Level3();
    Block* getNextBlock() override; //Returns an empty block with level char
};

#endif
