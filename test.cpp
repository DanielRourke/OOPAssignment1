
#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std;


void f1()
{
    int x;
    x = rand() % 100;
    cout << x << std::endl;
    x = rand() % 100;
    cout << x << std::endl;
}
void f2()
{
    int x;
    x = rand() % 100;
    cout << x << std::endl;
      x = rand() % 100;
    cout << x << std::endl;
}

int main()
{
   int x =0;

    srand(1);

    f1();
    f2();


    srand(1);
    x = rand() % 100;
    cout << x << std::endl;
    x = rand() % 100;
    cout << x << std::endl;
        x = rand() % 100;
    cout << x << std::endl;
    x = rand() % 100;
    cout << x << std::endl;

       srand(2);

    x = rand() % 100;
    cout << x << std::endl;
    x = rand() % 100;
    cout << x << std::endl;



    srand(time(NULL));

    x = rand() % 100;
    cout << x << std::endl;
      x = rand() % 100;
    cout << x << std::endl;
    
    return 0;
}