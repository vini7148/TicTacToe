#include "gameloop.h"

int main()
{
    gameloop G;

    G.init();

    while (G.run())
    {
        // break on draw or win
    }

    std::cout << "\n\n\tEnd of Game\n";
    system("pause");
    

    return 0;
}