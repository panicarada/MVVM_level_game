#pragma once
//ViewModel.h


#ifndef _VIEWMODEL_H
#define _VIEWMODEL_H

#include"./model/Model.h"
#include <QSharedDataPointer>
#include"./command/commands.h"

class ViewModel
{
public:
    ViewModel() noexcept;

    const QPoint& get_ice_pos();
    const QPoint& get_fire_pos();

    void Exec_Ice_left_command();
    void Exec_Ice_right_command();
    void Exec_Ice_jump_command();

    void Exec_Fire_left_command();
    void Exec_Fire_right_command();
    void Exec_Fire_jump_command();

    void Exec_move_command();

private:
    QSharedPointer<Model> m_model; // 指向对应模型的指针
};

#endif // !_VIEWMODEL_H
