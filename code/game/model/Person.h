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
    Person(QSharedPointer<Map> &map,QSharedPointer<Diamonds> &Diamonds);
    // 设置人物位置
    void set_pos(const QPoint &&pos) noexcept;
    void set_pos_x(const double &&pos_x) noexcept;
    void set_pos_y(const double &&pos_y) noexcept;
    // 设置人物速度
    void set_speed(const QPoint &&speed) noexcept;
    void set_speed_x(const double &&speed_x) noexcept;
    void set_speed_y(const double &&speed_y) noexcept;
    QPointF get_pos() noexcept;
    QPointF get_speed() noexcept;
    const bool& isAerial() noexcept; // 是否在空中
    void move();
signals:
    // 钻石被碰到时，发出的信号，在适合的地方使用语句emit diamond_notification()发送
    void diamond_notification(QSharedPointer<Diamond> diamond);
private:
    QPointF m_speed; // 人的速度
    QPointF m_pos; // 人的位置，用左上角的点记录
    QSharedPointer<Map> m_map; // 指向地图的指针
    QSharedPointer<Diamonds> m_diamonds; // 指向钻石的指针
    bool m_isAerial; // 是否在空中
    QRectF rect; // 人所对应的矩形，m_pos是其左下角
};


#endif // !_PERSON_H
