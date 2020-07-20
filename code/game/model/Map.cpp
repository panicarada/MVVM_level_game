//Map.cpp


#include"Map.h"
#include <QRect>

Map::Map()
    : walls_set(QSet<QSharedPointer<Wall>>())
{
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(23,802),  QPoint(506,802)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,713), QPoint(24,801)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,713), QPoint(362,710) ), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(364,688), QPoint(364,710)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(22,685), QPoint(363,689)), FLOOR));
}

QSharedPointer<Wall_crashed_union> Map::intersect(const QRectF &rect)
{
    QSharedPointer<Wall_crashed_union> crashed_walls = nullptr;
    for (auto wall : walls_set)
    { // 遍历每个墙体
        if (wall->intersect(rect))
        {
            if (crashed_walls == nullptr)
            {
                crashed_walls = QSharedPointer<Wall_crashed_union>::create();
            }
            if (wall->wall_type == FLOOR)
            {
                crashed_walls->floor = wall;
            }
            else if (wall->wall_type == CEIL)
            {
                crashed_walls->ceil = wall;
            }
            else if (wall->wall_type == LEFT_BLOCK)
            {
                crashed_walls->left_block = wall;
            }
            else if (wall->wall_type == RIGHT_BLOCK)
            {
                crashed_walls->right_block = wall;
            }
            else if (wall->wall_type == SLOPE)
            {
                crashed_walls->slope = wall;
            }
        }
    }
    return crashed_walls;
}


Wall::Wall(const QLineF &&segment, const WallType &&wall_type)
    : segment(segment), wall_type(wall_type)
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
