#include "lifting_platform.h"


const int lifting_platform::width = 112;
const int lifting_platform::height = 20;

lifting_platform::lifting_platform(const int&& id, const QPointF &&pos, const double &&pos_lb, const double &&pos_ub)
    : id(id), speed(0), pos(pos), pos_lower_bound(pos_lb), pos_upper_bound(pos_ub), status(MOTIONLESS),
      left_edge(QSharedPointer<Wall>::create(QLineF(pos, pos + QPointF(0, height)), RIGHT_BLOCK)),
      right_edge(QSharedPointer<Wall>::create(QLineF(pos + QPointF(width, 0), pos + QPointF(width, height)), LEFT_BLOCK)),
      upper_edge(QSharedPointer<Wall>::create(QLineF(pos, pos + QPointF(width, 0)), FLOOR)),
      lower_edge(QSharedPointer<Wall>::create(QLineF(pos + QPointF(0, height), pos + QPointF(width, height)), CEIL))
{

}

void lifting_platform::move()
{
    if (status == MOVING)
    {
        QPointF last_pos = pos;
        pos.setY(pos.y() + speed);
        if (pos.y() >= pos_lower_bound)
        { // 低于下界位置
            pos.setY(pos_lower_bound);
            status = MOTIONLESS; // 设置为静止
        }
        else if (pos.y() <= pos_upper_bound)
        { // 高于上界位置
            pos.setY(pos_upper_bound);
            status = MOTIONLESS; // 设置为静止
        }
        // 四条边也跟着移动
        left_edge->translate(pos - last_pos);
        right_edge->translate(pos - last_pos);
        upper_edge->translate(pos - last_pos);
        lower_edge->translate(pos - last_pos);


        emit lifting_platform_notification(id, pos, status); // 发射当前状态的信号
    }
}

QSharedPointer<Wall> lifting_platform::intersect(const QRectF &rect)
{
    if (left_edge->intersect(rect)) return left_edge;
    else if (right_edge->intersect(rect)) return right_edge;
    else if (upper_edge->intersect(rect)) return upper_edge;
    else if (lower_edge->intersect(rect)) return lower_edge;
    return nullptr;
}

void lifting_platform::trigger_up()
{
    speed = -platform_speed_threshold;
    status = MOVING;
}

void lifting_platform::trigger_down()
{
    speed = platform_speed_threshold;
    status = MOVING;
}
