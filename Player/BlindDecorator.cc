#include <iostream>
#include <utility>
#include <stdexcept>
#include "BlindDecorator.h"
#include <memory>

BlindDecorator::BlindDecorator(Player *component): player{component}{}

BlindDecorator::~BlindDecorator(){
    delete player;
}

/*
std::vector<GridCell>* BlindDecorator::getRow(int rowNum){
    std::vector<GridCell> *origVec = player->getRow(rowNum);
    auto tmpVec = std::make_unique<std::vector<GridCell>>();
    for (int i = 0; i < player->getGridWidth(); i++){
        GridCell tmpCell = origVec->at(i);
        if ((rowNum >= 3) and (rowNum <= 12) and (i >= 3) and (i <= 9)){
            tmpCell.setType('?');
            tmpCell.isUsed = true;  
        }
        tmpVec->emplace_back(tmpCell);
    }
    return tmpVec;
}
*/

std::vector<GridCell>* BlindDecorator::getRow(int rowNum){
    return player->getRow(rowNum);
}

void BlindDecorator::printRow (int rowNum) {
    std::vector<GridCell> gridRow = *(player->getRow(rowNum));
    for (int i = 0; i < player->getGridWidth(); i++){
        if ((rowNum >= 6) and (rowNum <= 15) and (i >= 3) and (i <= 9)){
            std::cout << "?";
        }
        else{
            std::cout << gridRow.at(i);
        }
    }
}

void BlindDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool BlindDecorator::getPlayerId(){
    return player->getPlayerId();
}

int BlindDecorator::getLevel(){
    return player->getLevel();
}

int BlindDecorator::getScore(){
    return player->getScore();
}

char BlindDecorator::getNextBlock(){
    return player->getNextBlock();
}

void BlindDecorator::setNextBlock(){
    player->setNextBlock();
}

void BlindDecorator::moveLeft(){
    player->moveLeft();
}

void BlindDecorator::moveRight(){
    player->moveRight();
}

bool BlindDecorator::moveDown(){
    return player->moveDown();
}

void BlindDecorator::rotate(std::string direction){
    player->rotate(direction);
}

int BlindDecorator::drop(){
    return player->drop();
}

/*
void BlindDecorator::print(){
    player->print();
}
*/
