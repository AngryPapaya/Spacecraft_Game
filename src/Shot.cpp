#include "Shot.h"
#include "ConsoleUtils.h"
#include <stdio.h>

Shot::Shot(int _x, int _y) : x(_x), y(_y)
{
}

void Shot::moveShot() {
    gotoxy(x, y);
    printf(" ");

    if (y > 4) {
        y--;
    }

    gotoxy(x, y);
    printf("*");
}

