#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QPixmap>
#include "./common/Common.h"
#include <QDir>
#include <array>


// 人物形态
enum PersonStatus
{
    turningLeft, // 朝向左
    turningRight,
    Facing, // 面对玩家
};

// 人物
class Person_UI : public QWidget
{
    Q_OBJECT
public:
    explicit Person_UI(const PersonType &&person_type, QWidget *parent = nullptr);
    void paint(QPainter &, int Frame); // 人物在不同帧下的绘制方法
    void set_pos(const QPoint &pos);
    void set_speed(const QPoint &speed);
    void set_status(const PersonStatus &&status);
private:
    QPoint pos; // 位置
    QPoint speed; // 速度
    PersonType person_type; // 人物类型
    PersonStatus person_status; // 人物形态

    // 图像数据声明为静态数组
    std::array<QPixmap, 4> idle_pics; // 静止时的图像
    std::array<QPixmap, 4> left_pics; // 向左运动时的图像
    std::array<QPixmap, 4> right_pics; // 向右运动时的图像
};


#endif // PERSON_H
