

//#include "Board.cpp"
#include "MKgame.h"
/* TO DO????????
add move class to board
add smarter Ai
set up typecasting

 */
int main()
{
    srand(time(NULL));
    int m , k, p , gameType;
    Number input;

    cout << "Game : Type 0 for quick game OR 1 from custom game : " ;
    gameType = input.getNumber(0,1);
    if (gameType == 1)
    {
        cout << "Please enter Board size between 2 and 20 : ";
        m = input.getNumber(2,20);
      
        cout << "Enter Win threshold : ";
        k = input.getNumber(1, m);
        
        cout << "Enter numer of players : ";
        p = input.getNumber(1,4);
       
        MKgame custom(m,k,p);
        custom.play();
    }
    else
    {
        MKgame game;
        game.play();
    }    
    return 0;
}