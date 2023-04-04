#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class SpaceCraft
{
public:
    SpaceCraft(int _x, int _y, int _health, int _lifeScore);

    void printShip();
    void deleteShip();
    void moveShip();
    void printHealth();
    void deathFunction();
    int X();
    int Y();
    void loseHealth();

private:
    int x;           
    int y;           
    int health;      
    int lifeCounter; 
};

#endif
