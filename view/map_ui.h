#ifndef MAP_UI_H
#define MAP_UI_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPoint>
#include "./common/Common.h"
#include "lifting_platform_ui.h"
#include "trigger_lever_ui.h"

class Diamond_UI
{
public:
    int id; // id
    QPoint pos; // 钻石左上角的位置
    PersonType type; // 钻石类型
public:
    Diamond_UI(const int &&id, const QPoint&& pos, const PersonType&& type)
        : id(id), pos(pos), type(type)
    {

    }
};

class Map_UI : public QWidget
{
    Q_OBJECT
public:
    explicit Map_UI(QWidget *parent = nullptr);
    void paint(QPainter &,int width, int height);
    void remove_diamond(const int& id); // 移除标示码为id的钻石，以后不再绘制
    void set_property_lever(const int& id, const double& angle, const movable_item_status& status); // 设置控制杆的属性
    void set_property_platform(const int& id, const QPointF& pos, const movable_item_status& status); // 设置升降台的属性

private:
    QPixmap background; // 地图图像
    QPixmap img_fire_diamond; // 火属性钻石图像
    QPixmap img_ice_diamond; // 冰属性钻石图像
    QSet<QSharedPointer<Diamond_UI>> diamonds; // 钻石集合
    QSet<QSharedPointer<trigger_lever_ui>> levers; // 控制杆集合
    QSet<QSharedPointer<lifting_platform_ui>> platforms; // 升降台集合
};

#endif // MAP_UI_H
