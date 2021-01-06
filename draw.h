#include <iostream>
#include <stdlib.h>

#include "board.h"

using namespace std;

class draw: public board
{
    char ref_bd[5][12] =
    {
        { " 1 | 2 | 3 " },
        { "---+---+---" },
        { " 4 | 5 | 6 " },
        { "---+---+---" },
        { " 7 | 8 | 9 " }
    };

    char print_bd[5][12] =
    {
        { "   |   |   " } ,
        { "---+---+---" } ,
        { "   |   |   " },
        { "---+---+---" },
        { "   |   |   " }
    };

public:

    draw();
    ~draw();

    bool init();
    bool update();
};