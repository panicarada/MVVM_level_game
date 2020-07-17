#pragma once
//ICE_jump_move_command


#ifndef _ICEJUMP_H
#define _ICEJUMP_H

#include"./common/commands.h"


template <class ViewModel>
class Ice_jump_move_command :public Commands
{
public:
    Ice_jump_move_command(QSharedPointer<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Ice_jump_command();
    }
private:
    QSharedPointer<ViewModel> m_VM;
};

#endif // !_ICEJUMP_H
