#pragma once


#ifndef _VIEWMODEL_H
#define _VIEWMODEL_H

#include"./model/Model.h"
#include <QSharedDataPointer>
#include "./common/commands.h"
#include "FIRE_jump_move_command.h"
#include "FIRE_left_move_command.h"
#include "FIRE_right_move_command.h"
#include "ICE_jump_move_command.h"
#include "ICE_left_move_command.h"
#include "ICE_right_move_command.h"
#include "move_command.h"

#include <QEnableSharedFromThis>



class ViewModel
{
public:
    ViewModel() noexcept;

    const QPointF& get_ice_pos();
    const QPointF& get_fire_pos();
    const QPointF& get_ice_speed();
    const QPointF& get_fire_speed();

    void Exec_Ice_left_command();
    void Exec_Ice_right_command();
    void Exec_Ice_jump_command();

    void Exec_Fire_left_command();
    void Exec_Fire_right_command();
    void Exec_Fire_jump_command();

    void Exec_move_command();


    // 构造并绑定命令指针
    void setup_command(QSharedPointer<ViewModel> vm);

    // 获取命令指针
    QSharedPointer<Commands> get_fire_jump_move_command();
    QSharedPointer<Commands> get_fire_left_move_command();
    QSharedPointer<Commands> get_fire_right_move_command();
    QSharedPointer<Commands> get_ice_jump_move_command();
    QSharedPointer<Commands> get_ice_left_move_command();
    QSharedPointer<Commands> get_ice_right_move_command();
    QSharedPointer<Commands> get_move_command();

private:
    QSharedPointer<Model> m_model; // 指向对应模型的指针
    // 指向各种命令的指针
    QSharedPointer<Fire_jump_move_command<ViewModel>> fire_jump_move_command;
    QSharedPointer<Fire_left_move_command<ViewModel>> fire_left_move_command;
    QSharedPointer<Fire_right_move_command<ViewModel>> fire_right_move_command;
    QSharedPointer<Ice_jump_move_command<ViewModel>> ice_jump_move_command;
    QSharedPointer<Ice_left_move_command<ViewModel>> ice_left_move_command;
    QSharedPointer<Ice_right_move_command<ViewModel>> ice_right_move_command;
    QSharedPointer<Move_command<ViewModel>> move_command;
};

#endif // !_VIEWMODEL_H
