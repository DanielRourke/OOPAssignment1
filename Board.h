
#include "encaps.h"
#include <string>
#include <time.h>
#include <stdlib.h> 

class Board
{
    private:
    char** grid;
    int size;
    int winThreshold;
    int movesRemaining;


    public:
    Board(int,int);
    Board (const Board&);
    ~Board();
    void printBoard();
    bool isValidMove(int x, int y);
    bool isValidMove(Move);
    Status isGameOver(int, int);
    Status isGameOver(Move);
    void addMove(int x , int y, char c);
    void addMove(Move);
    int getSize() const {return size;} 
    int countRow(int,int,int,int);
    int countRow(Move,int, int);
    Move increase(int x, int y, int c);
    char retrieveSymbol(int x, int y) {return grid[x][y];}
};


