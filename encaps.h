#include <iostream>
#include <vector>
using namespace std;

enum Status {INCOMPLETE, WIN, DRAW };

struct Move
{
    Move(char c, int score = 0) : x(0), y(0), s(c), score(score){}
    Move(int a = 0, int b = 0, char c = ' ') : x(a), y(b), s(c) ,score(0){}
    Move(const Move& move) : x(move.x), y(move.y), s(move.s), score(move.score) {}
    int x;
    int y;
    char s;
    int score;
};




struct Number
{
    int result;
    Number() : result(0) {}
    int getNumber(int min,int max)
    { 
        do
        {
            cin >> result;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invaliad Input";
                result = 0;
            }
        }
        while(result < min || result > max);

        return result;
    }
};



