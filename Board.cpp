#include "Board.h"

using namespace std;

Board::Board(int s = 3, int k = 3)
{
    size = s;
    winThreshold = k;
    movesRemaining = s * s;
    grid = new char*[size];

    for (int i= 0 ; i < size; i++)
    {
        grid[i] = new char[size];
    }

    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            grid[i][j] = ' ';
        }
    }

}

 Board::Board (const Board& oldBoard) : size(oldBoard.size), winThreshold(oldBoard.winThreshold), movesRemaining(oldBoard.movesRemaining)
 {
    grid = new char*[size];
    for (int i= 0 ; i < size; i++)
    {
        grid[i] = new char[size];
    }

    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            grid[i][j] = oldBoard.grid[i][j];
        }
    }

 }

void Board::printBoard()
{
    //top numbers
    cout << " ";
    for (int i = 0 ; i < size; i++)
    {
        cout << "  " ;
        if(i < 10)
        {
            cout << " ";
        }
        cout << i + 1 ;
    }
    //
    cout << endl ;

    //start next line 
     //draw top line
    cout << "  " << (char)201;

    for (int i = 0; i < size; i++)
    {
        cout << (char)205 << (char)205 << (char)205  ;
        if (i < size -1)
        {
            cout << (char)203 ;
        }
    }

    cout << (char)187;
    
    //draw line with board values
 
    for (int i = 0 ; i < size; i++)
    {
        cout << endl ;
        if(i < 9)
        {
            cout << " ";
        }
        
        cout << i + 1;

        for (int j = 0 ; j < size; j++)
        {
            cout << (char) 186 << " " << grid[i][j] << " " ;
        }

        cout << (char)186;

   //draw line in the middle

        if (i < size -1)
        {
        
             cout << endl << "  " << (char)204;
        
            for (int i = 0; i < size; i++)
            {
                cout << (char)205 <<(char)205 <<(char)205 ;
                if (i < size -1)
                {
                    cout  << (char)206;
                }
                else
                {
                    cout << (char)185;
                }
            }

        }
        
    }
    
    //draw last line
    cout << endl << "  " << (char)200;

    for (int i = 0; i < size; i++)
    {
        cout << (char)205 << (char)205 << (char)205 ;
        if (i < size -1)
        {
            cout << (char)202 ;
        }
    }
    cout << (char)188 << endl;
}

bool Board::isValidMove(int row, int col)
{
    if(( row < size && row >= 0 )   &&   ( col <= size && col >= 0 )  && grid[row][col] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Board::isValidMove(Move move)
{
    if(( move.x < size && move.x >= 0 )   &&   ( move.y <= size && move.y >= 0 )  && grid[move.x][move.y] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

 void Board::addMove(int x , int y, char c)
 {
     grid[x][y] = c;
     movesRemaining--;
 }

 void Board::addMove(Move move)
 {

     grid[move.x][move.y] = move.s;
     movesRemaining--;
 }
 int Board::countRow(int r, int c, int x, int y)
 {
    int count = 0;
    char symbol = grid[r][c];
    r = r + x;
    c = c + y;
  
    //count how many same symbols in a row
    while( (r > -1 && r < size && c > -1 && c < size ) && grid[r][c] == symbol)
    {
       
        r += x;
        c += y;
        count++;
      
    }
    return count;
 }
 int Board::countRow(Move move, int x, int y)
 {

    int count = 0;
    move.x = move.x + x;
    move.y = move.y + y;
  
    //count how many same symbols in a row
    while( (move.x > -1 && move.x < size && move.y > -1 && move.y < size ) && grid[move.x][move.y] == move.s)
    {
       
        move.x = move.x + x;
        move.y = move.y + y;
        count++;
      
    }
    return count;
 }

Status Board::isGameOver(int x, int y)
   {
    int rowCount = 0;
       
    for (int i = 1; i < 5; i++)
    {
        switch (i)
        {
            case 1: // count diagonal "\"
                rowCount = countRow(x,y,1,1) + countRow(x,y,-1,-1) + 1;
            break;
            case 2: // count diagonal"/"
                rowCount = countRow(x,y,-1,1) + countRow(x,y,1,-1) + 1;
            break;
            case 3:// count vertical "|"
                rowCount = countRow(x,y,+1,0) + countRow(x,y,-1,0) + 1;
            break;
            case 4:// count horizontal "--"
                rowCount = countRow(x,y,0,1) + countRow(x,y,0,-1) + 1 ;
            break;

   
        }
           
            if (rowCount >= winThreshold)
            {
                return WIN;
            }

            rowCount = 0;
  
    }
    if (movesRemaining == 0)
    {
        return DRAW;
    }

    return INCOMPLETE;
   }

  Status Board::isGameOver(Move move)
   {
    int rowCount = 0;
       
    for (int i = 1; i < 5; i++)
    {
        switch (i)
        {
            case 1: // count diagonal "\"
                rowCount = countRow(move,1,1) + countRow(move,-1,-1) + 1;
            break;
            case 2: // count diagonal"/"
                rowCount = countRow(move,-1,1) + countRow(move,1,-1) + 1;
            break;
            case 3:// count vertical "|"
                rowCount = countRow(move,+1,0) + countRow(move,-1,0) + 1;
            break;
            case 4:// count horizontal "--"
                rowCount = countRow(move,0,1) + countRow(move,0,-1) + 1 ;
            break;

   
        }
           
            if (rowCount >= winThreshold)
            {
                return WIN;
            }

            rowCount = 0;
  
    }
    if (movesRemaining == 0)
    {
        return DRAW;
    }

    return INCOMPLETE;
   }

    Move Board::increase(int x, int y, int c)
    {
        grid[x][y] += c;
        Move move(x, y,  grid[x][y]);
        return move;
    }



 Board::~Board()
 {
     for (int i = 0 ; i < size ; i++)
     {
         delete grid[i];
     }
     delete []  grid;
 }
