//ViewModel.cpp


#include"ViewModel.h"
#include "./common/Common.h"
#include <QDebug>

ViewModel::ViewModel(QSharedPointer<Model> model) noexcept
{
    m_model = model;
    // 此时this并没有被共享指针管理，不可以对命令进行连接
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

void ViewModel::setup_command(QSharedPointer<ViewModel> vm)
{
    // 绑定命令
    fire_jump_move_command = QSharedPointer<Fire_jump_move_command<ViewModel>>::create(vm);
    fire_left_move_command = QSharedPointer<Fire_left_move_command<ViewModel>>::create(vm);
    fire_right_move_command = QSharedPointer<Fire_right_move_command<ViewModel>>::create(vm);
    ice_jump_move_command = QSharedPointer<Ice_jump_move_command<ViewModel>>::create(vm);
    ice_left_move_command = QSharedPointer<Ice_left_move_command<ViewModel>>::create(vm);
    ice_right_move_command = QSharedPointer<Ice_right_move_command<ViewModel>>::create(vm);
    move_command = QSharedPointer<Move_command<ViewModel>>::create(vm);
}

QSharedPointer<Commands> ViewModel::get_fire_jump_move_command()
{
    return fire_jump_move_command;
}

QSharedPointer<Commands> ViewModel::get_fire_left_move_command()
{
    return fire_left_move_command;
}

QSharedPointer<Commands> ViewModel::get_fire_right_move_command()
{
    return fire_right_move_command;
}

QSharedPointer<Commands> ViewModel::get_ice_jump_move_command()
{
    return ice_jump_move_command;
}

QSharedPointer<Commands> ViewModel::get_ice_left_move_command()
{
    return ice_left_move_command;
}

QSharedPointer<Commands> ViewModel::get_ice_right_move_command()
{
    return ice_right_move_command;
}

QSharedPointer<Commands> ViewModel::get_move_command()
{
    return move_command;
}

const QPointF& ViewModel::get_ice_pos()
{
    return m_model->get_pos(PersonType::ICE);
}

const QPointF& ViewModel::get_fire_pos()
{
    return m_model->get_pos(PersonType::FIRE);
}

const QPointF &ViewModel::get_ice_speed()
{
    return m_model->get_speed(PersonType::ICE);
}

const QPointF &ViewModel::get_fire_speed()
{
    return m_model->get_speed(PersonType::FIRE);
}

