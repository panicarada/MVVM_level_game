#include "Common.h"


// 判断矩形和线段是否相交
bool intersect_rect_segment(const QRectF& rect, const QLineF& segment)
{
    // 判断线段与（实心）矩形相交
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
