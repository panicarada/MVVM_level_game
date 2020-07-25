//Map.cpp


#include"Map.h"
#include <QRect>

Map::Map()
    : walls_set(QSet<QSharedPointer<Wall>>())
{
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,800),  QPoint(24,714)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(365,712), QPoint(365,688)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,685), QPoint(24,599)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,573), QPoint(24,341)), LEFT_BLOCK));


    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,800), QPoint(508,800)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,685), QPoint(365,685)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(648,800), QPoint(733,800)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(876,800), QPoint(991,799)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(1018,715), QPoint(1075,714)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(817,630), QPoint(933,632)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(538,632), QPoint(680,630)), FLOOR));


    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,714), QPoint(365,712)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,599), QPoint(422,599)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(422,598), QPoint(478,654)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(478,654), QPoint(957,656)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(1017,569), QPoint(1075,569)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(963,513), QPoint(1017,569)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(932,514), QPoint(963,513)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(904,484), QPoint(932,514)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(535,484), QPoint(904,484)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(142,455), QPoint(507,456)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(507,456), QPoint(535,484)), CEIL));


    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(991, 801), QPoint(991, 743)), RIGHT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(1075, 714), QPoint(1075, 569)), RIGHT_BLOCK));

    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(991, 743), QPoint(1018, 715)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(933, 632), QPoint(957, 656)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(481, 574), QPoint(538, 632)), SLOPE));

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
