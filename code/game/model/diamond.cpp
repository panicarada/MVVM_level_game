#include "diamond.h"
#include <QDebug>
#include <QtMath>
#include <QRect>


Diamond::Diamond(const QPoint &&pos,bool is_Ice)
    :is_ice_diamond(is_Ice),is_exist(true),d_pos(pos)
{

}


void Diamond::set_pos(const QPoint &&pos) noexcept
{
    d_pos = pos;
}

void Diamond::set_diamond(bool is_Ice) noexcept
{
    is_ice_diamond = is_Ice;
}

void Diamond::set_exist(bool is_Exist) noexcept
{
    is_exist = is_Exist;
}


QPointF Diamond::get_pos() noexcept
{
    return d_pos;
}

bool Diamond::isIce() noexcept
{
    return is_ice_diamond;
}

Diamonds::Diamonds()
    :diamonds_set(QSet<QSharedPointer<Diamond>>())
{
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(578,760),false));//创建钻石_火
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(805,760),true));//创建钻石_冰
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(600,600),false));
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(875,600),true));
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(200,390),false));
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(500,390),true));
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(94,126),true));
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(583,102),true));
    diamonds_set.insert(QSharedPointer<Diamond>::create(QPoint(749,102),true));
}



QSharedPointer<Diamond> Diamonds::intersect(const QRectF & rect)
{
//    QSharedPointer<Diamond> resu_dia = nullptr;
    for (auto eDiamond : diamonds_set)//遍历所有钻石
    {
        if (rect.contains(eDiamond->get_pos()))//如果碰到钻石
        {
            return eDiamond;
        }
    }
    return nullptr;//未碰到钻石 返回空指针
}


