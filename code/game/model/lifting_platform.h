#ifndef LIFTING_PLATFORM_H
#define LIFTING_PLATFORM_H
#include <QPointF>
#include <QObject>
#include <QLineF>
#include <QSharedPointer>

#include "./common/Common.h"
#include "wall.h"

// 升降台

class lifting_platform : public QObject
{
    Q_OBJECT
public:
    lifting_platform(const int&& id, const QPointF&& pos, const double&& pos_lb, const double&& pos_ub);
    void move(); // 移动平台
    movable_item_status get_status(); // 获取运动状态
    double get_speed(); // 获取当前运动速度
    QSharedPointer<Wall> intersect(const QRectF& rect); // 判断人物是否和升降台相碰
    void trigger_up(); // 触发升降台向上运动
    void trigger_down(); // 触发升降台向下运动

signals:
    // 升降台状态发生变化后发射出的信号
    void lifting_platform_notification(const int& id, const QPointF& pos, const movable_item_status& status);

private:
    int id; // 唯一标示码
    double speed; // 当前移动速度（y方向）
    QPointF pos; // 左上角位置
    const double pos_lower_bound; // 最低的位置
    const double pos_upper_bound; // 最高的位置
    movable_item_status status; // 升降台状态，静止或移动
    const static int width;
    const static int height;

    // 对应矩形的四条边，看成四面墙
    QSharedPointer<Wall> left_edge;
    QSharedPointer<Wall> right_edge;
    QSharedPointer<Wall> upper_edge;
    QSharedPointer<Wall> lower_edge;
};

#endif // LIFTING_PLATFORM_H
