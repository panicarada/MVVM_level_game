#include "person_ui.h"
#include "./common/Common.h"
#include <QDebug>
#include <QDir>

Person_UI::Person_UI(const PersonType &&person_type, QWidget *parent) :
    QWidget(parent), person_type(person_type)
{
    QString path = "://source//image//";
    if (person_type == ICE)
    {
        path += "ice_";
    }
    else
    {
        path += "fire_";
    }
    // 静止图像
    idle_pics[0].load(path + "idle_1.png");
    idle_pics[1].load(path + "idle_2.png");
    idle_pics[2].load(path + "idle_3.png");
    idle_pics[3].load(path + "idle_4.png");

    // 左移动图像
    left_pics[0].load(path + "left_1.png");
    left_pics[1].load(path + "left_2.png");
    left_pics[2].load(path + "left_3.png");
    left_pics[3].load(path + "left_4.png");

    // 右移动图像
    right_pics[0].load(path + "right_1.png");
    right_pics[1].load(path + "right_2.png");
    right_pics[2].load(path + "right_3.png");
    right_pics[3].load(path + "right_4.png");
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
    int i = Frame % 4;
    // 图像绘制起点做移动是因为图片具有空的部分
    if (person_status == turningLeft)
    {
        painter.drawPixmap(pos.x() - 31, pos.y() - 25, left_pics.at(i));
    }
    else if (person_status == turningRight)
    {
        painter.drawPixmap(pos.x() - 24, pos.y() - 25, right_pics.at(i));
    }
    else
    {
        painter.drawPixmap(pos.x()-32, pos.y() - 26, idle_pics.at(i));
    }
}

void Person_UI::set_pos(const QPointF &pos)
{
    this->pos = pos;
}

void Person_UI::set_speed(const QPointF &speed)
{
    this->speed = speed;
}

void Person_UI::set_status(const PersonStatus &&status)
{
    this->person_status = status;
}
