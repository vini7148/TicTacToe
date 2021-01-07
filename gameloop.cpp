#include "gameloop.h"

#ifdef _WIN32
#include <Windows.h>
#define sl Sleep(1000)
#else
#include <unistd.h>
#define sl sleep(1)
#endif

gameloop::gameloop()
{
    x = -1;
    y = -1;
    ch = 1;
}

gameloop::~gameloop()
{
    x = -1;
    y = -1;
    ch = 1;
}

bool gameloop::input()
{
    if (ch % 2 == 1)
    {
        cout << ">> ";
        int temp;
        cin >> temp;

        temp -= 1;

        x = temp / 3;
        y = temp % 3;
    }

    else
    {
        RR.findBestMove(d.check_board());
        // Sleep(1000);
        x = RR.ret_x();
        y = RR.ret_y();
        // cout << "\n>>" << x << " " << y << " AI\n"; 
    }
    
    // cout << "\n" << x << " " << y << "\n"; 

    return d.is_empty(x, y);
}

bool gameloop::init()
{
    return d.init();
}

bool gameloop::run()
{
    bool inp = input();

    if (!inp)
    {
        // error in input
        cout << "\n\aIncorrect Input / Position Already occupied\a\n\n";
        
        return run();
    }

    d.Update(x, y, ch % 2);
    d.update();

    // Sleep(1000);

    sl;

    // if (ch % 2 == 0)
    //     Sleep(5000);

    ch++;

    int win = d.check_win();

    if (win < 0)
    {
        if (d.check_draw())
        {
            cout << "\n\tGAME DRAW\n";

            return false;
        }

        return run();
    }

    if (win == 0)
    {
        cout << "\n\tAI WON\n";
        
        return false;
    }

    cout << "\n\tYOU WON\n";
    return false;
}
