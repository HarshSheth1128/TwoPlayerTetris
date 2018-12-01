#include <iostream>
#include <utility>
#include <stdexcept>
#include "ForceDecorator.h"

ForceDecorator::ForceDecorator(Player *component): player{component}{}

ForceDecorator::~ForceDecorator(){
    delete player;
}


std::vector<GridCell>* ForceDecorator::getRow(int rowNum){
    return player->getRow(rowNum);
}


void ForceDecorator::printRow (int rowNum) {
    player->printRow(rowNum);
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

void ForceDecorator::setNextBlock(char b){
    player->setNextBlock(b);
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

void ForceDecorator::drop(){
    player->drop();
}

/*
void ForceDecorator::print(){
    player->print();
}
*/
