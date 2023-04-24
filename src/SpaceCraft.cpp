#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

SpaceCraft::SpaceCraft(int _x, int _y, int _health, int _lifeScore) : x(_x), y(_y), health(_health), lifeCounter(_lifeScore)
{
}

void SpaceCraft::printShip()
{
    gotoxy(x, y);
    printf("  %c", 30);

    gotoxy(x, y + 1);
    printf(" %c%c%c", 40, 207, 41);

    gotoxy(x, y + 2);
    printf("%c%c %c%c", 30, 190, 190, 30);
}

void SpaceCraft::deleteShip()
{
    gotoxy(x, y);
    printf("      ");

    gotoxy(x, y + 1);
    printf("      ");

    gotoxy(x, y + 2);
    printf("      ");
}

void SpaceCraft::moveShip()
{
    if (!kbhit())
    {
        return;
    }

    deleteShip();

    int key = getch();
    if (key == 'j' || key == LEFT)
    {
        if (x > 3)
        {
            x--;
        }
    }
    else if (key == 'l' || key == RIGHT)
    {
        if (x + 6 < 77)
        {
            x++;
        }
    }
    else if (key == 'i' || key == UP)
    {
        if (y > 4)
        {
            y--;
        }
    }
    else if (key == 'k' || key == DOWN)
    {
        if (y + 3 < 33)
        {
            y++;
        }
    }

    printShip();
    printHealth();
}

void SpaceCraft::printHealth()
{
    gotoxy(50, 2);
    printf("Lives %d", lifeCounter);

    gotoxy(64, 2);
    printf("Health");

    gotoxy(71, 2);
    printf("      ");

    for (int i = 0; i < health; ++i)
    {
        gotoxy(71 + i, 2);
        printf("%c", 3);
    }
}

void SpaceCraft::deathFunction()
{
    if (health == 0)
    {
        deleteShip();

        gotoxy(x, y);
        printf("  **  ");

        gotoxy(x, y + 1);
        printf(" **** ");

        gotoxy(x, y + 2);
        printf("  **  ");

        Sleep(200);

        deleteShip();

        gotoxy(x, y);
        printf("* ** *");

        gotoxy(x, y + 1);
        printf(" **** ");

        gotoxy(x, y + 2);
        printf("* ** *");

        Sleep(200);

        deleteShip();

        lifeCounter--;
        health = 3;
        printHealth();
        printShip();
    }
}

void SpaceCraft::loseHealth()
{
    health--;
}

int SpaceCraft::X()
{
    return x;
}

int SpaceCraft::Y()
{
    return y;
}

int SpaceCraft::getLifeCounter()
{
    return lifeCounter;
}
