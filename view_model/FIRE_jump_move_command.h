#pragma once
//Fire_jump_move_command


#ifndef _FIREJUMP_H
#define _FIREJUMP_H

#include"./common/commands.h"

template <class ViewModel>
class Fire_jump_move_command :public Commands
{
public:
    Fire_jump_move_command(QSharedPointer<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Fire_jump_command();
    }
private:
    QSharedPointer<ViewModel> m_VM;
};

#endif // !_FIREJUMP_H
