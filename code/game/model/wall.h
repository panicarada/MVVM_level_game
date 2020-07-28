#ifndef WALL_H
#define WALL_H
#include <vector>
#include <QSet>
#include <QLineF>
#include <QPointF>
#include <QRectF>
#include <QSharedPointer>
#include "./common/Common.h"

// 一面墙体的类
class Wall
{
public:
    // 判断墙面和矩形rect是否相交
    Wall(const QLineF &&segment, const WallType &&wall_type);
    bool intersect(const QRectF &rect);
    void translate(const QPointF &&offset); // 平移，在升降台中用到
public:
    QLineF segment; // 墙体对应的线段
    WallType wall_type; // 墙体类型
};




#endif // WALL_H
