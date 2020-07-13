//Map.cpp


#include"Map.h"
#include <QRect>

Map::Map()
    : walls_set(QSet<QSharedPointer<Wall>>())
{

}

QSharedPointer<Wall> Map::intersect(const QRectF &rect)
{
    for (auto wall : walls_set)
    { // 遍历每个墙体
        if (wall->intersect(rect))
        {
            return wall;
        }
    }
    return nullptr;
}

bool Wall::intersect(const QRectF &rect)
{ // 判断线段与（实心）矩形相交
  /* （1）线段在矩形内部，等价于两个点都在矩形内部 */
  if (rect.contains(segment.p1().toPoint()) && rect.contains(segment.p2().toPoint()))
  {
      return true;
  }

  /* （2）线段与矩形四个边中任意一个相交 */
  if (segment.intersects(QLineF(rect.topLeft(), rect.topRight()), nullptr) == QLineF::BoundedIntersection)
  {
      return true;
  }
  if (segment.intersects(QLineF(rect.topRight(), rect.bottomRight()), nullptr) == QLineF::BoundedIntersection)
  {
      return true;
  }
  if (segment.intersects(QLineF(rect.bottomRight(), rect.bottomLeft()), nullptr) == QLineF::BoundedIntersection)
  {
      return true;
  }
  if (segment.intersects(QLineF(rect.bottomLeft(), rect.topLeft()), nullptr) == QLineF::BoundedIntersection)
  {
      return true;
  }

  return false;
}
