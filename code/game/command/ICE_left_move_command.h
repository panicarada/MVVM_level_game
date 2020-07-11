//ICE_left_move_command


#pragma once
#ifndef _ICELEFT_H
#define _ICELEFT_H

#include"commands.h"
#include"./view_model/ViewModel.h"

class Ice_left_move_command :public Commands
{
public:
    Ice_left_move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Ice_left_command();
    }
private:
    std::shared_ptr<ViewModel> m_VM;
};

#endif // !_ICELEFT_H
