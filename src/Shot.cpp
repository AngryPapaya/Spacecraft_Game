#include "Shot.h"
#include "ConsoleUtils.h"
#include <stdio.h>

Shot::Shot(int _x, int _y) : x(_x), y(_y)
{
}

void Shot::moveShot()
{
    gotoxy(x, y);
    printf(" ");

    y--;

    gotoxy(x, y);
    printf("*");
}

bool Shot::out()
{
    if (y == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Shot::X()
{
    return x;
}

int Shot::Y()
{
    return y;
}
