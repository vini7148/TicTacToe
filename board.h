#pragma once

// #include <bits/stdc++.h>

class board
{
private:
    char* pl;
    int emp;
    char AI = 'X', HU = 'O';

public:
    char** bd;

    board();
    ~board();

    bool Update(int x, int y, int p);
    bool is_empty(int x, int y);
    int check_win();
    bool check_draw();
    char** check_board();
};