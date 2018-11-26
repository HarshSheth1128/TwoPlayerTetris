#ifndef __GAMEPLAYER_H__
#define __GAMEPLAYER_H__

#include "Player.h"

class GamePlayer{
    public:
    //GamePlayer::GamePlayer(xWindow &w);
    GamePlayer::~GamePlayer();
    std::vector<GridCell> getRow(int rowNum) override;
    int getLevel() override;
    int getScore() override;
    Block* getNextBlock() override;
    void setNextBlock(Block *) override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
    void rotate(std::string direction) override;
    void drop() override;
}
#endif
