#include <iostream>

class robo
{
    int x, y;

    char AI = 'X', HU = 'O';

public:
    robo();
    ~robo();

    bool isMovesLeft(char** board);
    int evaluate(char** b);
    int minimax(char** board, int depth, bool isMax);
    void findBestMove(char** board);

    int ret_x();
    int ret_y();
};