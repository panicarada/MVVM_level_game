#include "view.h"
#include "ui_view.h"
#include <QDebug>
#include <command/move_command.h>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    fire_person = QSharedPointer<Person>::create(this);
    ice_person = QSharedPointer<Person>::create(this);
}

View::~View()
{
    delete ui;
}

void View::set_game_status_command(QSharedPointer<Commands> command)
{
    game_status_command = command;
}

void View::set_ice_move_command(QSharedPointer<Commands> command)
{
    ice_move_command = command;
}

void View::set_fire_move_command(QSharedPointer<Commands> command)
{
    fire_move_command = command;
}

void View::keyPressEvent(QKeyEvent *event)
{
    keys_pressed += Qt::Key(event->key());

    /* 1.游戏暂停 */
    if (keys_pressed.contains(Qt::Key_Space))
    { // 暂停
        qDebug() << "Pause";
//        game_status_command->set_parameters(
//                    QSharedPointer<gameParameters>::create(GameStatus::pause));
//        game_status_command->exec();
    }
    /* 游戏暂停 */

    /* 2.冰人运动 */
    bool Jump = false;
    bool Down = false;
    bool Left = false;
    bool Right = false;
    // 上与下动作冲突
    if (keys_pressed.contains(Qt::Key_W))
    {
        qDebug() << "ice Jump";
        Jump = true;
    }
    else if (keys_pressed.contains(Qt::Key_S))
    {
        qDebug() << "ice Down";
        Down = true;
    }
    // 左移与右移冲突
    if (keys_pressed.contains(Qt::Key_A))
    {
        qDebug() << "ice Left";
        Left = true;
    }
    else if (keys_pressed.contains(Qt::Key_D))
    {
        qDebug() << "ice Right";
        Right = true;
    }
    // QSharedPointer<T>::create(...)相当于std::make_shared
//    ice_move_command->set_parameters(
//                QSharedPointer<moveParameters>::create(Left, Right, Jump, Down));
    /* 冰人运动 */


    /* 3.火人运动 */
    // 上与下动作冲突
    if (keys_pressed.contains(Qt::Key_Up))
    {
        qDebug() << "fire Jump";
        Jump = true;
    }
    else if (keys_pressed.contains(Qt::Key_Down))
    {
        qDebug() << "fire Down";
        Down = true;
    }
    // 左移与右移冲突
    if (keys_pressed.contains(Qt::Key_Left))
    {
        qDebug() << "fire Left";
        Left = true;
    }
    else if (keys_pressed.contains(Qt::Key_Right))
    {
        qDebug() << "fire Right";
        Right = true;
    }
    // QSharedPointer<T>::create(...)相当于std::make_shared
//    fire_move_command->set_parameters(
//                QSharedPointer<moveParameters>::create(Left, Right, Jump, Down));
    /* 火人运动 */



//    ice_move_command->exec();
//    fire_move_command->exec();
}


void View::keyReleaseEvent(QKeyEvent *event)
{
    if (!keys_pressed.isEmpty())
    {
        keys_pressed -= Qt::Key(event->key());
    }
}

void View::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    ice_person->paint(painter);
    fire_person->paint(painter);
}
