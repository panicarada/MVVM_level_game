//Person.cpp


#include"Person.h"
#include <QDebug>

#include <QtMath>



Person::Person(QSharedPointer<Map> &map, PersonType &&type)
    : m_speed(QPoint()), m_pos(QPoint()), m_map(map), m_isAerial(false)
    , rect(QRectF(m_pos, QSize(PERSONSIZE_X, PERSONSIZE_Y))), type(type)
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

QPointF Person::get_pos() noexcept
{
    return m_pos;
}

QPointF Person::get_speed() noexcept
{
    return m_speed;
}

const bool &Person::isAerial() noexcept
{
    return m_isAerial;
}

void Person::move()
{
    // 检测碰撞
    auto crashed_walls = m_map->intersect_wall(rect);

    //检测钻石
    auto crashed_diamond = m_map->intersect_diamond(rect, type);

    if (crashed_diamond != nullptr) // 碰到钻石
    {
        crashed_diamond->disable(); // 碰到即使其失效
        emit this->diamond_notification(crashed_diamond->get_id());
    }

    // 受重力影响，y方向速度增大（向下）
    m_speed += QPointF(0, DY_SPEED);

    if (crashed_walls == nullptr)
    { // 说明人物在空中，
        if (m_speed.y() >= FALL_BOUND)
        { // 下落速度过快，进行限制
            m_speed.setY(FALL_BOUND);
        }
        m_pos += m_speed; // 位置在这一时刻根据速度改变
        rect.moveTopLeft(m_pos); // 根据人物位置移动矩形
        m_isAerial = true; // 在空中
    }
    else
    {
        // 和墙体碰撞
        if (crashed_walls->floor)
        { // 和地板碰
            m_isAerial = false;
            if (m_speed.y() > 0)
            { // 阻止向下运动
                m_speed.setY(0);
            }
        }
        else if (crashed_walls->slope)
        { // 不和地板碰时，才会考虑斜面
            m_isAerial = false;
            // 先按照现在的速度移动
            m_pos += m_speed;
            rect.moveTopLeft(m_pos);
            if (crashed_walls->slope->intersect(rect))
            { // 这么移动后会穿模
                // 位置退回来
                m_pos -= m_speed;
                rect.moveTopLeft(m_pos);

                // 只保留速度在斜坡上的分量
                QPointF slope_vec = crashed_walls->slope->segment.p2() - crashed_walls->slope->segment.p1(); // 斜坡对应的向量
                double length = crashed_walls->slope->segment.length();

                double slope_speed_project = QPointF::dotProduct(slope_vec/length, m_speed); // 计算目前速度在斜坡上分量大小
                // 用分量大小乘上下坡对应的单位向量，得到新的速度
                m_speed = slope_speed_project * (slope_vec / length);

                // 受到一个沿着斜坡的下滑力
                if (crashed_walls->slope->segment.p2().y() < crashed_walls->slope->segment.p1().y())
                { // 如果第二个点比较高，则下滑力和斜坡正方向相反
                    slope_vec = -slope_vec;
                }
                m_speed +=  10 * (slope_vec / length) * DY_SPEED * qSin(crashed_walls->slope->segment.angle());
            }
            else // 不会穿模
            { // 不改变现有速度，但是暂且退回去
                m_pos -= m_speed;
                rect.moveTopLeft(m_pos);
            }
        }
        if (crashed_walls->ceil)
        { // 和天花板碰撞
            if (m_speed.y() < 0)
            { // 阻止想上运动
                m_speed.setY(-0/8 * m_speed.y());
            }
        }
        if (crashed_walls->left_block)
        {
            // 先按照现在的速度移动
            m_pos += m_speed;
            rect.moveTopLeft(m_pos);
            if (crashed_walls->left_block->intersect(rect))
            { // 这么移动后会穿模
                // 退回来
                m_pos -= m_speed;
                rect.moveTopLeft(m_pos);
                m_speed.setX(0);
                if (!m_isAerial)
                { // 如果此时不在空中，y方向速度也变为0
                    m_speed.setY(0);
                }
            }
            else
            {
                // 退回来
                m_pos -= m_speed;
                rect.moveTopLeft(m_pos);
            }
        }
        if (crashed_walls->right_block)
        {
            // 先按照现在的速度移动
            m_pos += m_speed;
            rect.moveTopLeft(m_pos);
            if (crashed_walls->right_block->intersect(rect))
            {
                // 退回来
                m_pos -= m_speed;
                rect.moveTopLeft(m_pos);
                m_speed.setX(0);
                if (!m_isAerial)
                { // 如果此时不在空中，y方向速度也变为0
                    m_speed.setY(0);
                }
            }
            else
            {
                // 退回来
                m_pos -= m_speed;
                rect.moveTopLeft(m_pos);
            }
        }

        m_pos += m_speed;
        rect.moveTopLeft(m_pos); // 根据人物位置移动矩形
    }

//    qDebug() << m_isAerial;
    // 左右方向的移动是即时性的，若下一时刻没有按左右移动键，x方向上即刻停下
    m_speed.setX(V_MOTIONLESS);
}
