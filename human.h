 #include"Player.h"
// #include "Board.h"
//#include <iostream>

using namespace std;

class Human : public Player
{
    public:
    Human(int i, char s) : Player(i,s)  {name += " (Human)";}
    void getMove(Board * b, int& x ,int& y)
    {
        do
        {
            cout << name << "  move : ";
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }

           cin >> x >> y ;
            x--;
            y--;
        }
        while (cin.fail() || !(b->isValidMove(x , y )));
    }
    Move getMove(Board b, Move move)
    {
        int x, y;
        //Move move(playerSymbol);
        move.s = playerSymbol;
        do
        {
            cout << name << "  move : ";
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }

           cin >> x >> y ;
            move.x = x -1;
            move.y = y -1;
           
        }
        while (cin.fail() || !(b.isValidMove(move)));
        return move;
    }





};