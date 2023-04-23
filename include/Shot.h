#ifndef SHOT_H
#define SHOT_H

class Shot
{
public:
    Shot(int _x, int _y);

    void moveShot();
    bool out();
    int X();
    int Y();

private:
    int x;
    int y;
};

#endif