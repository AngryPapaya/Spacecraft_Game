#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid
{
public:
    Asteroid(int _x, int _y);

    void printAsteroid();
    void moveAsteroid();
    void hit(class SpaceCraft &sc);

private:
    int x;
    int y;
};

#endif
