//Person.cpp


#include"Person.h"




Person::Person(const PersonType &&type, QSharedPointer<Map> &map)
    : m_speed(QPoint()), m_pos(QPoint()), m_type(type), m_map(map), m_isAerial(false)
{

}

void Person::set_pos(const QPoint &&pos) noexcept
{
    m_pos = pos;
}

void Person::set_pos_x(const int &&pos_x) noexcept
{
    m_pos.setX(pos_x);
}

void Person::set_pos_y(const int &&pos_y) noexcept
{
    m_pos.setY(pos_y);
}

void Person::set_speed(const QPoint &&speed) noexcept
{
    m_speed = speed;
}

void Person::set_speed_x(const int &&speed_x) noexcept
{
    m_speed.setX(speed_x);
}

void Person::set_speed_y(const int &&speed_y) noexcept
{
    m_speed.setY(speed_y);
}

const QPoint &Person::get_pos() noexcept
{
    return m_pos;
}

const QPoint &Person::get_speed() noexcept
{
    return m_speed;
}

const bool &Person::isAerial() noexcept
{
    return m_isAerial;
}

void Person::move()
{
    m_pos += m_speed; // 位置在这一时刻根据速度改变
    rect.setBottomLeft(m_pos); // 根据人物位置移动矩形

    auto wall = m_map->intersect(rect);
    if (wall == nullptr)
    { // 说明人物在空中，受重力影响，y方向速度降低
        m_speed -= QPoint(0, DY_SPEED);
        if (m_speed.y() <= FALL_BOUND)
        { // 下落速度过快，进行限制
            m_speed.setY(FALL_BOUND);
        }

        m_isAerial = true; // 在空中
    }
    else // 和某面墙相撞
    {
        /* 1. 速度在墙面法向分量变为0 */
        /* 2. 速度平行于墙面的分量保持不变 */
        QPoint wall_segment = (wall->segment.p1() - wall->segment.p2()).toPoint(); // 墙面对应向量
        double length = wall->segment.length();
        m_speed = wall_segment * QPoint::dotProduct(wall_segment, m_speed) / length;

        if (wall->isFloor)
        {
            m_isAerial = false;
        }
        else
        {
            m_isAerial = true;
        }
    }
    // 左右方向的移动是即时性的，若下一时刻没有按左右移动键，x方向上即刻停下
    m_speed.setX(V_MOTIONLESS);
}
