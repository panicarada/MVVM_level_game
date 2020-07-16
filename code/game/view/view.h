#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QSet>
#include <QTimer>
#include <QPoint>
#include "person_ui.h"
#include "map_ui.h"
#include "./command/commands.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT
public:
    View(QWidget *parent = nullptr);
    ~View() override;
    void set_game_status_command(QSharedPointer<Commands>);
    void set_ice_jump_command(QSharedPointer<Commands>);
    void set_ice_left_command(QSharedPointer<Commands>);
    void set_ice_right_command(QSharedPointer<Commands>);
    void set_fire_jump_command(QSharedPointer<Commands>);
    void set_fire_left_command(QSharedPointer<Commands>);
    void set_fire_right_command(QSharedPointer<Commands>);
    void set_move_command(QSharedPointer<Commands>);

    void set_get_ice_pos(const std::function<QPoint(void)>&&);
    void set_get_fire_pos(const std::function<QPoint(void)>&&);
    void set_get_ice_speed(const std::function<QPoint(void)>&&);
    void set_get_fire_speed(const std::function<QPoint(void)>&&);


protected:
    void keyPressEvent(QKeyEvent *event) override; // 键盘按下事件
    void keyReleaseEvent(QKeyEvent *event) override; // 键盘松开事件
    void paintEvent(QPaintEvent *) override; // 绘制事件，通过update()函数激活
private slots:
    void move(); // 每隔一段时间就触发move_command
private:
    Ui::View *ui;
    QSharedPointer<Person_UI> ice_person; // 冰人
    QSharedPointer<Person_UI> fire_person; // 火人
    QSharedPointer<Map_UI> map; // 地图
    QSet<Qt::Key> keys_pressed; // 被按下的所有按键
    QSharedPointer<Commands> game_status_command; // 游戏状态指令
    QSharedPointer<Commands> ice_jump_command; // 冰人跳跃指令
    QSharedPointer<Commands> ice_left_command; // 冰人左移指令
    QSharedPointer<Commands> ice_right_command; // 冰人右移指令
    QSharedPointer<Commands> fire_jump_command; // 火人跳跃指令
    QSharedPointer<Commands> fire_left_command; // 火人左移指令
    QSharedPointer<Commands> fire_right_command; // 火人右移指令
    QSharedPointer<Commands> move_command; // 刷新位移指令

    std::function<QPoint(void)> get_ice_pos; // 获取冰人位置
    std::function<QPoint(void)> get_fire_pos; // 获取火人位置
    std::function<QPoint(void)> get_ice_speed; // 获取冰人速度
    std::function<QPoint(void)> get_fire_speed; // 获取火人速度


    QTimer* timer;
    int curFrame; // 用于绘制地图，记录帧数
};
#endif // VIEW_H
