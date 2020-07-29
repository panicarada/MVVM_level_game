#ifndef TRIGGER_LEVER_H
#define TRIGGER_LEVER_H
#include "lifting_platform.h"
#include <QSharedPointer>
#include "./common/Common.h"
#include <QObject>

// 控制升降台的杠杆

class trigger_lever : public QObject
{
    Q_OBJECT
public:
    trigger_lever(const int&& id, QSharedPointer<lifting_platform> platform, const bool&& positive_imples_up,const QPoint&& hinge_pos);
    void move();
    void trigger_clockwise(); // 顺时针方向触发旋转
    void trigger_counter_clockwise(); // 逆时针方向触发旋转
    bool intersect(const QRectF& rect); // 判断人物是否和控制杆相碰
    double &get_angle(); // 获取当前角度，角度制
signals:
    // 控制杆状态发生变化后发射出的信号
    void trigger_lever_notification(const int& id, const double& angle, const movable_item_status& status);

private:
    int id; // 唯一标示码
    QSharedPointer<lifting_platform> platform; // 每个控制杆控制一个升降台
    double angle; // 旋转角度（以逆时针方向为正）（角度制）
    double angular_velocity; // 当前角速度（角度制）
    movable_item_status status; // 控制杆当前状态
    const bool positive_implies_up; // 正方向（逆时针）旋转是否意味着让升降台上升
    const QPoint hinge_pos; // 控制杆转轴的位置，在初始化时固定
    const static double length; // 控制杆的长度
    const static double angular_velocity_threshold; // 角速度阈值
};

#endif // TRIGGER_LEVER_H
