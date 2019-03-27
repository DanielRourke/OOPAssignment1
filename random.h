// #include <time.h>
// #include <stdlib.h> 
#include "Human.h"
// #include "Player.h"
// #include "Board.h"


class Random : public Player
{
    
    public:
    Random(int i, char s) : Player(i,s) { name += " (Random)";}
   
     void getMove(Board * b, int& x ,int& y)
      {
        do
        {  
            x = rand() % b->getSize();
            y = rand() % b->getSize();
        }
          while(!(b->isValidMove(x , y )));

          cout << name << "  move : " << x << " " << y << endl;

      }
       Move getMove(Board b, Move move)
      {
        move.s = playerSymbol;
        do
        {  
            move.x = rand() % b.getSize();
            move.y = rand() % b.getSize();
        }
          while(!(b.isValidMove(move)));

          cout << name << "  move : " << move.x << " " << move.y << endl;
        return move;
      }
};