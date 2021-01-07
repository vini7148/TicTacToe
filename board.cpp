#include "board.h"

board::board()
{
    bd = new char*[3];

    for (int i = 0; i < 3; i++)
    {
        bd[i] = new char[3];

        for (int j = 0; j < 3; j++)
        {
            bd[i][j] = ' ';
        }
    }


    pl = new char[2];
    
    pl[0] = 'X';
    pl[1] = 'O';
    
    emp = 9;
}

board::~board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bd[i][j] = ' ';
        }
    }

    delete[] bd;
    
    delete[] pl;
}

bool board::Update(int x, int y, int p)
{
    if (x > 2 || x < 0 || y > 2 || y < 0)
        return false;

    if (bd[x][y] != ' ')
        return false;

    bd[x][y] = pl[p];
    emp--;

    return true;
}

bool board::is_empty(int x, int y)
{
    if (x > 2 || x < 0 || y > 2 || y < 0)
        return false;

    if (bd[x][y] == ' ')
        return true;

    return false;
}


int board::check_win()
{
    for (int row = 0; row < 3; row++)
    {
        if (bd[row][0] == bd[row][1] &&
            bd[row][1] == bd[row][2])
        {
            if (bd[row][0] == AI)
                return 0;
            else if (bd[row][0] == HU)
                return 1;
        }
    }
 
    for (int col = 0; col<3; col++)
    {
        if (bd[0][col] == bd[1][col] &&
            bd[1][col] == bd[2][col])
        {
            if (bd[0][col] == AI)
                return 0;
 
            else if (bd[0][col] == HU)
                return 1;
        }
    }
 
    if (bd[0][0]==bd[1][1] && bd[1][1]==bd[2][2])
    {
        if (bd[0][0] == AI)
            return 0;
        else if (bd[0][0] == HU)
            return 1;
    }
 
    if (bd[0][2]==bd[1][1] && bd[1][1]==bd[2][0])
    {
        if (bd[0][2]==AI)
            return 0;
        else if (bd[0][2]==HU)
            return 1;
    }
 
    return -1;
}


// int board::check_win()
// {
//     for (int i = 0; i < 3; i++)
//     {
//         if (bd[i][0] == bd[i][1] && bd[i][1] == bd[i][2])
//         {
//             if (bd[i][0] == 'X')
//                 return 0;
            
//             return 1;
//         }
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         if (bd[0][i] == bd[1][i] && bd[1][i] == bd[2][i])
//         {
//             if (bd[i][0] == 'X')
//                 return 0;
            
//             return 1;
//         }
//     }

//     if (bd[0][0] == bd[1][1] && bd[1][1] == bd[2][2])
//     {
//         if (bd[0][0] == 'X')
//             return 0;
            
//         return 1;
//     }

//     if (bd[0][2] == bd[1][1] && bd[1][1] == bd[2][0])
//     {
//         if (bd[0][2] == 'X')
//             return 0;
            
//         return 1;
//     }


//     return -1;
// }

// bool board::check_draw()
// {
//     if (!emp)
//         return false;

//     return true;
// }

bool board::check_draw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (bd[i][j] == ' ')
                return false;
    
    return true;
}

char** board::check_board()
{
    return bd;
}