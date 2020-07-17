#pragma once
//ICE_left_move_command


#ifndef _ICELEFT_H
#define _ICELEFT_H

#include"./common/commands.h"


template <class ViewModel>
class Ice_left_move_command :public Commands
{
public:
    Ice_left_move_command(QSharedPointer<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Ice_left_command();
    }
private:
    QSharedPointer<ViewModel> m_VM;
};

#endif // !_ICELEFT_H
