#include "Const.h"
#include "Board.h"
#include <iostream>
#include <windows.h>
#include <vector>
void init() {
    HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdh, &csbi);
    int board_size_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int board_size_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    std::cout << board_size_x << " " << board_size_y;

}
int main()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

   bool gamegoing = 1;

    Board board;
    
    
   while (gamegoing == 1)
    {
        board.output();
        board.change();
        Sleep(16);
        SetConsoleCursorPosition(consoleHandle, {0,0});


    }
   
    
}

