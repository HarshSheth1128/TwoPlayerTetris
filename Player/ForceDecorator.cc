#include <iostream>
#include <utility>
#include <stdexcept>
#include "ForceDecorator.h"

ForceDecorator::ForceDecorator(Player *component, char type): player{component}, blockType{type}{}

ForceDecorator::~ForceDecorator(){
    delete player;
}

std::vector<GridCell>* ForceDecorator::getRow(int rowNum){
    return player->getRow(rowNum);
}

void ForceDecorator::printRow (int rowNum) {
    player->printRow(rowNum);
}

void ForceDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool ForceDecorator::getPlayerId(){
    return player->getPlayerId();
}

int ForceDecorator::getLevel(){
    return player->getLevel();
}

int ForceDecorator::getScore(){
    return player->getScore();
}

char ForceDecorator::getNextBlock(){
    return player->getNextBlock();
}

void ForceDecorator::setNextBlock(){
    player->setNextBlockChar(this->blockType);
    player->setNextBlock();
}

void ForceDecorator::moveLeft(){
    player->moveLeft();
}

void ForceDecorator::moveRight(){
    player->moveRight();
}

bool ForceDecorator::moveDown(){
    return player->moveDown();
}

void ForceDecorator::rotate(std::string direction){
    player->rotate(direction);
}

int ForceDecorator::drop(){
    return player->drop();
}

/*
void ForceDecorator::print(){
    player->print();
}
*/
