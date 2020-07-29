#include "Common.h"
#include <QtMath>



static double outer_product(const QPointF &p1, const QPointF &p2)
{ // 向量外积
    return p1.x() * p2.y() - p2.x() * p1.y();
}

static bool segments_intersect(const QLineF &segment_1, const QLineF &&segment_2)
{ // 算法描述见https://segmentfault.com/a/1190000004457595
    auto vec_AC = segment_2.p1() - segment_1.p1();
    auto vec_AD = segment_2.p2() - segment_1.p1();
    auto vec_BC = segment_2.p1() - segment_1.p2();
    auto vec_BD = segment_2.p2() - segment_1.p2();

    if (outer_product(vec_AC, vec_AD) * outer_product(vec_BC, vec_BD) <= 0)
    {
        if (outer_product(-vec_AC, -vec_BC) * outer_product(-vec_AD, -vec_BD) <= 0)
        {
            return true;
        }
    }
    return false;
}


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
      if (segments_intersect(segment, QLineF(rect.topLeft(), rect.topRight())))
      {
          return true;
      }
      if (segments_intersect(segment, QLineF(rect.topRight(), rect.bottomRight())))
      {
          return true;
      }
      if (segments_intersect(segment, QLineF(rect.bottomRight(), rect.bottomLeft())))
      {
          return true;
      }
      if (segments_intersect(segment, QLineF(rect.bottomLeft(), rect.topLeft())))
      {
          return true;
      }

      /* 这是Qt 5.14 才引入的写法
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
      }*/
      return false;
}
