#include "map_ui.h"
#include <QDebug>


Map_UI::Map_UI(QWidget *parent)
    : QWidget(parent)
{
    img.load(":/source/image/demo_back.png");
}

void Map_UI::paint(QPainter &painter)
{
    painter.drawPixmap(0, 0, img);
}
