#ifndef DIAMOND_H
#define DIAMOND_H

#include <memory>
#include <string>
#include <QPoint>
#include <QObject>
#include <QSet>
#include <QLineF>
#include <QPointF>
#include <QRectF>
#include <QSharedPointer>
#include <array>
#include "./common/Common.h"

class Diamond
{
public:
    Diamond() = delete; // 拒绝空构造器
    Diamond(const PersonType &&type,  const int &&id, const QPointF &&pos); // 输入的线段都是相对左上角的坐标
    QPointF& get_pos() noexcept;    // 设置钻石位置
    void disable() noexcept;    // 钻石被碰后调用，使其失效
    PersonType& get_type() noexcept; // 获得钻石属性
    int& get_id() noexcept; // 获取钻石标示码
    bool intersect(const QRectF& rect, const PersonType& rect_type); // 判断钻石是否和一个矩形相交
private:
    PersonType type; // 钻石类型（冰人碰冰，火人碰火）
    bool is_exist; // 是否存在
    QPointF pos; // 钻石的坐标（左上角）
    std::array<QLineF, 5> edges;  // 钻石的五条边，坐标都是绝对坐标，但是输入时是用相对坐标
    int id; // 钻石标示码，和view所用一致

    const static std::array<QLineF, 5> rel_lines; // 五条边的相对坐标，对所有的钻石都是一样的
};


#endif // DIAMOND_H
