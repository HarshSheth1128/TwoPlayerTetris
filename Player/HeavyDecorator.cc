#include <iostream>
#include <utility>
#include <stdexcept>
#include "HeavyDecorator.h"

HeavyDecorator::HeavyDecorator(Player *component): player{component}{}

HeavyDecorator::~HeavyDecorator(){
     delete player;
}

std::vector<GridCell>* HeavyDecorator::getRow(int rowNum){
     return player->getRow(rowNum);
}


void HeavyDecorator::printRow (int rowNum) {
    player->printRow(rowNum);
}

bool HeavyDecorator::getPlayerId(){
    return player->getPlayerId();
}

int HeavyDecorator::getLevel(){
    return player->getLevel();
}

int HeavyDecorator::getScore(){
    return player->getScore();
}

char HeavyDecorator::getNextBlock(){
    return player->getNextBlock();
}

void HeavyDecorator::setNextBlock(char b){
    player->setNextBlock(b);
}

void HeavyDecorator::moveLeft(){
    player->moveLeft();
    if (playerId == playerOnePlaying){
        for (int i = 0; i < 2; i++){
            if (!player->moveDown()){
                player->drop();
                //playerOnePlaying = (!playerOnePlaying);
                return;
            }
        }
    }
}

void HeavyDecorator::moveRight(){
    player->moveRight();
    if (playerId == playerOnePlaying){
        for (int i = 0; i < 2; i++){
            if (!player->moveDown()){
                player->drop();
                //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
                return;
            }
        }
    }
}

bool HeavyDecorator::moveDown(){
    return player->moveDown();
}

void HeavyDecorator::rotate(std::string direction){
    player->rotate(direction);
}

void HeavyDecorator::drop(){
    player->drop();
}

/*
void HeavyDecorator::print(){
    player->print();
}
*/
