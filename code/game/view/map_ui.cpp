#include "map_ui.h"
#include <QDebug>


Map_UI::Map_UI(QWidget *parent)
    : QWidget(parent)
{
    // 加载素材图像
    background.load(":/source/image/demo_back.png");
    img_ice_diamond.load(":/source/image/diomand_ice.png");
    img_fire_diamond.load(":/source/image/diomand_fire.png");
    img_ice_diamond = img_ice_diamond.scaledToWidth(40);
    img_fire_diamond = img_fire_diamond.scaledToWidth(40);

    // 添加钻石具体数据
    diamonds << QSharedPointer<Diamond_UI>::create(0, QPoint(558, 740), FIRE);
    diamonds << QSharedPointer<Diamond_UI>::create(1, QPoint(785, 740), ICE);
}

void Map_UI::paint(QPainter &painter, int width, int height)
{
    painter.drawPixmap(0, 0, background.scaled(width, height, Qt::KeepAspectRatio));
    for (auto diamond : diamonds)
    {
        if (diamond->type == ICE)
        { // 冰钻石
            painter.drawPixmap(diamond->pos, img_ice_diamond);
        }
        else if (diamond->type == FIRE)
        { // 火钻石
            painter.drawPixmap(diamond->pos, img_fire_diamond);
        }
    }


//    painter.drawLine(QLineF(343, 822, 827, 823));
//    painter.drawLine(QLineF(343, 734, 344, 822));
//    painter.drawLine(QLineF(343, 734, 684, 734));
//    painter.drawLine(QLineF(684, 712, 684, 712));
    //    painter.drawLine(QLineF(344, 709, 683, 710));
}

void Map_UI::remove_diamond(const int &id)
{
    for (auto diamond : diamonds)
    {
        if (diamond->id == id)
        { // id不会重复
            diamonds -= diamond;
            break;
        }
    }
}
