#include "person_ui.h"

Person::Person(QWidget *parent) : QWidget(parent)
{

}

void Person::paint(QPainter &painter)
{
    painter.setBrush(Qt::white);
    painter.drawEllipse(20, 17, 8, 8);
}
