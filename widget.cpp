#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <player.h>
#include <ball.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    srand(time(0));
    ui->setupUi(this);
    ui->lcdNumber->hide();


}

Widget::~Widget()
{
    for (int i=0;i<NUM;i++)
        delete balls[i];
    delete player;
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    if(isStarted)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        for (int i=0; i<NUM; i++)
            balls[i]->draw(painter);
        player->draw(painter);
    }
}

void Widget::keyPressEvent(QKeyEvent *e)
{
   if(isStarted)
   {
       player->move(width(),height(), e);
   }
}


void Widget::stopGame()
{
    if(isStarted)
    {
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(moveAll()));
        timer.stop();
        QMessageBox::warning(this,"Balls","GAME OVER! SCORE: "+QString::number(time(0)-scorecounter)+" SECONDS");
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->lcdNumber->hide();
        for (int i=0;i<NUM;i++)
            delete balls[i];
        delete player;
        isStarted = false;
    }
}

void Widget::moveAll()
{
    if(isStarted){
    for(int i=0;i<NUM;i++){
        for(int j=i;j<NUM;j++){
             if(balls[i]->isCollided(*balls[j]))
             {
                 balls[i]->reverse();
                 balls[j]->reverse();
             }
         }
    }
    for(int i=0;i<NUM;i++)
    {
        if(player->isCollided(*balls[i]))
        {
           balls[i]->reverse();
           player->minusLives();
           if(!player->isAlive())
               stopGame();
        }
    }
    for (int i=0; i<NUM; i++)
        balls[i]->move(width(), height());
    ui->lcdNumber->display(player->returnLives());
    this->repaint();
}
}

void Widget::on_pushButton_clicked(bool checked)
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->lcdNumber->show();
    for (int i=0;i<NUM;i++)
    {
        balls[i] = new Ball(width(),height());
    }
    player = new Player(width(),height());
    connect(&timer,SIGNAL(timeout()),this,SLOT(moveAll()));
    timer.start(40);
    scorecounter = time(0);
    isStarted = true;
}

void Widget::on_pushButton_2_clicked(bool checked)
{
    this->close();
}
