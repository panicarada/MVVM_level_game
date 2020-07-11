//ViewModel.cpp


#include"ViewModel.h"
#include"../command/ICE_left_move_command.h"
#include"../command/ICE_right_move_command.h"
#include"../command/ICE_jump_move_command.h"

#include"../command/FIRE_left_move_command.h"
#include"../command/FIRE_right_move_command.h"
#include"../command/FIRE_jump_move_command.h"

ViewModel::ViewModel() throw()
{
	m_model = std::make_shared<Model>();

	Ice_left_command = std::static_pointer_cast<Commands, Ice_left_move_command>(std::make_shared<Ice_left_move_command>(this));
	Ice_right_command = std::static_pointer_cast<Commands, Ice_right_move_command>(std::make_shared<Ice_right_move_command>(this));
	Ice_jump_command = std::static_pointer_cast<Commands, Ice_jump_move_command>(std::make_shared<Ice_jump_move_command>(this));

	Fire_left_command = std::static_pointer_cast<Commands, Fire_left_move_command>(std::make_shared<Fire_left_move_command>(this));
	Fire_right_command = std::static_pointer_cast<Commands, Fire_right_move_command>(std::make_shared<Fire_right_move_command>(this));
	Fire_jump_command = std::static_pointer_cast<Commands, Fire_jump_move_command>(std::make_shared<Fire_jump_move_command>(this));
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