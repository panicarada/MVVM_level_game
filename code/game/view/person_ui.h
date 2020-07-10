#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>



// 人物形态
enum PersonStatus
{
    turningLeft, // 朝向左
    turningRight,
    Facing, // 面对玩家
};

// 人物
class Person : public QWidget
{
    Q_OBJECT
public:
    explicit Person(QWidget *parent = nullptr);
    void paint(QPainter &);

private:
    QPoint pos; // 位置
    PersonStatus person_status; // 人物形态
};

#endif // PERSON_H
