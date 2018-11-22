#include "Block.h"
#include <algorithm>

Block::Block(Grid* g, std::vector<GridCell*> cells, char c):grid(g),blockCells(cells),type(c){
    for(auto i: blockCells){
        i->setType(type);
    }
}

Block::~Block(){}

struct CompareX {
    bool const operator()(GridCell* c1, GridCell* c2) {
        return (c1->getX()<c2->getX());
    } 
};

struct CompareY {
    bool const operator()(GridCell* c1, GridCell* c2) {
        return (c1->getY()<c2->getY());
    } 
};

void Block::moveLeft(){
    for(auto i: blockCells){
        if(i->getX() == 0 || i->getNeighbour("left")->isUsed){
            if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("left")) == blockCells.end()){
                return;
            }
        }
    }
    std::sort(blockCells.begin(), blockCells.end(), CompareX());
    char c = blockCells.at(0)->getType();
    for(int i = 0; i < blockCells.size(); i++){
        blockCells.at(i)->isUsed = false;
        blockCells.at(i)->setType(' ');
        blockCells.at(i) = blockCells.at(i)->getNeighbour("left");
        blockCells.at(i)->setType(c);
        blockCells.at(i)->isUsed = true;
    }
}

void Block::moveRight(){
    for(auto i: blockCells){
        if(i->getX() == 10 || i->getNeighbour("right")->isUsed){
            if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("right")) == blockCells.end()){
                return;
            }
        }
    }
    std::sort(blockCells.begin(), blockCells.end(), CompareX());
    char c = blockCells.at(0)->getType();
    for(int i = blockCells.size()-1; i >= 0; i--){
        blockCells.at(i)->isUsed = false;
        blockCells.at(i)->setType(' ');
        blockCells.at(i) = blockCells.at(i)->getNeighbour("right");
        blockCells.at(i)->setType(c);
        blockCells.at(i)->isUsed = true;
    }
}

void Block::moveDown(){
    for(auto i: blockCells){
        if(i->getY() == 17 || i->getNeighbour("bottom")->isUsed){
            if(std::find(blockCells.begin(), blockCells.end(), i->getNeighbour("bottom")) == blockCells.end()){
                return;
            }
        }
    }
    std::sort(blockCells.begin(), blockCells.end(), CompareY());
    char c = blockCells.at(0)->getType();
    for(int i = blockCells.size()-1; i >= 0; i--){
        blockCells.at(i)->isUsed = false;
        blockCells.at(i)->setType(' ');
        blockCells.at(i) = blockCells.at(i)->getNeighbour("bottom");
        blockCells.at(i)->setType(c);
        blockCells.at(i)->isUsed = true;
    }
}

void rotateCW(){

}

void rotateCCW(){

}

void drop(){

}