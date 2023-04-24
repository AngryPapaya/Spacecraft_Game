#include "SpaceCraft.h"
#include "ConsoleUtils.h"
#include "Asteroid.h"
#include "Shot.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <list>
using namespace std;

int main()
{
    bool game_over = false;
    int score = 0;

    SpaceCraft sc(37, 30, 3, 3);

    list<Asteroid *> a;
    list<Asteroid *>::iterator itA;

    for (int i = 0; i < 5; ++i)
    {
        a.push_back(new Asteroid(rand() % 74 + 3, rand() % 5 + 4));
    }

    list<Shot *> s;
    list<Shot *>::iterator itS;

    hideCursor();
    printGameLimits();

    sc.printShip();
    sc.printHealth();

    while (!game_over)
    {
        gotoxy(4, 2);
        printf("Score %d", score);
        if (kbhit())
        {
            char key = getch();
            if (key == 'a')
            {
                s.push_back(new Shot(sc.X() + 2, sc.Y() - 1));
            }
        }

        for (itS = s.begin(); itS != s.end(); itS++)
        {
            (*itS)->moveShot();
            if ((*itS)->out())
            {
                gotoxy((*itS)->X(), (*itS)->Y());
                printf(" ");
                delete (*itS);
                itS = s.erase(itS);
            }
        }

        for (itA = a.begin(); itA != a.end(); itA++)
        {
            (*itA)->moveAsteroid();
            (*itA)->hit(sc);
        }

        for (itA = a.begin(); itA != a.end(); itA++) {
            for (itS = s.begin(); itS != s.end(); itS++) {
                if ((*itA)->X() == (*itS)->X() && ((*itA)->Y() + 1 == (*itS)->Y() || (*itA)->Y() == (*itS)->Y())) {
                    gotoxy((*itS)->X(), (*itS)->Y());
                    printf(" ");
                    delete(*itS);
                    itS = s.erase(itS);

                    a.push_back(new Asteroid(rand() % 74 + 3, 4));
                    gotoxy((*itA)->X(), (*itA)->Y());
                    printf(" ");
                    delete(*itA);
                    itA = a.erase(itA);

                    score += 5;
                }
            }
        }

        if (sc.getLifeCounter() == 0) {
            game_over = true;
        }

        sc.deathFunction();
        sc.moveShip();

        Sleep(30);
    }

    return 0;
}
