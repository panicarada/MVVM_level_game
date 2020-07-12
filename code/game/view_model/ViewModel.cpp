//ViewModel.cpp


#include"ViewModel.h"

ViewModel::ViewModel() noexcept
{
    m_model = std::make_shared<Model>();
}

std::shared_ptr<Commands> ViewModel::get_Ice_left_command()
{
    return Ice_left_command;
}

std::shared_ptr<Commands> ViewModel::get_Ice_right_command()
{
    return Ice_right_command;
}

std::shared_ptr<Commands> ViewModel::get_Ice_jump_command()
{
    return Ice_jump_command;
}

std::shared_ptr<Commands> ViewModel::get_Fire_left_command()
{
    return Fire_left_command;
}

std::shared_ptr<Commands> ViewModel::get_Fire_right_command()
{
    return Fire_right_command;
}

std::shared_ptr<Commands> ViewModel::get_Fire_jump_command()
{
    return Fire_jump_command;
}

std::shared_ptr<Commands> ViewModel::get_move_command()
{
    return move_command;
}

void ViewModel::Exec_Ice_left_command()
{
    m_model->set_speed_x(-V_MOVE, 0);
}
void ViewModel::Exec_Ice_right_command()
{
    m_model->set_speed_x(V_MOVE, 0);
}
void ViewModel::Exec_Ice_jump_command()
{
    if (!m_model->isAerial(0))
        m_model->set_speed_y(V_JUMP, 0);
}

void ViewModel::Exec_Fire_left_command()
{
    m_model->set_speed_x(-V_MOVE, 1);
}
void ViewModel::Exec_Fire_right_command()
{
    m_model->set_speed_x(V_MOVE, 1);
}
void ViewModel::Exec_Fire_jump_command()
{
    if (!m_model->isAerial(1))
        m_model->set_speed_y(V_JUMP, 1);
}

void ViewModel::Exec_move_command()
{
    m_model->Move();
}

const Pos& ViewModel::get_ice_pos()
{
    return m_model->get_ice_pos();
}

const Pos& ViewModel::get_fire_pos()
{
    return m_model->get_fire_pos();
}
