#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <QPointF>
#include <QLineF>
#include <QRectF>
enum GameStatus
{
    playing = 0,
    dead,
    pause,
    reset, // 游戏重启
};

/* 注：坐标系为 */
/*     O ------> x
 *     |                     |
 *     |         画面        |
 *     |                    |
 *     v y
 */
#define PERSONSIZE_X 40
#define PERSONSIZE_Y 60

#define V_MOTIONLESS 0		// 静止的速度
#define V_JUMP -1.50			// 跳跃初速度
#define V_MOVE 0.7           // 左右移动速度
#define DY_SPEED 0.010 		// 受重力影响的速度改变量
#define FALL_BOUND 0.7		// 下落过程最大速度


#define trigger_lever_angle_threshold_lower_bound 18 // 控制杆角度阈值下界
#define trigger_lever_angle_threshold_upper_bound 162 // 控制杆角度阈值上界
#define platform_speed_threshold 1  // 升降台速度阈值一样，并且升降台只能匀速运动
enum DiamondType
{
    Fire_Diamond = 0,
    Ice_Diamond
};

enum PersonType // 人的类型
{
    FIRE = 0,
    ICE
};

enum WallType // 墙体类型
{ // 碰撞检测中
    SLOPE = 0, // 斜面
    FLOOR = 1, // 地板
    LEFT_BLOCK = 2, // 左墙，检测到碰撞后立刻退回原地
    RIGHT_BLOCK = 3, // 右墙
    CEIL = 4, // 天花板，碰撞后立刻退回原地，并且Y方向速度反向
};

enum movable_item_status // 可移动元件的状态（比如升降台和机关）
{
    MOTIONLESS = 0, // 静止的
    MOVING = 1, // 正在移动
};


// 判断矩形和线段是否相交
bool intersect_rect_segment(const QRectF& rect, const QLineF& segment);


#endif // COMMON_H
