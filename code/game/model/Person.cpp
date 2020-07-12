//Person.cpp


#include"Person.h"



void Person::set_map(const std::shared_ptr<Map>& m)
{
    m_map = m;
}

void Person::set_pos_x(double x) noexcept
{
    m_pos.x = x;
}

double Person::get_pos_x() noexcept
{
    return m_pos.x;
}

void Person::set_pos_y(double y) noexcept
{
    m_pos.y = y;
}

double Person::get_pos_y() noexcept
{
    return m_pos.y;
}

void Person::set_pos(double x, double y) noexcept
{
    m_pos.x = x;
    m_pos.y = y;
}

const Pos& Person::get_pos() noexcept
{
    return m_pos;
}

void Person::get_pos(double& x, double& y) noexcept
{
    x = m_pos.x;
    y = m_pos.y;
}

const Pos Person::get_pos_right() noexcept
{
    return Pos(m_pos.x + PERSONSIZE_X, m_pos.y);
}

const std::string& Person::get_name() const noexcept
{
    return *m_name.get();
}

void Person::set_speed_x(double x) noexcept
{
    m_speed.x = x;
}

double Person::get_speed_x() noexcept
{
    return m_speed.x;
}

void Person::set_speed_y(double y) noexcept
{
    m_speed.y = y;
}

double Person::get_speed_y() noexcept
{
    return m_speed.y;
}

Velocity& Person::get_speed() noexcept
{
    return m_speed;
}

void Person::set_aerial(bool isAerial) noexcept
{
    aerial = isAerial;
}

void Person::move()
{

    m_pos.x += m_speed.x;
    m_pos.y += m_speed.y;

    //»ºÂý¼õËÙ
    if (aerial)
        if (m_speed.y > V_GRAVITY + D_SPEED)
            m_speed.y -= D_SPEED;
        else m_speed.y = V_GRAVITY;
    else
    {
        m_speed.x = V_MOTIONLESS;
        m_speed.y = V_MOTIONLESS;
    }
}
