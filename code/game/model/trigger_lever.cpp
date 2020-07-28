#include "trigger_lever.h"
#include <QtMath>



const double trigger_lever::length = 3.0;
const double trigger_lever::angular_velocity_threshold = 1.0;

trigger_lever::trigger_lever(const int&& id, QSharedPointer<lifting_platform> platform, const bool&& positive_implies_up, const QPoint &&hinge_pos)
    : id(id), platform(platform), angle(trigger_lever_angle_threshold_lower_bound), angular_velocity(0), status(MOTIONLESS) ,
      positive_implies_up(positive_implies_up) ,hinge_pos(hinge_pos)
{

}

void trigger_lever::trigger_clockwise()
{
    angular_velocity = -angular_velocity_threshold;
    status = MOVING;
}

void trigger_lever::trigger_counter_clockwise()
{
    angular_velocity = angular_velocity_threshold;
    status = MOVING;
}

bool trigger_lever::intersect(const QRectF &rect)
{
    double rad_angle = qDegreesToRadians(angle); // 弧度制角度
    QLineF segment(hinge_pos, hinge_pos + QPointF(length * qCos(rad_angle), -length * qSin(rad_angle)));
    return intersect_rect_segment(rect, segment);
}

double &trigger_lever::get_angle()
{
    return angle;
}

void trigger_lever::move()
{
    if (status == MOVING)
    { // 杆正在旋转
        // 杆本身的旋转
        angle += angular_velocity;
        if (angle <= trigger_lever_angle_threshold_lower_bound)
        { // 角度超出阈值
            angle = trigger_lever_angle_threshold_lower_bound;
            status = MOTIONLESS;
        }
        else if (angle >= trigger_lever_angle_threshold_upper_bound)
        {
            angle = trigger_lever_angle_threshold_upper_bound;
            status = MOTIONLESS;
        }
        // 发射控制杆变化的信号
        emit trigger_lever_notification(id, angle, status);

        // 触发升降台移动
        if (angular_velocity > 0)
        { // 逆时针旋转
            if (positive_implies_up)
            {
                platform->trigger_up();
            }
            else
            {
                platform->trigger_down();
            }
        }
        else
        { // 顺时针旋转
            if (positive_implies_up)
            {
                platform->trigger_down(); // 触发升降台移动
            }
            else
            {
                platform->trigger_up();
            }
        }
        platform->move();
    }
}
