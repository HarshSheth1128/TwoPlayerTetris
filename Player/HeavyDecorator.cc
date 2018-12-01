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

void HeavyDecorator::setNextBlock(){
    player->setNextBlock();
}

void HeavyDecorator::moveLeft(){
    player->moveLeft();
    if (player->getPlayerId() == player->isPlayerOnePlaying()){
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
    //std::cout << "at 1." << std::endl;
    if (player->getPlayerId() == player->isPlayerOnePlaying()){
      //  std::cout << "at 2." << std::endl;
        for (int i = 0; i < 2; i++){
        //    std::cout << "at 3." << std::endl;
            if (!player->moveDown()){
          //      std::cout << "dropping" << std::endl;
                player->drop();
                //playerOnePlaying = (!playerOnePlaying); //this should happen in GamePlayer::drop
                return;
            }
        }
    }
}

void HeavyDecorator::setNextBlockChar(char c){
    player->setNextBlockChar(c);
}

bool HeavyDecorator::moveDown(){
    return player->moveDown();
}

void HeavyDecorator::rotate(std::string direction){
    player->rotate(direction);
}

int HeavyDecorator::drop(){
    return player->drop();
}

/*
void HeavyDecorator::print(){
    player->print();
}
*/
