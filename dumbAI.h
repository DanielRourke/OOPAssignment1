
#include "player.h"

class dumbAI : public player
{
    private:
    int ** state;
    public:
    dumbAI(int i, char s, int size, int rowSize) : Player(i,s) 
    {  
        name += " (dumbAI)";
        state = new int*[size];
        for (int i= 0 ; i < size; i++)
        {
            state[i] = new int[size];
        } 
    }
    Move getMove(Board * b, Move move)
    {


    }

};