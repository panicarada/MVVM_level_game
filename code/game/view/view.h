#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "person.h"
#include <command/commands.h>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT
public:
    View(QWidget *parent = nullptr);
    ~View() override;
    void set_move_command(QSharedPointer<Commands>);
    void set_reset_command(QSharedPointer<Commands>);

protected:
    void keyPressEvent(QKeyEvent *event) override; // 键盘敲击时间

private slots:

private:
    Ui::View *ui;
    Person ice_person; // 冰人
    Person fire_person; // 火人

    QSharedPointer<Commands> move_command;
    QSharedPointer<Commands> reset_command;
};
#endif // VIEW_H
