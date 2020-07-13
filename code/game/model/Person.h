#pragma once
//person.h


#ifndef _PERSON_H
#define _PERSON_H

#include <memory>
#include <string>
#include <QPoint>
#include "Map.h"
#include "./common/Common.h"

class Person
{
public:
    Person() = delete; // 拒绝空构造器
    Person(const PersonType &&type, QSharedPointer<Map> &map);

    // 设置人物位置
    void set_pos(const QPoint &&pos) noexcept;
    void set_pos_x(const int &&pos_x) noexcept;
    void set_pos_y(const int &&pos_y) noexcept;
    // 设置人物速度
    void set_speed(const QPoint &&speed) noexcept;
    void set_speed_x(const int &&speed_x) noexcept;
    void set_speed_y(const int &&speed_y) noexcept;

    const QPoint& get_pos() noexcept;
    const QPoint& get_speed() noexcept;
    const bool& isAerial() noexcept; // 是否在空中

    void move();

private:
    /* 注：此时为了方便，坐标系定为 */
    /*       ^ y
     *      |
     *      |
     *     O ------> x
     */

    QPoint m_speed; // 人的速度
    QPoint m_pos; // 人的位置
    QRectF rect; // 人所对应的矩形，m_pos是其左下角
    PersonType m_type; // 是否是冰人
    QSharedPointer<Map> m_map; // 指向地图的指针
    bool m_isAerial; // 是否在空中
};


#endif // !_PERSON_H
