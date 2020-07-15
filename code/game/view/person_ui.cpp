#include "person_ui.h"
#include "./common/Common.h"
#include <QDebug>

Person_UI::Person_UI(const PersonType &&type, QWidget *parent) : QWidget(parent), person_type(type)
{
    qDebug() << ice_stand.load(":/source/image/ice_stand.png");
    fire_stand.load(":/source/image/fire_stand.png");
}


void Person_UI::paint(QPainter &painter)
{

    if (person_type == PersonType::ICE)
    {
        painter.drawPixmap(pos, ice_stand);
    }
    else
    {
        painter.drawPixmap(pos, fire_stand);
    }

//    qDebug() << pos;
    painter.drawLine(QLineF(0, 150, 200, 150)); // FLOOR
    painter.drawLine(QLineF(200, 150, 300, 300)); // SLOPE
    painter.drawLine(QLineF(0, 60, 400, 60)); // CEIL
    painter.drawLine(QLineF(300, 300, 500, 400)); // SLOPE
    painter.drawLine(QLineF(500, 400, 500, 301)); // RIGHT_BLOCK
    painter.drawLine(QLineF(501, 300, 700, 300)); // FLOOR


    painter.drawRect(pos.x(), pos.y(), PERSONSIZE_X, PERSONSIZE_Y);
}

void Person_UI::set_pos(const QPoint &pos)
{
    this->pos = pos;
}

void Person_UI::set_status(const PersonStatus &&status)
{
    this->person_status = status;
}
