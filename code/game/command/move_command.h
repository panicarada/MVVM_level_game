//Move_command


#pragma once
#ifndef _MOVECOMMAND_H
#define _MOVECOMMAND_H

#include"commands.h"
#include"./view_model/ViewModel.h"

class move_command :public Commands
{
public:
    move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_move_command();
    }
private:
    std::shared_ptr<ViewModel> m_VM;
};

#endif // !_MOVECOMMAND_H
