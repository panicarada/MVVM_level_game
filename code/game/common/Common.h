#ifndef COMMON_H
#define COMMON_H
#include <iostream>

enum GameStatus
{
    playing = 0,
    dead,
    pause,
    reset, // 游戏重启
};


#define PERSONSIZE_X 50
#define PERSONSIZE_Y 100

#define V_MOTIONLESS 0		// 静止的速度
#define V_JUMP 10			// 跳跃初速度
#define V_MOVE 10           // 左右移动速度
#define DY_SPEED 1  		// 受重力影响的速度改变量
#define FALL_BOUND -4		// 下落过程最大速度


enum PersonType // 人的类型
{
    FIRE = 0,
    ICE
};

#endif // COMMON_H
