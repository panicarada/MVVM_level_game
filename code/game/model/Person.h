#pragma once
//person.h


#ifndef _PERSON_H
#define _PERSON_H

#include <memory>
#include <string>
#include <QPoint>
#include <QObject>
#include "Map.h"
#include "diamond.h"
#include "./common/Common.h"

class Person : public QObject
{
    Q_OBJECT
public:
    Person() = delete; // 拒绝空构造器
    Person(QSharedPointer<Map> &map, PersonType&& type);
    // 设置人物位置
    void set_pos(const QPoint &&pos) noexcept;
    void set_pos_x(const double &&pos_x) noexcept;
    void set_pos_y(const double &&pos_y) noexcept;
    // 设置人物速度
    void set_speed(const QPoint &&speed) noexcept;
    void set_speed_x(const double &&speed_x) noexcept;
    void set_speed_y(const double &&speed_y) noexcept;
    void set_death(bool is_death) noexcept;
    QPointF get_pos() noexcept;
    QPointF get_speed() noexcept;
    const bool& isAerial() noexcept; // 是否在空中
    const bool& isIcePool() noexcept; // 是否在冰池里
    const bool& isFirePool() noexcept; // 是否在冰池里
    void move();
signals:
    // 钻石被碰到时，发出的信号，在适合的地方使用语句emit diamond_notification()发送钻石的标示码
    void diamond_notification(const int &id);
private:
    QPointF m_speed; // 人的速度
    QPointF m_pos; // 人的位置，用左上角的点记录
    QSharedPointer<Map> m_map; // 指向地图的指针
    bool m_isAerial; // 是否在空中
    bool m_Icepool; //判断是否在冰池里
    bool m_Firepool; //判断是否在火池里
    bool m_isDead;  //是否死亡
    QRectF rect; // 人所对应的矩形，m_pos是其左上角
    PersonType type; // 人物类型
};


#endif // !_PERSON_H
