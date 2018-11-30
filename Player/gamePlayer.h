#ifndef __GAMEPLAYER_H__
#define __GAMEPLAYER_H__

#include "Player.h"
#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class GamePlayer: public Player{
    std::vector<Block*> blocksOnBoard;
    void shiftCellsDown(int y);
    void removeEmptyBlocks();

    public:
    //GamePlayer::GamePlayer(xWindow &w);
    GamePlayer(Grid *grid, Level *level, bool id);
    ~GamePlayer();
    bool getPlayerId() override;
    //Player* getBasePlayer() override;
    std::vector<GridCell>* getRow(int rowNum) override;
    void printRow (int rowNum) override;
    int getLevel() override;
    int getScore() override;
    char getNextBlock() override;
    void setNextBlock(char b) override;
    void moveLeft() override;
    void moveRight() override;
    bool moveDown() override;
    void rotate(std::string direction) override;
    void drop() override;
    //void print() override; 
    //void addBlockOnBoard(Block *b) override;
};
#endif
