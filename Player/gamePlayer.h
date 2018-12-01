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
    // xWindow *window;

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
    void setNextBlockChar(char c) override;
    void setNextBlock() override;
    void moveLeft(int times) override;
    void moveRight(int times) override;
    bool moveDown(int times) override;
    void rotate(std::string direction, int times) override;
    void levelUp() override;
    void levelDown() override;
    int drop(int times) override;
    void noRandom(std::string sequencefile) override;
    void random() override;
    void printBlock() override;
    //void print() override; 
    //void addBlockOnBoard(Block *b) override;
};
#endif
