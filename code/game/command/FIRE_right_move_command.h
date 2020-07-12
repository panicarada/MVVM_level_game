#pragma once
//Fire_right_move_command


#ifndef _FIRERIGHT_H
#define _FIRERIGHT_H

#include"commands.h"
#include"./view_model/ViewModel.h"

class Fire_right_move_command :public Commands
{
public:
    Fire_right_move_command(QSharedPointer<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Fire_right_command();
    }
private:
    QSharedPointer<ViewModel> m_VM;
};

#endif // !_FIRERIGHT_H
