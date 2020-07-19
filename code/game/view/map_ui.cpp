#include "map_ui.h"
#include "./common/Common.h"
#include <QDebug>
#include <QDir>

Map_UI::Map_UI(QWidget *parent) : QWidget(parent)
{

}

void Map_UI::paint(QPainter &painter)
{
    QPixmap backwall;

    backwall.load("../../source/image/demo_back.png");

    painter.drawPixmap(0, 0, backwall.width(), backwall.height(),backwall);

}
