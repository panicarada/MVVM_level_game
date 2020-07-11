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
class Person_UI : public QWidget
{
    Q_OBJECT
public:
    explicit Person_UI(QWidget *parent = nullptr);
    void paint(QPainter &);
    void set_pos(const QPoint &pos);
    void set_status(const PersonStatus &&status);
private:
    QPoint pos; // 位置
    PersonStatus person_status; // 人物形态
};

#endif // PERSON_H
