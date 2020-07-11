//Fire_right_move_command


#pragma once
#ifndef _FIRERIGHT_H
#define _FIRERIGHT_H

#include"Commands.h"
#include"../view_model/ViewModel.h"

class Fire_right_move_command :public Commands
{
public:
	Fire_right_move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
	void exec() override
	{
		m_VM->Exec_Fire_right_command();
	}
private:
	std::shared_ptr<ViewModel> m_VM;
};

#endif // !_FIRERIGHT_H