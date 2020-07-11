#pragma once
//ICE_jump_move_command


#ifndef _ICEJUMP_H
#define _ICEJUMP_H

#include"commands.h"
#include"./view_model/ViewModel.h"

class Ice_jump_move_command :public Commands
{
public:
    Ice_jump_move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Ice_jump_command();
    }
private:
    std::shared_ptr<ViewModel> m_VM;
};

#endif // !_ICEJUMP_H
