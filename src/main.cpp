#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include "Asteroid.h"
#include <windows.h>
#include <conio.h>

int main()
{
    bool game_over = false;

    SpaceCraft sc(7, 7, 3, 3);

    Asteroid ast_1(10, 4);
    Asteroid ast_2(4, 8);
    Asteroid ast_3(15, 10);

    hideCursor();      
    printGameLimits(); 

    sc.printShip();
    sc.printHealth();

    while (!game_over) 
    {
        ast_1.moveAsteroid();
        ast_1.hit(sc);

        ast_2.moveAsteroid();
        ast_2.hit(sc);

        ast_3.moveAsteroid();
        ast_3.hit(sc);

        sc.deathFunction();
        sc.moveShip();

        Sleep(30);
    }

    return 0;
}
