//Map.cpp


#include"Map.h"
#include <QRect>

Map::Map()
    : walls_set(QSet<QSharedPointer<Wall>>())
{
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(0, 150, 200, 150), true));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(200, 150, 300, 300), true));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(100, 60, 300, 40), false));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(300, 300, 500, 400), true));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(500, 400, 500, 300), false));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(500, 300, 700, 100), true));



}

QSharedPointer<Wall> Map::intersect(const QRectF &rect, bool &multiple)
{ // multiple: 是否和多个墙体接触
    QSharedPointer<Wall> crashed_wall = nullptr;
    for (auto wall : walls_set)
    { // 遍历每个墙体
        if (wall->intersect(rect))
        {
            if (crashed_wall != nullptr)
            {
                multiple = true;
                return crashed_wall;
            }
            crashed_wall = wall;
        }
    }
    return crashed_wall;
}

Wall::Wall(const QLineF &&segment, bool &&isFloor)
    : segment(segment), isFloor(isFloor)
{

}

bool Wall::intersect(const QRectF &rect)
{ // 判断线段与（实心）矩形相交
  /* （1）线段在矩形内部，等价于两个点都在矩形内部 */
  if (rect.contains(segment.p1()) && rect.contains(segment.p2()))
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
