#include "gameloop.h"

int main()
{
    gameloop* G = new gameloop;

    G->init();

    while (G->run())
    {
        // break on draw or win
    }


    std::cout << "\n\n\tEnd of Game\n";


    std::cout << "\n\tDo you wish to restart(Y/N)?\n\t";
    
    char c;
    std::cin >> c; 


    delete G;


    if (c == 'Y' || c == 'y')
        main();
    

    return 0;
}