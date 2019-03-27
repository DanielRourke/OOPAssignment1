// #include <string>
#include "Board.cpp"
             
class Player
{
    protected:
    char playerSymbol;
    std::string name;
    public:
    Player() : name("Blank Player"), playerSymbol(' ') {}
    Player(int i, char s, string n = "Player") : name(n + to_string(i+1)) , playerSymbol(s){}
    virtual Move getMove(Board b, Move) =0;
    virtual void getMove(Board * b, int& x, int& y ) =0;
    char Symbol()
    {
        return playerSymbol;
    }
    string Name() { return name; }


};