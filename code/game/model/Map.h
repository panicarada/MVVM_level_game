#pragma once
//Map.h


#ifndef _MAP_H
#define _MAP_H

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
    bool intersect(const QRectF &rect);
public:
    QLineF segment; // 墙体对应的线段
    bool isFloor; // 是否为地面（斜坡也可以是地面）
};

class Map
{
public:
    Map();

    // 判断矩形是否与某一个墙体相交，是的话返回对应墙体指针，否则返回nullptr
    QSharedPointer<Wall> intersect(const QRectF & rect);
private:
    QSet<QSharedPointer<Wall>> walls_set; // 墙体集合
};





#endif // !_MAP_H
