#ifndef _LEVELDECORATOR_H_
#define _LEVELDECORATOR_H_

#include "Player.h"
#include "EffectsDecorator.h"
#include <vector>
#include <string>

class LevelDecorator: public EffectsDecorator{
    Player *player;
    
    public:
    LevelDecorator(Player *component);
    ~LevelDecorator() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    void printRow (int rowNum) override;
    bool getPlayerId() override;
    int getLevel() override;
    int getScore() override;
    void setNextBlockChar(char c) override;
    char getNextBlock() override;
    void setNextBlock() override;
    void moveLeft()override;
    void moveRight()override;
    bool moveDown()override;
    void rotate(std::string direction)override;
    int drop() override;
    //void print() override;
};

#endif