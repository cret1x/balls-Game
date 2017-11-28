#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <ball.h>
#include <QKeyEvent>
#include <player.h>

namespace Ui {
class Widget;
}

const int NUM = 7;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    Ball * balls[NUM];
    int scorecounter;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void stopGame();

protected slots:
    void moveAll();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

private:
    Ui::Widget *ui;
    Player * player;
    bool isStarted = false;

};

#endif // WIDGET_H
