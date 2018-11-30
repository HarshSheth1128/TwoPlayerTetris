#ifndef _BLINDDECORATOR_H_
#define _BLINDDECORATOR_H_

#include "Player.h"
#include "EffectsDecorator.h"
#include <vector>
#include <string>

class BlindDecorator: public EffectsDecorator{
    Player *player;
    
    public:
    BlindDecorator(Player *component);
    ~BlindDecorator() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    void printRow (int rowNum) override;
    bool getPlayerId() override;
    int getLevel() override;
    int getScore() override;
    char getNextBlock() override;
    void setNextBlock(char b) override;
    void moveLeft()override;
    void moveRight()override;
    bool moveDown()override;
    void rotate(std::string direction)override;
    void drop() override;
    //void print() override;
};


#endif