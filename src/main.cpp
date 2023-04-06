#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include "Asteroid.h"
#include "Shot.h"
#include <windows.h>
#include <conio.h>
#include <list>
using namespace std;

int main()
{
    bool game_over = false;

    SpaceCraft sc(7, 7, 3, 3);

    Asteroid ast_1(10, 4);
    Asteroid ast_2(4, 8);
    Asteroid ast_3(15, 10);

    list<Shot *> s;
    list<Shot *>::iterator it;

    hideCursor();
    printGameLimits();

    sc.printShip();
    sc.printHealth();

    while (!game_over)
    {
        if (kbhit())
        {
            char key = getch();
            if (key == 'a')
            {
                s.push_back(new Shot(sc.X() + 2, sc.Y() - 1));
            }
        }

        for (it = s.begin(); it != s.end(); it++)
        {
            (*it)->moveShot();
        }

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
