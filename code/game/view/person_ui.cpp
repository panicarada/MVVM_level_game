#include "person_ui.h"
#include "./common/Common.h"
#include <QDebug>
#include <QDir>

Person_UI::Person_UI(const bool &isIce, QWidget *parent) : QWidget(parent), isIce(isIce)
{

}


/*************************************
 *  |
 * -O------------------------>X轴正方向
 *  |
 *  |
 *  |
 *  |
 *  |
 *  ↓
 * Y轴正方向
*************************************/


void Person_UI::paint(QPainter &painter, int Frame)
{
    QPixmap ice_idle[4];
    QPixmap ice_left[4];
    QPixmap ice_right[4];
    QPixmap fire_idle[4];
    QPixmap fire_left[4];
    QPixmap fire_right[4];

    //这里相对路径等待优化
    //qDebug()<<QDir::currentPath();
    fire_idle[0].load("../../source/image/fire_idle_1.png");
    fire_idle[1].load("../../source/image/fire_idle_2.png");
    fire_idle[2].load("../../source/image/fire_idle_3.png");
    fire_idle[3].load("../../source/image/fire_idle_4.png");

    fire_left[0].load("../../source/image/fire_left_1.png");
    fire_left[1].load("../../source/image/fire_left_2.png");
    fire_left[2].load("../../source/image/fire_left_3.png");
    fire_left[3].load("../../source/image/fire_left_4.png");

    fire_right[0].load("../../source/image/fire_right_1.png");
    fire_right[1].load("../../source/image/fire_right_2.png");
    fire_right[2].load("../../source/image/fire_right_3.png");
    fire_right[3].load("../../source/image/fire_right_4.png");

    ice_idle[0].load("../../source/image/ice_idle_1.png");
    ice_idle[1].load("../../source/image/ice_idle_2.png");
    ice_idle[2].load("../../source/image/ice_idle_3.png");
    ice_idle[3].load("../../source/image/ice_idle_4.png");

    ice_left[0].load("../../source/image/ice_left_1.png");
    ice_left[1].load("../../source/image/ice_left_2.png");
    ice_left[2].load("../../source/image/ice_left_3.png");
    ice_left[3].load("../../source/image/ice_left_4.png");

    ice_right[0].load("../../source/image/ice_right_1.png");
    ice_right[1].load("../../source/image/ice_right_2.png");
    ice_right[2].load("../../source/image/ice_right_3.png");
    ice_right[3].load("../../source/image/ice_right_4.png");
    int i = Frame % 4;


    if (isIce)
    {
        if(person_status == turningLeft)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),ice_left[i].width(),ice_left[i].height(),ice_left[i]);
        }
        else if(person_status == turningRight)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),ice_right[i].width(),ice_right[i].height(),ice_right[i]);
        }
        else
        {
            painter.drawPixmap(pos.rx(), pos.ry(),ice_idle[i].width(),ice_idle[i].height(),ice_idle[i]);
        }

    }
    else
    {
 //       qDebug()<<speed;
        if(person_status == turningLeft)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),fire_left[i].width(),fire_left[i].height(),fire_left[i]);
        }
        else if(person_status == turningRight)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),fire_right[i].width(),fire_right[i].height(),fire_right[i]);
        }
        else
        {
            painter.drawPixmap(pos.rx(), pos.ry(),fire_idle[i].width(),fire_idle[i].height(),fire_idle[i]);
        }
    }
  //  qDebug() << pos;

}

void Person_UI::set_pos(const QPoint &pos)
{
    this->pos = pos;
}

void Person_UI::set_speed(const QPoint &speed)
{
    this->speed = speed;
}

void Person_UI::set_status(const PersonStatus &&status)
{
    this->person_status = status;
}
