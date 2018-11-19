#ifndef __GRIDCELL_H__
#define __GRIDCELL_H__

#include <iostream>
#include "vector"
#include "GridCell.h"
#include <map>
#include "string.h"

class GridCell{
    std::map<std::string, GridCell*> neighbours;
    bool isUsed;
    int x,y;
    char cellChar;
};

#endif