#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

SpaceCraft::SpaceCraft(int _x, int _y) : x_(_x), y_(_y)
{
}

void SpaceCraft::printShip() const
{
    gotoxy(x_, y_);
    printf("  %c", 30);

    gotoxy(x_, y_ + 1);
    printf(" %c%c%c", 40, 207, 41);

    gotoxy(x_, y_ + 2);
    printf("%c%c %c%c", 30, 190, 190, 30);
}

void SpaceCraft::deleteShip() const
{
    gotoxy(x_, y_);
    printf("     ");

    gotoxy(x_, y_ + 1);
    printf("     ");

    gotoxy(x_, y_ + 2);
    printf("     ");
}

void SpaceCraft::moveShip()
{
    if (kbhit())
    {
        deleteShip();
        switch (getch())
        {
            case 'j':
            case LEFT:
                x_--;
                break;
            case 'l':
            case RIGHT:
                x_++;
                break;
            case 'i':
            case UP:
                y_--;
                break;
            case 'k':
            case DOWN:
                y_++;
                break;
            default:
                break;
        }
        printShip();
    }
}
