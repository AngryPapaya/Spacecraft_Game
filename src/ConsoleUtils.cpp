#include "ConsoleUtils.h"
#include <windows.h>

void gotoxy(int x, int y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, COORD{SHORT(x), SHORT(y)});
}

void hideCursor()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    if (GetConsoleCursorInfo(hOut, &cci))
    {
        cci.bVisible = false;
        SetConsoleCursorInfo(hOut, &cci);
    }
}
