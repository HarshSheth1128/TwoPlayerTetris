#include "Level2.h"
#include <stdlib.h>
#include <vector>
#include "../Grid/GridCell.h"

Level2::Level2():Level(2){}

Level2::~Level2(){}

Block* Level2::getNextBlock(){
    char blockChar;
    int random = rand() % 7;
    //We generate a number from 0-6, 
    //then we assign a character to each number
    if(random == 0){blockChar = 'S';}
    else if (random == 1){blockChar = 'Z';}
    else if (random == 2){blockChar = 'T';}
    else if (random == 3){blockChar = 'J';}
    else if (random == 4){blockChar = 'L';}
    else if (random == 5){blockChar = 'O';}
    else if (random == 6){blockChar = 'I';}
    std::vector<GridCell*> retVec;
    return new Block(nullptr, retVec, blockChar);  
}