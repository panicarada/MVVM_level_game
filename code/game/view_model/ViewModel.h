//ViewModel.h


#pragma once
#ifndef _VIEWMODEL_H
#define _VIEWMODEL_H

#include"../model/Model.h"
#include"../command/Commands.h"

class ViewModel
{
public:
	ViewModel() throw();

	std::shared_ptr<Commands> get_Ice_left_command();
	std::shared_ptr<Commands> get_Ice_right_command();
	std::shared_ptr<Commands> get_Ice_jump_command();

	std::shared_ptr<Commands> get_Fire_left_command();
	std::shared_ptr<Commands> get_Fire_right_command();
	std::shared_ptr<Commands> get_Fire_jump_command();

	std::shared_ptr<Commands> get_move_command();

	const Pos& get_ice_pos();
	const Pos& get_fire_pos();

	void Exec_Ice_left_command();
	void Exec_Ice_right_command();
	void Exec_Ice_jump_command();

	void Exec_Fire_left_command();
	void Exec_Fire_right_command();
	void Exec_Fire_jump_command();

	void Exec_move_command();

private:

	std::shared_ptr<Model> m_model;

	std::shared_ptr<Commands> Ice_left_command;
	std::shared_ptr<Commands> Ice_right_command;
	std::shared_ptr<Commands> Ice_jump_command;

	std::shared_ptr<Commands> Fire_left_command;
	std::shared_ptr<Commands> Fire_right_command;
	std::shared_ptr<Commands> Fire_jump_command;

	std::shared_ptr<Commands> move_command;
};

#endif // !_VIEWMODEL_H
