#include "player.h"
#include <QDebug>

Player::Player(int w,int h): Ball(w,h)
{
    vx=10;
    vy=10;

}

void Player::move(int w, int h, QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_S:
        point += QPoint(0,vy);
        break;
    case Qt::Key_W:
        point -= QPoint(0,vy);
        break;
    case Qt::Key_D:
        point += QPoint(vx,0);
        break;
    case Qt::Key_A:
        point -= QPoint(vx,0);
        break;
    default:
        break;
}
    if(point.x()+r>=w)
    {
        point -= QPoint(vx,0);
    }
    if(point.y()+r>=h)
    {
        point -= QPoint(0,vy);
    }
    if(point.x()-r<=0)
    {
        point += QPoint(vx,0);
    }
    if(point.y()-r<=0)
    {
        point += QPoint(0,vy);
    }
}

void Player::draw(QPainter &painter)
{
    //qDebug()<<point;
    QRect rect(point-QPoint(20,20),point+QPoint(20,20));
    painter.drawImage(rect,QImage(":/files/images/av.png"));
   // painter.drawEllipse(point,r,r);

}

void Player::minusLives()
{
    lives--;
}

bool Player::isAlive()
{
    if(lives<=0) return false;
    else return true;
}

int Player::returnLives()
{
    return lives;
}


