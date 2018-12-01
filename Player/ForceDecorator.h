#ifndef _FORCEDECORATOR_H_
#define _FORCEDECORATOR_H_

#include "Player.h"
#include "EffectsDecorator.h"
#include <vector>
#include <string>

class ForceDecorator: public EffectsDecorator{
    Player *player;
    
    public:
    ForceDecorator(Player *component);
    ~ForceDecorator() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    void printRow (int rowNum) override;
    bool getPlayerId() override;
    int getLevel() override;
    int getScore() override;
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