#include "map_ui.h"
#include <QDebug>


Map_UI::Map_UI(QWidget *parent)
    : QWidget(parent)
{
    img.load(":/source/image/demo_back.png");
}

void Map_UI::paint(QPainter &painter, int width, int height)
{
    painter.drawPixmap(0, 0, img.scaled(width, height, Qt::KeepAspectRatio));
//    painter.drawLine(QLineF(343, 822, 827, 823));
//    painter.drawLine(QLineF(343, 734, 344, 822));
//    painter.drawLine(QLineF(343, 734, 684, 734));
//    painter.drawLine(QLineF(684, 712, 684, 712));
//    painter.drawLine(QLineF(344, 709, 683, 710));
}
