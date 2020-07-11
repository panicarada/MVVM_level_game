//Fire_left_move_command


#pragma once
#ifndef _FIRELEFT_H
#define _FIRELEFT_H

#include"commands.h"
#include"./view_model/ViewModel.h"

class Fire_left_move_command :public Commands
{
public:
    Fire_left_move_command(std::shared_ptr<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Fire_left_command();
    }
private:
    std::shared_ptr<ViewModel> m_VM;
};

#endif // !_FIRELEFT_H
