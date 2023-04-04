#include "ConsoleUtils.h"
#include <stdio.h>
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

void printGameLimits()
{
    char horizontal = 205;
    char vertical = 186;
    char topLeft = 201;
    char bottomLeft = 200;
    char topRight = 187;
    char bottomRight = 188;

    for (int i = 2; i < 78; i++)
    {
        gotoxy(i, 3);
        printf("%c", horizontal);

        gotoxy(i, 33);
        printf("%c", horizontal);
    }

    for (int i = 4; i < 33; i++)
    {
        gotoxy(2, i);
        printf("%c", vertical);

        gotoxy(77, i);
        printf("%c", vertical);
    }

    gotoxy(2, 3);
    printf("%c", topLeft);

    gotoxy(2, 33);
    printf("%c", bottomLeft);

    gotoxy(77, 3);
    printf("%c", topRight);

    gotoxy(77, 33);
    printf("%c", bottomRight);
}
