#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class SpaceCraft
{
public:
    SpaceCraft(int _x, int _y);
    void printShip() const;
    void deleteShip() const;
    void moveShip();

private:
    int x_;
    int y_;
};

#endif //SPACECRAFT_H
