#ifndef DIAMOND_H
#define DIAMOND_H

#include <memory>
#include <string>
#include <QPoint>
#include <QObject>
#include <QSet>
#include <QLineF>
#include <QPointF>
#include <QRectF>
#include <QSharedPointer>
#include "./common/Common.h"

class Diamond
{
public:
    Diamond() = delete; // 拒绝空构造器
    Diamond(const QPoint &&pos,bool is_Ice);
    QPointF get_pos() noexcept;    //设置钻石位置
    void set_pos(const QPoint &&pos) noexcept; //设置钻石位置
    void set_diamond(bool is_Ice) noexcept;    //设置钻石属性
    void set_exist(bool is_Exist) noexcept;    //设置钻石状态
    bool isIce() noexcept; //获得钻石属性
private:
    bool is_ice_diamond;//钻石属性
    bool is_exist; //是否存在
    QPointF d_pos;//钻石的位置

};

class Diamonds
{
public:
    Diamonds();
    //判断是否与对应钻石接触
    QSharedPointer<Diamond> intersect(const QRectF & rect);
private:
    QSet<QSharedPointer<Diamond>> diamonds_set; // 钻石集合

};

#endif // DIAMOND_H
