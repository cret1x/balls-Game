#include "ball.h"

Ball::Ball(int w,int h)
{
    r = 15 + rand()%15;
    point.setX(rand()%(w-2*r));
    point.setY(rand()%(h-2*r));
    color = QColor::fromRgb(rand()%256,rand()%256,rand()%256);
    vx = 5 + rand()%15;
    vy = 5 + rand()%15;
    if(rand()%2==0) vx *=-1;
    if(rand()%2==0) vy *=-1;
}

void Ball::move(int w, int h)
{
    point += QPoint(vx,vy);
    if(point.x()+r>=w) vx*=-1;
    if(point.y()+r>=h) vy*=-1;
    if(point.x()-r<=0) vx*=-1;
    if(point.y()-r<=0) vy*=-1;
}

void Ball::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color,Qt::Dense4Pattern));
    painter.drawImage(point.x()-r,point.y()-r,QImage(":/files/images/batya.png").scaled(2*r,2*r));
}



bool Ball::isCollided(Ball &b)
{
    if((b.point.x() - point.x())*(b.point.x() - point.x())+(b.point.y()-point.y())*(b.point.y()-point.y())<=(b.r+r)*(b.r+r))
        return true;  
    else return false;
}

void Ball::reverse()
{
    vx*=-1;
    vy*=-1;
}

