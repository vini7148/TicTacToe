#include "ai.h"
#include "draw.h"

class gameloop
{
    int x, y, ch;
    robo RR;
    draw d;

public:

    gameloop();
    ~gameloop();

    bool init();
    bool run();

    bool input();
};