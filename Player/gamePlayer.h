#ifndef __GAMEPLAYER_H__
#define __GAMEPLAYER_H__

#include "Player.h"
#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class GamePlayer: public Player{
    int score;
    Grid *grid;
    Level *level;
    Block *nextBlock;
    Block *currBlock;
    std::vector<Block*> blocksOnBoard;
    void shiftCellsDown(int y);
    void removeEmptyBlocks();
    public:
    // xWindow *window;

    //GamePlayer::GamePlayer(xWindow &w);
    GamePlayer(Grid *grid);
    ~GamePlayer();
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
};
#endif
