#include <iostream>
#include <utility>
#include <stdexcept>
#include "LevelDecorator.h"

LevelDecorator::LevelDecorator(Player *component): player{component}{}

LevelDecorator::~LevelDecorator(){
     delete player;
}

std::vector<GridCell>* LevelDecorator::getRow(int rowNum){
     return player->getRow(rowNum);
}

bool LevelDecorator::getPlayerId(){
    return player->getPlayerId();
}

int LevelDecorator::getLevel(){
    return player->getLevel();
}

int LevelDecorator::getScore(){
    return player->getScore();
}

char LevelDecorator::getNextBlock(){
    return player->getNextBlock();
}

void LevelDecorator::setNextBlock(){
    player->setNextBlock();
}

void LevelDecorator::moveLeft(){
    player->moveLeft();
    if (playerId == playerOnePlaying){
        if (!player->moveDown()){
            player->drop();
            //playerOnePlaying = (!playerOnePlaying);
            return;
        }
    }
}

void LevelDecorator::moveRight(){
    player->moveRight();
    if (playerId == playerOnePlaying){
        if (!player->moveDown()){
            player->drop();
            //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
            return;
        }
    }
}

//This might be a problem: because right and left moves in heavydecorator are calling movedown. So reconsider
bool LevelDecorator::moveDown(){
    //bool lastMove = player->moveDown();
    player->moveDown();
    if (!player->moveDown()){
        player->drop();
            //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
            return false;
    }
    return true;
}


void LevelDecorator::rotate(std::string direction){
    player->rotate(direction);
    if (!player->moveDown()){
        player->drop();
        //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
        return;
    }
}

void LevelDecorator::printRow (int rowNum) {
    player->printRow(rowNum);
}

int LevelDecorator::drop(){
    return player->drop();
}

/*
void LevelDecorator::print(){
    player->print();
}
*/
