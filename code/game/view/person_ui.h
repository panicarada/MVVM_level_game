#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QPixmap>
#include "./common/Common.h"
#include <QDir>



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
    void paint(QPainter &);
    void set_pos(const QPoint &pos);
    void set_status(const PersonStatus &&status);
private:
    QPoint pos; // 位置
    PersonType person_type;
    PersonStatus person_status; // 人物形态
    QPixmap ice_stand; // 冰人静止图像
    QPixmap fire_stand; // 火人静止图像
};


#endif // PERSON_H
