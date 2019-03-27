//
// #include "player.h"
#include "random.h"
///two player only
class minimaxAi : public Player
{
    private:
    char oppentSymbol;
    int depth;
    public:
    minimaxAi(int i, char s, char o) : Player(i,s) , oppentSymbol(o){ name += " (miniMax)";}
    void getMove(Board * b, int& x ,int& y)
    {
        // Board simBoard(b);
        // return simAiMove(simBoard, move)

    }
//    Move simAiMove(Board simBoard, Move lastMove)  
   Move getMove(Board simBoard, Move lastMove)
   {
      // simBoard.printBoard();
      depth = 0;
       return getAIMove(simBoard, lastMove);
   }



   Move getAIMove(Board simBoard, Move lastMove)
    {
        //cout << lastMove.x << " " << lastMove.y<< " "  << lastMove.s<< " "  << lastMove.score << " " << endl;
      
        simBoard.addMove(lastMove);
       // cout << "SIMULATIONS "<< endl;
       // simBoard.printBoard();
      //  cout << "__________"<< lastMove.x << " " << lastMove.y<< " " << lastMove.score << endl;
        Status simStatus = simBoard.isGameOver(lastMove);
        
        if(simStatus == WIN)
        {
            if(lastMove.s == playerSymbol)
            {
                
               // lastMove.score = 10;
               Move retmove(lastMove.s ,10 - depth);
              //  cout << retmove.score << endl;
                return retmove;
            }
            else if (lastMove.s == oppentSymbol)
            {
            //     lastMove.score = -10;
            //    // cout <<"score"<<  lastMove.score<< endl;
            //     return lastMove;
               Move retmove(lastMove.s ,depth - 10);
              //  cout << retmove.score << endl;
          
                return retmove;
            }
        }
        else if(simStatus == DRAW)
        {
            // lastMove.score = 0;
            // return lastMove;
               Move retmove(lastMove.s ,0);
          //      cout << retmove.score << endl;
              //  cout <<"score"<<  lastMove.score<< endl;
              return retmove;
        }


        //switch players
        if(lastMove.s == playerSymbol)
        {
            lastMove.s = oppentSymbol;
        }
        else if(lastMove.s == oppentSymbol)
        {
            lastMove.s = playerSymbol ;
        }
        
        vector<Move> possibleMove;
        depth++;
        for (int x = 0 ; x < simBoard.getSize(); x++)
        {
            for (int y = 0 ; y < simBoard.getSize(); y++)
            {
                if (simBoard.isValidMove(x, y))
                {
                    Move newMove(lastMove.s);
                    newMove.x = x;
                    newMove.y = y;

                   newMove.score = getAIMove(simBoard, newMove).score;
                      //  cout<< "returned score" << getAIMove(simBoard, newMove).score <<endl;
                   // cout<< "returned score" << newMove.score <<endl;
                    possibleMove.push_back(newMove);
                }
            }
        }

        int moveIndex = 0;
       
        if(lastMove.s == playerSymbol)
        {
            int highestScore = -100;
            for (int i = 0; i < possibleMove.size(); i ++)
            {
                if (possibleMove[i].score > highestScore )
                {
                    highestScore = possibleMove[i].score;
                 //   cout << possibleMove[i].score << endl;
                    moveIndex = i;
                }
            }
       
        }
        else if(lastMove.s == oppentSymbol)
        {
            int lowestScore = 100;
            for (int i = 0; i < possibleMove.size(); i ++)
            {
                if (possibleMove[i].score < lowestScore )
                {
                    lowestScore = possibleMove[i].score;
        
                    moveIndex = i;
                }
            }
             
        }
        depth = 0;
      //  cout << name << "  move : " << possibleMove[moveIndex].x << " " << possibleMove[moveIndex].y << " With a score of " << possibleMove[moveIndex].score << " symbols" << depth <<endl;
         return possibleMove[moveIndex];

    }


} ;


    // simulateMove(Board SimBoard, int r, int c , int index , int& winCount, int& drawCount, int& lossCount)
    // {
    //     simBoard.addMove(r,c, players[index]);
    //     index = (index + 2) % 0
    //     Move simMove(players[index]);
    //     int size = simBoard.getSize();
    //     //shortest move 


    //     for (int x = 0 ; x < size; x++)
    //     {
    //         for (int y = 0 ; y < size ; y++)
    //         {
    //             if (isValidMove(x, y))
    //             {
    //                 simMove.x = x;
    //                 simMove.y = y;
    //                swtich (isGameOver(move))
    //                {
    //                    case ("WIN")
    //                    {
    //                        winCount++;
    //                        break;
    //                    }
    //                    case ("DRAW")
    //                    {
    //                        drawCount++;
    //                        break;
    //                    }
    //                    case ("INCOMPLETE")
    //                    {
    //                         simulateMove(simBoard, x, y, index, lossCount, drawCount, winCount);
    //                    }
                       
    //                }
                    
    //             }
    //         }
    //     }



        
    // simulateMove(Board SimBoard, int r, int c , int index , int& winCount, int& drawCount, int& lossCount)
    // {
    //     simBoard.addMove(r,c, players[index]);
    //     index = (index + 2) % 0
    //     Move simMove(players[index]);
    //     int size = simBoard.getSize();
    //     //shortest move 


    //     swtich (isGameOver(move))
    //                {
    //                    case ("WIN")
    //                    {
    //                        winCount++;
    //                        break;
    //                    }
    //                    case ("DRAW")
    //                    {
    //                        drawCount++;
    //                        break;
    //                    }
    //                    case ("INCOMPLETE")
    //                    {
    //                         simulateMove(simBoard, x, y, index, lossCount, drawCount, winCount);
    //                    }



    //     for (int x = 0 ; x < size; x++)
    //     {
    //         for (int y = 0 ; y < size ; y++)
    //         {
    //             if (isValidMove(x, y))
    //             {
    //                 simMove.x = x;
    //                 simMove.y = y;
                   
                       
    //                }
                    
    //             }
    //         }
    //     }




    //     //for PLayerx playery




    //     //status check x y 
    //         //check move win
    //         //if win or draw return Win  or draw
            
    //         //incomlepte
            
    //         //for openent oppent

    //             //check all oppent moves
    //             // how many loss
    //             // how many draw
    //             //return loss or Draw

                

    //             // incomplete   check all moves xy 


    //         // all aviable moves

    //             //status check x y
    //             //if win add to wins
    //             // of draw 
    //             // incomple add to movecount and check player x y

    //             /*


    //          Status       check if ai makes moves and wins

                
               



    //                 for (int x = 0 ; x < 3; x++)
    //                 {
    //                     for (int y= 0 ; y < 3; y++)
    //                     {
    //                         if valid move
    //                         check move for win
    //                         if move win
    //                             return win;
    //                             if draw return draw

    //                   return   = status   if incomplete check if oppentwins
    //                             {
    //                                  for (int x = 0 ; x < 3; x++)
    //                                     {
    //                                         for (int y= 0 ; y < 3; y++)
    //                                         {
                                                
    //                                             if is valid move
    //                                                   check move for win
    //                                                     if move win
    //                                                      return win;
    //                                                     if draw return draw

    //                                                return  = status 
    //                                                  if incomplete check if oppentwins
                                                
    //                             }
    //                     }
    //                 }












    //                 for (int x = 0 ; x < 3; x++)
    //                 {
    //                     for (int y= 0 ; y < 3; y++)
    //                     {
    //                         if valid move

    //                         check move for win
    //                         if move win
    //                             return win;
    //                     }
    //                 }




    //             */

    //            /*

    //             grid 

    //                 move 3 1 2 
    //                      0 x 2 
    //                      2 x x



    //            */














    // }