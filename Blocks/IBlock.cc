#include "IBlock.h"
#include <vector>
#include "../Grid/GridCell.h"
#include "../Grid/Grid.h"
IBlock::IBlock(Grid *g): Block(g, 'I'){
    std::vector<GridCell*> tmp;
    tmp.emplace_back(g->getGridCell(0,3));
    tmp.emplace_back(g->getGridCell(1,3));
    tmp.emplace_back(g->getGridCell(2,3));
    tmp.emplace_back(g->getGridCell(3,3));
    for (auto i : tmp){
        if (i->isUsed){
            throw std::exception();
        }
    }
    blockCells = tmp;
    setUpBlock();
}

IBlock::~IBlock(){}

<<<<<<< HEAD
=======
/*

int main(){
    Grid* g = new Grid();
    Block* s = new IBlock(g);
    //s->rotate("CW");
    //for(int i = 0; i < 10; i++){
      //  s->moveRight();
    //}
    GridCell *gc = g->getGridCell(10, 5);
    gc->setType('c');
    gc->isUsed = true;
    while(s->moveRight());

    s->rotate("CW");
    
    s->moveRight();
    s->moveRight();
    s->moveRight();
    s->moveRight();
    
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 11; j++){
            std::cout << *(g->getGridCell(j,i));
        }
        std::cout << std::endl;
    }
    /*
    s->moveRight();
    s->moveRight();
    s->rotate("CW");
    s->moveRight();
    s->moveRight();
    s->moveRight();
    s->moveRight();
    while(s->moveRight());
    Block* s2 = new IBlock(g);
    s2->moveDown();
    s2->moveDown();
    s2->moveDown();
    s2->moveDown();
    s2->rotate("CW");
    while(s2->moveRight());
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 11; j++){
            std::cout << *(g->getGridCell(j,i));
        }
        std::cout << std::endl;
    }
    */
 
    //Block* s2 = new IBlock(g);
    
    //s2->moveDown();
    /*
    s2->moveDown();
    s2->moveDown();
    s2->moveDown();
    s2->moveDown();
    s2->moveDown();
    while(s2->moveRight());
    s2->rotate("CW");
    s2->moveRight();
    */
    //s2->moveDown();
    //s2->moveRight();
    //s2->moveRight();
    //s2->moveRight();
    //while(s2->moveLeft());
    //s2->rotate("CW");
    //s2->moveRight();
   // s2->moveRight();
    //s2->moveRight();
//}

>>>>>>> PlayerDecorator__Anjali
