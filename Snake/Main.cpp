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
void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
void game(HANDLE consoleHandle) {
    Board board;

    Sleep(3000);

    while (board.snake.live() == 1)
    {
        board.output();
        board.change();
        Sleep(16);
        SetConsoleCursorPosition(consoleHandle, { 0,0 });


    }
}

int main()
{

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(consoleHandle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &structCursorInfo);
    
    while (1) {
        game(consoleHandle);

        std::cout << "You are lose!";

    }


    
}

