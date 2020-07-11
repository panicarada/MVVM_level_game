//Fire_jump_move_command


#pragma once
#ifndef _FIREJUMP_H
#define _FIREJUMP_H

#include"Commands.h"
#include"../view_model/ViewModel.h"

class Fire_jump_move_command :public Commands
{
public:
	Fire_jump_move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
	void exec() override
	{
		m_VM->Exec_Fire_jump_command();
	}
private:
	std::shared_ptr<ViewModel> m_VM;
};

#endif // !_FIREJUMP_H