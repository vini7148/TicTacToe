#include <iostream>

#include "ai.h"


robo::robo()
{
    x = -1;
    y = -1;
}

robo::~robo()
{
    x = -1;
    y = -1;
}

bool robo::isMovesLeft(char** board)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    
    return false;
}
 
int robo::evaluate(char** b)
{
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == AI)
                return +10;
            else if (b[row][0] == HU)
                return -10;
        }
    }
 
    for (int col = 0; col<3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == AI)
                return +10;
 
            else if (b[0][col] == HU)
                return -10;
        }
    }
 
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0] == AI)
            return +10;
        else if (b[0][0] == HU)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==AI)
            return +10;
        else if (b[0][2]==HU)
            return -10;
    }
 
    return 0;
}
 
int robo::minimax(char** board, int depth, bool isMax)
{
    int score = robo::evaluate(board);
 
    if (score == 10)
        return score;
 
    if (score == -10)
        return score;
 
    if (robo::isMovesLeft(board)==false)
        return 0;
 
    if (isMax)
    {
        int best = -1000;
 
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j] = AI;
 
                    best = std::max( best, robo::minimax(board, depth+1, !isMax) );

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
 
    else
    {
        int best = 1000;
 
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j] = HU;
 
                    best = std::min(best, robo::minimax(board, depth+1, !isMax));
 
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}
 
void robo::findBestMove(char** board)
{
    int bestVal = -1000;
    
    // Move bestMove;
    // bestMove.row = -1;
    // bestMove.col = -1;

    x = -1;
    y = -1;
 
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j]==' ')
            {
                board[i][j] = AI;
 
                int moveVal = robo::minimax(board, 0, false);
 
                board[i][j] = ' ';
 
                if (moveVal > bestVal)
                {
                    x = i;
                    y = j;
                    bestVal = moveVal;
                }
            }
        }
    }
 
    // return bestMove;
}

int robo::ret_x()
{
    return x;
}

int robo::ret_y()
{
    return y;
}