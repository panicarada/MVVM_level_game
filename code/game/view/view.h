#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QSet>
#include "person_ui.h"
#include "command/commands.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT
public:
    View(QWidget *parent = nullptr);
    ~View() override;
    void set_ice_move_command(QSharedPointer<Commands>);
    void set_fire_move_command(QSharedPointer<Commands>);
    void set_game_status_command(QSharedPointer<Commands>);

protected:
    void keyPressEvent(QKeyEvent *event) override; // 键盘按下事件
    void keyReleaseEvent(QKeyEvent *event) override; // 键盘松开事件
    void paintEvent(QPaintEvent *) override; // 绘制事件，通过update()函数激活
private slots:

private:
    Ui::View *ui;
    QSharedPointer<Person> ice_person; // 冰人
    QSharedPointer<Person> fire_person; // 火人
    QSet<Qt::Key> keys_pressed; // 被按下的所有按键
    QSharedPointer<Commands> ice_move_command; // 冰人移动指令
    QSharedPointer<Commands> fire_move_command; // 火人移动指令
    QSharedPointer<Commands> game_status_command; // 游戏状态指令
};
#endif // VIEW_H
