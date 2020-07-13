#include "person_ui.h"
#include "./common/Common.h"
#include <QDebug>

Person_UI::Person_UI(const bool &isIce, QWidget *parent) : QWidget(parent), isIce(isIce)
{

}

void Person_UI::paint(QPainter &painter)
{
    if (isIce)
    {
        painter.setBrush(Qt::blue);
    }
    else
    {
        painter.setBrush(Qt::red);
    }
//    qDebug() << pos;
    painter.drawLine(QLineF(0, 150, 200, 150));
    painter.drawLine(QLineF(200, 150, 300, 300));
    painter.drawLine(QLineF(100, 60, 300, 40));
    painter.drawLine(QLineF(300, 300, 500, 400));
    painter.drawLine(QLineF(500, 400, 500, 300));
    painter.drawLine(QLineF(500, 300, 700, 100));


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
