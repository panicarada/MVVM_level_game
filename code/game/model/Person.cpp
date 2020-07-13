//Person.cpp


#include"Person.h"
#include <QDebug>

#include <QtMath>


Person::Person(QSharedPointer<Map> &map)
    : m_speed(QPoint()), m_pos(QPoint()), m_map(map), m_isAerial(false)
    , rect(QRectF(m_pos, QSize(PERSONSIZE_X, PERSONSIZE_Y)))
{

}

void Person::set_pos(const QPoint &&pos) noexcept
{
    m_pos = pos;
    rect.moveTopLeft(m_pos);
}

void Person::set_pos_x(const double &&pos_x) noexcept
{
    m_pos.setX(pos_x);
    rect.moveTopLeft(m_pos);
}

void Person::set_pos_y(const double &&pos_y) noexcept
{
    m_pos.setY(pos_y);
    rect.moveTopLeft(m_pos);
}

void Person::set_speed(const QPoint &&speed) noexcept
{
    m_speed = speed;
}

void Person::set_speed_x(const double &&speed_x) noexcept
{
    m_speed.setX(speed_x);
}

void Person::set_speed_y(const double &&speed_y) noexcept
{
    m_speed.setY(speed_y);
}

QPoint Person::get_pos() noexcept
{
    return m_pos.toPoint();
}

QPoint Person::get_speed() noexcept
{
    return m_speed.toPoint();
}

const bool &Person::isAerial() noexcept
{
    return m_isAerial;
}

void Person::move()
{
    m_pos += m_speed; // 位置在这一时刻根据速度改变
    rect.moveTopLeft(m_pos); // 根据人物位置移动矩形

    bool multiple = false; // 是否和多面墙体相撞
    auto wall = m_map->intersect(rect, multiple);

    if (multiple)
    { // 与多面墙体相撞，速度设为0

        m_pos -= m_speed;
        m_speed.setX(V_MOTIONLESS);
        m_speed.setY(V_MOTIONLESS);
        return ;
    }

    if (wall == nullptr)
    { // 说明人物在空中，受重力影响，y方向速度降低
        m_speed += QPointF(0, DY_SPEED);
        if (m_speed.y() >= FALL_BOUND)
        { // 下落速度过快，进行限制
            m_speed.setY(FALL_BOUND);
        }

        m_isAerial = true; // 在空中
    }
    else // 和某面墙相撞
    {
        /* 1. 速度在墙面法向分量变为0 */
        /* 2. 速度平行于墙面的分量保持不变 */
        QPointF wall_segment = (wall->segment.unitVector().p2() - wall->segment.unitVector().p1()); // 墙面对应单位向量
        m_speed = wall_segment * QPointF::dotProduct(wall_segment, m_speed);

//        qDebug() << wall_segment;
        if (wall->isFloor)
        {
            m_isAerial = false;


            if (wall->segment.angle() > 90)
            {
                m_pos += V_MOVE * wall_segment * qSin(wall->segment.angle());
            }
            else
            {
                m_pos -= V_MOVE * wall_segment * qSin(wall->segment.angle());
            }
        }
        else
        {
            m_speed += QPointF(0, DY_SPEED);
            if (m_speed.y() >= FALL_BOUND)
            { // 下落速度过快，进行限制
                m_speed.setY(FALL_BOUND);
            }
            m_pos += m_speed;
            m_isAerial = true;
        }
    }

//    qDebug() << m_isAerial;
    // 左右方向的移动是即时性的，若下一时刻没有按左右移动键，x方向上即刻停下
    m_speed.setX(V_MOTIONLESS);
}
