#ifndef LIFTING_PLATFORM_UI_H
#define LIFTING_PLATFORM_UI_H
#include <QPixmap>
#include <QPoint>
#include <QWidget>
#include <QPainter>
#include "./common/Common.h"


// 升降台
class lifting_platform_ui : public QWidget
{
    Q_OBJECT
public:
    explicit lifting_platform_ui(const int&& id, const QPoint&& pos, QWidget *parent = nullptr);
    void set_pos(const QPoint& pos); // 设置旋转角度，逆时针为正，角度制
    void set_status(const movable_item_status& status); // 设置运动状态
    int& get_id();
    void paint(QPainter &);

private:
    int id;
    QPoint pos; // 左上角坐标
    movable_item_status status; // 当前运动状态
    QPixmap img_motionless; // 静止时的图像
    QPixmap img_moving; // 移动时的图像
};


#endif // LIFTING_PLATFORM_UI_H
