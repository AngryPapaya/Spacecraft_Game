#include "Asteroid.h"
#include "ConsoleUtils.h"
#include <SpaceCraft.h>
#include <stdio.h>
#include <cstdlib>

Asteroid::Asteroid(int _x, int _y) : x(_x), y(_y)
{
}

void Asteroid::printAsteroid()
{
    gotoxy(x, y);
    printf("%c", 184);
}

void Asteroid::moveAsteroid()
{
    gotoxy(x, y);
    printf(" ");

    if (++y > 32)
    {
        x = rand() % 71 + 4;
        y = 4;
    }

    printAsteroid();
}

void Asteroid::hit(class SpaceCraft &sc)
{
    if ((x >= sc.X()) && (x < sc.X() + 6) && (y >= sc.Y()) && (y < sc.Y() + 2))
    {
        sc.loseHealth();
        sc.deleteShip();
        sc.printShip();
        sc.printHealth();

        x = rand() % 71 + 4;
        y = 4;
    }
}

int Asteroid::X()
{
    return x;
}

int Asteroid::Y()
{
    return y;
}
