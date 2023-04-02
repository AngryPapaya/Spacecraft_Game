#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class SpaceCraft
{
public:
    SpaceCraft(int _x, int _y, int _health, int _lifeScore);
    void printShip() const;
    void deleteShip() const;
    void moveShip();
    void printHealth();
    void deathFunction();

private:
    int x;
    int y;
    int health;
    int lifeScore;
};

#endif //SPACECRAFT_H
