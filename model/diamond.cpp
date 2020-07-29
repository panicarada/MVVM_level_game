#include "diamond.h"
#include <QDebug>
#include <QtMath>
#include <QRect>
#include <QDebug>



const std::array<QLineF, 5> Diamond::rel_lines =
        {
            QLineF(QPointF(5, 0), QPointF(27, 0)),
            QLineF(QPointF(27, 0), QPointF(33, 7)),
            QLineF(QPointF(33, 7), QPointF(16, 30)),
            QLineF(QPointF(16, 30), QPointF(0, 7)),
            QLineF(QPointF(0, 7), QPointF(5, 0))
        };

Diamond::Diamond(const PersonType &&type, const int &&id, const QPointF &&pos)
    : type(type), is_exist(true), pos(pos), id(id)
{ // 输入线段都是相对坐标，需要平移成绝对坐标
    edges[0] = rel_lines[0].translated(pos);
    edges[1] = rel_lines[1].translated(pos);
    edges[2] = rel_lines[2].translated(pos);
    edges[3] = rel_lines[3].translated(pos);
    edges[4] = rel_lines[4].translated(pos);
}

QPointF &Diamond::get_pos() noexcept
{
    return pos;
}

void Diamond::disable() noexcept
{
    is_exist = false;
}

PersonType& Diamond::get_type() noexcept
{
    return type;
}

int &Diamond::get_id() noexcept
{
    return id;
}

bool Diamond::intersect(const QRectF &rect, const PersonType &rect_type)
{ // 一个钻石是否和矩形相交
    for (auto edge : edges)
    {
        if (is_exist && type == rect_type && intersect_rect_segment(rect, edge))
        {
            return true;
        }
    }
    return false;

}


