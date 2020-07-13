
//Model.cpp


#include"Model.h"
#include <QDebug>

Model::Model() noexcept
    : m_map(QSharedPointer<Map>::create()),
      ice_person(QSharedPointer<Person>::create(m_map)),
      fire_person(QSharedPointer<Person>::create(m_map))
{
    ice_person->set_pos(QPoint(150, 100)); // 设置冰人初始位置
    fire_person->set_pos(QPoint(6, 100)); // 火人初始位置
}

void Model::set_speed(double v_x, double v_y, PersonType &&type) noexcept
{
    if (type == PersonType::ICE)
    { // 设置冰人速度
        ice_person->set_speed(QPoint(int(v_x), int(v_y)));
    }
    else
    { // 设置火人速度
        fire_person->set_speed(QPoint(int(v_x), int(v_y)));
    }
}

void Model::set_speed_x(double v_x, PersonType &&type) noexcept
{
    if (type == PersonType::ICE)
    {
        ice_person->set_speed_x(std::move(v_x));
    }
    else
    {
        fire_person->set_speed_x(std::move(v_x));
    }
}

void Model::set_speed_y(double v_y, PersonType &&type) noexcept
{
    if (type == PersonType::ICE)
    {
        ice_person->set_speed_y(std::move(v_y));
    }
    else
    {
        fire_person->set_speed_y(std::move(v_y));
    }
}

const QPoint &Model::get_pos(PersonType &&type) noexcept
{
    if (type == PersonType::ICE)
    {
        return ice_person->get_pos();
    }
    else
    {
        return fire_person->get_pos();
    }
}

const bool &Model::isAerial(PersonType &&type) noexcept
{
    if (type == PersonType::ICE)
    {
        return ice_person->isAerial();
    }
    else
    {
        return fire_person->isAerial();
    }
}


void Model::Move() noexcept
{
    ice_person->move();
    fire_person->move();
}
