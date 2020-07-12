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
    painter.drawRect(pos.x(), pos.y()-PERSONSIZE_Y, PERSONSIZE_X, PERSONSIZE_Y);
}

void Person_UI::set_pos(const QPoint &pos)
{
    this->pos = pos;
}

void Person_UI::set_status(const PersonStatus &&status)
{
    this->person_status = status;
}
