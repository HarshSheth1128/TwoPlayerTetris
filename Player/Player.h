#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Grid/Grid.h"
#include "../Blocks/Block.h"
#include "../Level/Level.h"

class Player{
    // xWindow *window;
    protected:
    int score;
    Grid *grid;
    Level *level;
    char nextBlock;
    Block *currBlock = nullptr;
    bool playerId;
    static bool playerOnePlaying;
    
    public:
    virtual ~Player() = 0;
    Player(Grid* grid, Level *level, bool id);
    Player();
    virtual std::vector<GridCell>* getRow(int rowNum) = 0;
    virtual void printRow (int rowNum) = 0;
    virtual bool getPlayerId() = 0;
    //virtual Player* getBasePlayer() = 0;
    bool isPlayerOnePlaying();
    int getGridWidth();
    int getGridHeight();
    virtual int getLevel() = 0;
    virtual int getScore() = 0;
    virtual char getNextBlock() = 0;
    virtual void setNextBlock() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual bool moveDown() = 0;
    virtual void rotate(std::string direction) = 0;
    virtual int drop() = 0;
    //virtual void print() = 0;
    //virtual void addBlockOnBoard(Block *b) = 0;
};

#endif