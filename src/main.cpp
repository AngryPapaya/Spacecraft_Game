#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include <windows.h>
#include <conio.h>

int main()
{
    bool game_over = false;
    SpaceCraft sc(7, 7, 3, 3);
    hideCursor();
    printGameLimits();
    sc.printShip();
    sc.printHealth();

    while (!game_over)
    {
        sc.deathFunction();
        sc.moveShip();
        Sleep(30); // Delay to simulate animation speed
    }

    return 0;
}
