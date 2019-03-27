// #include <string>
// #include "random.h"

//#include <iostream>

#include "weighted.h"
// using namespace std;

class MKgame
{
    private:
    Board gameBoard;
    Player ** players;
    int playerCount;
    Status gameStatus;
    Move currentMove;
    public:

    MKgame(int m , int k , int p) : gameBoard(m, k), currentMove()
    { 
        gameStatus = INCOMPLETE;
        playerCount = p;
        setPlayers();
        currentMove.s = players[0]->Symbol();
    }
    MKgame() : gameBoard(), currentMove()
    {
        gameStatus = INCOMPLETE;
        playerCount = 2;
        players = new Player*[playerCount];
    
         // players[1] = new Random(1, 'O');
        players[0] = new Human(0, 'X');
         players[1] = new minimaxAi(1,'O','X' );
        //players[1] = new Random(1, 'O');
      //  players[1] = new Weighted(1, 'O', gameBoard);
      //  players[1] = new minimaxAi(1, 'O','X' );
        currentMove.s = players[0]->Symbol();
    }
    ~MKgame()
    {   
        for (int i = 0 ; i < playerCount; i++)
        {
            delete players[i];
        }
       delete [] players;
    }
    int play()
    {
        int index = playerCount -1;
        while(gameStatus == INCOMPLETE)
        {
            index = (index + 1) % playerCount;
            gameBoard.printBoard();
            currentMove = players[index]->getMove(gameBoard, currentMove);
            gameBoard.addMove(currentMove);
            gameStatus = gameBoard.isGameOver(currentMove);
        
           // cout << gameStatus ;   
        }
        gameBoard.printBoard();

        if (gameStatus == WIN)
        {
            cout << players[index]->Name() << " Wins!!" << endl;
        }
        else if (gameStatus == DRAW)
        {
            cout << "Game is a Draw!" << endl;
        }
    }

    void setPlayers()
    {
        char symbol;
        string pType;
        players = new Player*[playerCount];
        for (int i = 0; i < playerCount; i++)
        {
            cout << "What type of player is player " << to_string(i) <<endl << "Human, Random, AI : " ;
            cin >> pType;
            cout << "Which symbol is to represent the player : ";
            cin >> symbol;
                    if (pType == "0" || pType =="Human")
                    {
                        players[i] = new Human(i, symbol);
                    }
                    else if(pType =="1" || pType =="Random")
                    {
                        players[i] = new Random(i, symbol);
                    }  
                    else if (pType =="2" || pType == "AI")
                    {
                        players[i] = new minimaxAi(i, symbol, players[(i - 1) % playerCount]->Symbol());
                         //players[i] = new minimaxAi(i, symbol, 'X');
                    }
                    else if (pType =="3" || pType == "DUMB")
                    {
                        players[i] = new Weighted( i, symbol, gameBoard);
                    }
                    
  
        }



    }
 
};