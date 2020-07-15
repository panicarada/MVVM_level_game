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
#define V_JUMP -0.9			// 跳跃初速度
#define V_MOVE 0.15           // 左右移动速度
#define DY_SPEED 0.004 		// 受重力影响的速度改变量
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

enum WallType // 墙体类型
{ // 碰撞检测中，存在优先级BLOCK = CEIL > FLOOR > SLOPE
    SLOPE = 0, // 斜面
    FLOOR = 1, // 地板
    LEFT_BLOCK = 2, // 左墙，检测到碰撞后立刻退回原地
    RIGHT_BLOCK = 3, // 右墙
    CEIL = 4, // 天花板，碰撞后立刻退回原地，并且Y方向速度反向
};

#endif // COMMON_H
