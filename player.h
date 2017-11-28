#ifndef PLAYER_H
#define PLAYER_H
#include <ball.h>

class Player : public Ball
{
private:
    int lives = 3;
public:
    Player(int w,int h);
    void move(int w, int h,QKeyEvent *e);
    void draw(QPainter &painter);
    void minusLives();
    bool isAlive();
    int returnLives();
};

#endif // PLAYER_H
