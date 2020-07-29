//Person.cpp


#include"Person.h"
#include <QDebug>

#include <QtMath>



Person::Person(QSharedPointer<Map> &map, PersonType &&type)
    : m_speed(QPoint(0, 0)), m_pos(QPoint(0, 0)), m_map(map), m_isAerial(false)
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
    if (m_map->intersect_wrong_pool(rect, type))
    { // 角色死亡，发射游戏状态改变的信号
        emit change_game_status_notification(DEAD);
        return ;
    }


    // 检测墙体碰撞
    // 受重力影响，y方向速度增大（向下）
    m_speed += QPointF(0, DY_SPEED);

    auto crashed_walls = m_map->intersect_wall(rect);

    // 检测钻石
    auto crashed_diamond = m_map->intersect_diamond(rect, type);
    if (crashed_diamond != nullptr) // 碰到钻石
    {
        crashed_diamond->disable(); // 碰到即使其失效
        emit this->diamond_notification(crashed_diamond->get_id());
    }

    // 检测控制杆
    auto crashed_lever = m_map->intersect_lever(rect);
    if (crashed_lever != nullptr) // 碰到机关
    {
        if (crashed_lever->intersect(rect.translated(m_speed)))
        { // 如果移动后还是会碰撞
            double speed_angle = 90.0 - qRadiansToDegrees(qAtan(m_speed.x() / m_speed.y())); // 速度和x正方向夹角
//            qDebug() << "speed_angle = " << speed_angle;
            if (speed_angle >= crashed_lever->get_angle())
            {
                crashed_lever->trigger_counter_clockwise();
            }
            else
            {
                crashed_lever->trigger_clockwise();
            }
//            crashed_lever->move();
            return ;
        }
    }

    // 检测碰撞升降台
    QSharedPointer<Wall> crashed_platform_edge;
    auto crashed_platform = m_map->intersect_platform(rect, crashed_platform_edge);
    if (crashed_platform != nullptr)
    { // 相对于碰到墙体，加入到碰到的墙体集合即可
        if (crashed_walls == nullptr)
        {
            crashed_walls = QSharedPointer<Wall_crashed_union>::create();
        }
        if (crashed_platform_edge->wall_type == LEFT_BLOCK)
        {
            crashed_walls->left_block = crashed_platform_edge;
        }
        else if (crashed_platform_edge->wall_type == RIGHT_BLOCK)
        {
            crashed_walls->right_block = crashed_platform_edge;
        }
        else if (crashed_platform_edge->wall_type == CEIL)
        {
            crashed_walls->ceil = crashed_platform_edge;
        }
        else if (crashed_platform_edge->wall_type == FLOOR)
        {
            crashed_walls->floor = crashed_platform_edge;
            if (crashed_platform->get_status() == MOVING)
            {
                m_speed.setY(1.6*crashed_platform->get_speed()); // 跟着平台一起上升或下降
            }
        }
    }

    m_map->update();




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
