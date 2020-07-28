#ifndef TRIGGER_LEVER_UI_H
#define TRIGGER_LEVER_UI_H
#include <QPixmap>
#include <QPoint>
#include <QWidget>
#include <QPainter>
#include "./common/Common.h"

// 控制杆
class trigger_lever_ui : public QWidget
{
    Q_OBJECT
public:
    explicit trigger_lever_ui(const int&& id, const QPoint&& pos, QWidget *parent = nullptr);
    void set_angle(const double& angle); // 设置旋转角度，逆时针为正，角度制
    void set_status(const movable_item_status& status); // 设置运动状态
    int& get_id();
    void paint(QPainter &);

private:
    int id;
    double angle; // 当前旋转角度，以逆时针为正方向，角度制
    movable_item_status status; // 当前运动状态
    QPixmap img_motionless; // 静止时的图像
    QPixmap img_moving; // 移动时的图像
    QPoint hinge_pos; // 转轴的位置
};

#endif // TRIGGER_LEVER_UI_H
