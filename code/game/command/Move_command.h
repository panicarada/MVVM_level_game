//Move_command


#pragma once
#ifndef _MOVECOMMAND_H
#define _MOVECOMMAND_H

#include"Commands.h"
#include"../view_model/ViewModel.h"

class Move_command :public Commands
{
public:
	Move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
	void exec() override
	{
		m_VM->Exec_move_command();
	}
private:
	std::shared_ptr<ViewModel> m_VM;
};

#endif // !_MOVECOMMAND_H