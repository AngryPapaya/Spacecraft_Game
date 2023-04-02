#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include <windows.h>
#include <conio.h>

int main()
{
    bool game_over = false;
    SpaceCraft sc(7, 7);
    hideCursor();
    sc.printShip();

    while (!game_over)
    {
        sc.moveShip();
        Sleep(30); // Delay to simulate animation speed
    }

    return 0;
}
