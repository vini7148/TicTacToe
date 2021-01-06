# TicTacToe

This is a 1 player game of TicTacToe againt an AI. The AI is implemented using the minimax algorithm that choses the best possible move for any given scenario.

    It is almost imposible to beat this AI as in the worst case scenario this bot will follow a path that will result in a draw.


## Getting Started

***

### Prerequisties

You will require the following tools to compile / execute this application

* any C++ compiler (g++, clang, MingW, etc.)
* This code is platform independent, it will compile / run on both Windows and Unix.

### Compiling

Use the following command in a terminal to create an executable file from this source code
```
g++ main.cpp draw.cpp gameloop.cpp ai.cpp board.cpp
```
Note: I have used g++, but you can use any compiler of your choice. If don't wish to compile this source code yourself you can download the executeable version of the same from the releases, that corresponds to your system.

### Executing the program

If you are on **Windows** you simply double click on the executable file or alternatively you can run the same using the 'CMD' by using the following command

```
a.exe
```
Note: Here 'a.exe' is the name of the executable file.

If you are on any **Unix** platform you can use the following commands in a terminal

```
$ cd /path/to/folder/having/executable

$ ./a.out
```
Note: Here 'a.out' is the name of the executable file.

## Game in action 

![GIF]()


## Authors

* **Vinayak Goswami** - *Initial work* - [vini7148](https://github.com/vini7148)