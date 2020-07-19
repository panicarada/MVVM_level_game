#pragma once
//ICE_right_move_command


#ifndef _ICERIGHT_H
#define _ICERIGHT_H

#include"commands.h"
#include"./view_model/ViewModel.h"

class Ice_right_move_command :public Commands
{
public:
    Ice_right_move_command(QSharedPointer<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Ice_right_command();
    }
private:
    QSharedPointer<ViewModel> m_VM;
};

#endif // !_ICERIGHT_H
