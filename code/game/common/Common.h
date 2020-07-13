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


#define PERSONSIZE_X 20
#define PERSONSIZE_Y 30

#define V_MOTIONLESS 0		// 静止的速度
#define V_JUMP -0.6			// 跳跃初速度
#define V_MOVE 0.15           // 左右移动速度
#define DY_SPEED 0.002 		// 受重力影响的速度改变量
#define FALL_BOUND 0.7		// 下落过程最大速度
/* 注：坐标系为 */
/*     O ------> x
 *     |                     |
 *     |         画面        |
 *     |                    |
 *     v y
 */


enum PersonType // 人的类型
{
    FIRE = 0,
    ICE
};

#endif // COMMON_H
