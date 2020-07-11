#include "person_ui.h"

Person_UI::Person_UI(QWidget *parent) : QWidget(parent)
{

}

void Person_UI::paint(QPainter &painter)
{

    painter.setBrush(Qt::blue);
    painter.drawEllipse(pos, 100, 100);
}

void Person_UI::set_pos(const QPoint &pos)
{
    this->pos = pos;
}

void Person_UI::set_status(const PersonStatus &&status)
{
    this->person_status = status;
}
