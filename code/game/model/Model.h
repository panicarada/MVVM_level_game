#pragma once
//Model.h


#ifndef _MODEL_H
#define _MODEL_H

#include"Person.h"
#include"Map.h"
#include <QObject>
#include "diamond.h"
#include "./common/Common.h"

class Model : public QObject
{
    Q_OBJECT
public:
    Model() noexcept;
    // 设置对应人物的速度
    void set_speed(double v_x, double v_y, PersonType &&type) noexcept;
    // 设置对应人物x方向的速度
    void set_speed_x(double v_x, PersonType &&type) noexcept;
    // 设置对应人物y方向的速度
    void set_speed_y(double v_y, PersonType &&type) noexcept;
    // 获取对应人物的位置
    const QPointF &get_pos(PersonType &&type) noexcept;
    // 获取对应人物的速度
    const QPointF &get_speed(PersonType &&type) noexcept;
    // 判断对应人物是否在空中
    const bool &isAerial(PersonType &&type) noexcept;
    // 间隔刷新的move函数
    void Move() noexcept;
signals:
    void diamond_notification_model(const int& id); // 钻石被碰到后，发射被碰钻石的id
    // 升降台状态发生变化后发射出的信号
    void lifting_platform_notification(const int& id, const QPointF& pos, const movable_item_status& status);
    // 控制杆状态发生变化后发射出的信号
    void trigger_lever_notification(const int& id, const double& angle, const movable_item_status& status);
private:
    QSharedPointer<Map> m_map;
    QSharedPointer<Person> ice_person;
    QSharedPointer<Person> fire_person;
};

#endif // !_MODEL_H
