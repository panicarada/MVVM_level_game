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
#include "diamond.h"


// 一面墙体的类
class Wall
{
public:
    // 判断墙面和矩形rect是否相交
    Wall(const QLineF &&segment, const WallType &&wall_type);
    bool intersect(const QRectF &rect);
public:
    QLineF segment; // 墙体对应的线段
    WallType wall_type; // 墙体类型
};



struct Wall_crashed_union
{ // 储存碰撞墙体的结构，同一类型的墙体只有可能一个发生碰撞
    QSharedPointer<Wall> left_block; // 左墙
    QSharedPointer<Wall> right_block; // 右墙
    QSharedPointer<Wall> ceil; // 天花板
    QSharedPointer<Wall> floor; // 地板
    QSharedPointer<Wall> slope; // 斜坡
};


class Map
{
public:
    Map();

    // 判断矩形是否与某一个墙体相交，是的话返回对应墙体指针，否则返回nullptr
    QSharedPointer<Wall_crashed_union> intersect_wall(const QRectF& rect);

    // 判断矩形是否与某一个钻石相交，是的话返回对应钻石的共享指针，否则返回nullptr
    QSharedPointer<Diamond> intersect_diamond(const QRectF& rect, const PersonType& type);
private:
    QSet<QSharedPointer<Wall>> walls_set; // 墙体集合
    QSet<QSharedPointer<Diamond>> diamonds_set; // 钻石集合
};





#endif // !_MAP_H
