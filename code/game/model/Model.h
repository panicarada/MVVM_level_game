#pragma once
//Model.h


#ifndef _MODEL_H
#define _MODEL_H

#include"Person.h"
#include"Map.h"
#include "./common/Common.h"

class Model
{
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
private:
    QSharedPointer<Map> m_map;
    QSharedPointer<Person> ice_person;
    QSharedPointer<Person> fire_person;
};

#endif // !_MODEL_H
