#include "Block.h"
#include <algorithm>

Block::Block(Grid* g, std::vector<GridCell*> cells, char c):grid(g),blockCells(cells),type(c){
    //Set the character type for all cells that this block occupies
    for(auto i: blockCells){
        i->setType(type);
    }
}

Block::~Block(){}

//Struct that holds an operator to compare cell X values
struct CompareX {
    bool const operator()(GridCell* c1, GridCell* c2) {
        return (c1->getX()<c2->getX());
    } 
};

//Struct that holds an operator to compare cell Y values
struct CompareY {
    bool const operator()(GridCell* c1, GridCell* c2) {
        return (c1->getY()<c2->getY());
    } 
};

// Function that is responsible for moving the cell left
bool Block::moveLeft(){
    //We check to see that the block is not obstructed by a wall or a cell
    for(auto i: blockCells){
        if(i->getX() == 0 || i->getNeighbour("left")->isUsed){
            if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("left")) == blockCells.end()){
                return false;
            }
        }
    }
    //We sort the cells by their x values
    std::sort(blockCells.begin(), blockCells.end(), CompareX());
    char c = blockCells.at(0)->getType();
    //We go through the cells and change their pointers to new cells
    for(int i = 0; i < blockCells.size(); i++){
        blockCells.at(i)->isUsed = false;
        blockCells.at(i)->setType(' ');
        blockCells.at(i) = blockCells.at(i)->getNeighbour("left");
        blockCells.at(i)->setType(c);
        blockCells.at(i)->isUsed = true;
    }
    return true;
}

// Function that is responsible for moving the cell right
bool Block::moveRight(){
    //We check to see that the block is not obstructed by a wall or a cell
    for(auto i: blockCells){
        if(i->getX() == 10 || i->getNeighbour("right")->isUsed){
            if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("right")) == blockCells.end()){
                return false;
            }
        }
    }
    //We sort the cells by their x values
    std::sort(blockCells.begin(), blockCells.end(), CompareX());
    char c = blockCells.at(0)->getType();
    //We go through the cells and change their pointers to new cells
    for(int i = blockCells.size()-1; i >= 0; i--){
        blockCells.at(i)->isUsed = false;
        blockCells.at(i)->setType(' ');
        blockCells.at(i) = blockCells.at(i)->getNeighbour("right");
        blockCells.at(i)->setType(c);
        blockCells.at(i)->isUsed = true;
    }
    return true;
}

// Function that is responsible for moving the cell right
bool Block::moveDown(){
    //We check to see that the block is not obstructed by a wall or a cell
    for(auto i: blockCells){
        if(i->getY() == 17 || i->getNeighbour("bottom")->isUsed){
            if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("bottom")) == blockCells.end()){
                return false;
            }
        }
    }
    //We sort the cells by their y values
    std::sort(blockCells.begin(), blockCells.end(), CompareY());
    char c = blockCells.at(0)->getType();
    //We go through the cells and change their pointers to new cells
    for(int i = blockCells.size()-1; i >= 0; i--){
        blockCells.at(i)->isUsed = false;
        blockCells.at(i)->setType(' ');
        blockCells.at(i) = blockCells.at(i)->getNeighbour("bottom");
        blockCells.at(i)->setType(c);
        blockCells.at(i)->isUsed = true;
    }
    return true;
}

void rotateCW(){

}

void rotateCCW(){

}

void drop(){

}