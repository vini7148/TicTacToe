#include "draw.h"

#ifdef _WIN32
#define clear system("cls")
#else
#define clear system("clear")
#endif

draw::draw()
{
    clear;
}

draw::~draw()
{
    clear;
}

bool draw::init()
{
    cout << "\n";

    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << ref_bd[i] << "\t\t|\t" << print_bd[i] << "\n";
    }

    cout << "\n";

    return true;
}

bool draw::update()
{
    clear;
    
    char** bd = board::check_board();

    for (int i = 0; i < 3; i++)
    {
        print_bd[2 * i][1] = bd[i][0];
        print_bd[2 * i][5] = bd[i][1];
        print_bd[2 * i][9] = bd[i][2];
    }

    cout << "\n";

    // cout << "\tThis is the reference \t | This board shows the game progress\n";
    // cout << "\tboard for input";

    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << ref_bd[i] << "\t\t|\t" << print_bd[i] << "\n";
    }

    cout << "\n";

    return true;
}