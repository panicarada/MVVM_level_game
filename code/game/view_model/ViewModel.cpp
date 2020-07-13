//ViewModel.cpp


#include"ViewModel.h"
#include "./common/Common.h"

ViewModel::ViewModel() noexcept
{
    m_model = QSharedPointer<Model>::create();
}

void ViewModel::Exec_Ice_left_command()
{
    m_model->set_speed_x(-V_MOVE, PersonType::ICE);
}
void ViewModel::Exec_Ice_right_command()
{
    m_model->set_speed_x(V_MOVE, PersonType::ICE);
}
void ViewModel::Exec_Ice_jump_command()
{
    if (!m_model->isAerial(PersonType::ICE))
    { // 不在空中才能执行这一指令
        m_model->set_speed_y(V_JUMP, PersonType::ICE);
    }
}

void ViewModel::Exec_Fire_left_command()
{
    m_model->set_speed_x(-V_MOVE, PersonType::FIRE);
}
void ViewModel::Exec_Fire_right_command()
{
    m_model->set_speed_x(V_MOVE, PersonType::FIRE);
}

void ViewModel::Exec_Fire_jump_command()
{
    if (!m_model->isAerial(PersonType::FIRE))
    { // 不在空中才能执行这一指令
        m_model->set_speed_y(V_JUMP, PersonType::FIRE);
    }
}

void ViewModel::Exec_move_command()
{
    m_model->Move();
}

const QPoint& ViewModel::get_ice_pos()
{
    return m_model->get_pos(PersonType::ICE);
}

const QPoint& ViewModel::get_fire_pos()
{
    return m_model->get_pos(PersonType::FIRE);
}
