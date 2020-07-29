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
#include "lifting_platform.h"
#include "trigger_lever.h"
#include "diamond.h"
#include "wall.h"





struct Wall_crashed_union
{ // 储存碰撞墙体的结构，同一类型的墙体只有可能一个发生碰撞
    QSharedPointer<Wall> left_block; // 左墙
    QSharedPointer<Wall> right_block; // 右墙
    QSharedPointer<Wall> ceil; // 天花板
    QSharedPointer<Wall> floor; // 地板
    QSharedPointer<Wall> slope; // 斜坡
};



class Map : public QObject
{
    Q_OBJECT
public:
    Map();

    // 判断矩形是否与某一个墙体相交，是的话返回对应墙体指针，否则返回nullptr
    QSharedPointer<Wall_crashed_union> intersect_wall(const QRectF& rect);
    // 判断矩形是否和某一个不能碰的池相交，是的话返回真，否则为假
    bool intersect_wrong_pool(const QRectF &rect, const PersonType& type);

    // 判断矩形是否与某一个钻石相交，是的话返回对应钻石的共享指针，否则返回nullptr
    QSharedPointer<Diamond> intersect_diamond(const QRectF& rect, const PersonType& type);
    // 判断矩形是否和某一个控制杆相交，是的话返回对应钻石的共享指针，否则返回nullptr
    QSharedPointer<trigger_lever> intersect_lever(const QRectF& rect);
    // 判断矩形是否和某一个升降台相交，是的话返回对应碰撞升降台的共享指针，wall返回碰撞的具体墙体，否则返回nullptr
    QSharedPointer<lifting_platform> intersect_platform(const QRectF& rect, QSharedPointer<Wall>& wall_ptr);


    void update(); // 更新所有的元素，因为不一定碰撞才会触发更新
signals:
    // 升降台状态发生变化后发射出的信号
    void lifting_platform_notification(const int& id, const QPointF& pos, const movable_item_status& status);
    // 控制杆状态发生变化后发射出的信号
    void trigger_lever_notification(const int& id, const double& angle, const movable_item_status& status);
private:
    QSet<QSharedPointer<Wall>> walls_set; // 墙体集合
    QSet<QSharedPointer<Diamond>> diamonds_set; // 钻石集合
    QSet<QSharedPointer<lifting_platform>> platforms_set; // 升降台集合
    QSet<QSharedPointer<trigger_lever>> levers_set; // 控制杆集合
    QSet<QSharedPointer<Wall>> ice_pools_set; // 冰池集合
    QSet<QSharedPointer<Wall>> fire_pools_set; // 火池集合
    QSet<QSharedPointer<Wall>> poison_pools_set; // 毒池集合
};





#endif // !_MAP_H
