#include "Player/Player.h"
#include "Player/gamePlayer.h"
#include "Blocks/OBlock.h"
#include "Blocks/JBlock.h"
#include "Blocks/IBlock.h"
#include "Blocks/SBlock.h"
#include "Blocks/ZBlock.h"
#include "Blocks/TBlock.h"
#include "Blocks/LBlock.h"
#include "Level/Level.h"
#include "Level/Level0.h"
#include "Level/Level1.h"
#include "Level/Level2.h"
#include "Level/Level3.h"
#include "Level/Level4.h"
#include <sstream>
#include <string>


void printPlayers(Player *p1, Player *p2){

}

Level* getLevel(){
    #if startlevel == 0
    #ifdef scriptfile1
        return new Level0("scriptfile1");
    #endif
        return new Level0("sequence1.txt");
    #ifdef scriptfile2
        return new Level0("scriptfile2");
    #endif
        return new Level0("sequence2.txt");
    #elif startlevel == 1 
    return new Level1;
    #elif startlevel == 2 
    return new Level2;
    #elif startlevel == 3 
    return new Level3;
    #elif startlevel == 4 
    return new Level4;
    #endif
}

//GAME LOOP
int main(){
    Grid *g = new Grid();
    Level *l = getLevel();
    Player *p1 = new GamePlayer(g,l);
    Player *p2 = new GamePlayer(g,l);
    Player *activePlayer = new GamePlayer(g,l);
}
