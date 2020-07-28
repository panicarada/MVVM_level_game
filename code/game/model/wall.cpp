#include "wall.h"

Wall::Wall(const QLineF &&segment, const WallType &&wall_type)
    : segment(segment), wall_type(wall_type)
{

}

bool Wall::intersect(const QRectF &rect)
{ // 判断线段与（实心）矩形相交
    return intersect_rect_segment(rect, segment);
}

void Wall::translate(const QPointF &&offset)
{
    segment.translate(offset);
}
