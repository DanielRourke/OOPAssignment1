



#include "fullTreeAI.h"
class Weighted : public Player
{
    private:
    
    public:
    Board weights;
    Weighted(int i, char s, Board b) : Player(i,s) ,weights(b) {
         name += " (weighted)";
         
        // for(int x = 0 ; x < weights.getSize(); x++)
        // {
        //     for(int y = 0 ; y < weights.getSize(); y++)
        //     { 
        //         if (x  < 1)
        //     }
        // } 
         
         }
    void getMove(Board * b, int& x ,int& y)
    {

    }
 
   Move getMove(Board simBoard, Move lastMove)
   {
cout << " 0";
    //    for(int x = 0 ; x < weights.getSize(); x++)
    //     {
    //         for(int y = 0 ; y < weights.getSize(); y++)
    //         {  
        int x = lastMove.x;
        int y = lastMove.y;
                
                cout << " 2";
                add(x, y, 0, 1, simBoard );
                 add(x,y, 0 ,-1, simBoard);
                add(x,y, -1, 0, simBoard);
                cout << " 1";
                add(x, y, 1, 0, simBoard);
                add(x, y, 1, -1, simBoard);
                add(x, y, -1, -1, simBoard);
                add(x, y, 1 ,1, simBoard);
                add(x, y, -1 ,1, simBoard);
               
        //     }
        //  }
            Move best(' ');
            best.x = rand() % simBoard.getSize();
            best.y = rand() % simBoard.getSize();

        cout << " 3";
        for(int x = 0 ; x < weights.getSize(); x++)
        {
            for(int y = 0 ; y < weights.getSize(); y++)
            {
                if (simBoard.retrieveSymbol(x, y) > best.s && simBoard.isValidMove(x,y))
                {
                    best.x = x;
                    best.y = y;
                    cout << x << y;
                }
            }
        }

        cout << " selected " << best.x << best.y;
        weights.addMove(best);
        best.s = playerSymbol;
       // weights.printBoard();
       
       simBoard.printBoard();
        return best;
    }

    void add(int r, int c, int x, int y, Board b)
    {
        int count = 0;
        char symbol = b.retrieveSymbol(r, c);
        r = r + x;
        c = c + y;
        //count how many same symbols in a row
        while( (r > -1 && r < b.getSize() && c > -1 && c < b.getSize() ))
        {
            cout << " 0";
            if (b.isValidMove(r,c))
            {
                weights.increase( r, c, count);
            }
            else if (b.retrieveSymbol(r, c) == symbol)
            {
                // r += x;
                // c += y;
                count++;
            }
            else 
            {
                break;
            }

                r += x;
                c += y;
        }
    }

 };
   