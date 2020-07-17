#include "view.h"
#include "ui_view.h"
#include <QDebug>
#include "common/Common.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , timer(new QTimer) // 定时器
    , curFrame(0)
{
    ui->setupUi(this);
    fire_person = QSharedPointer<Person_UI>::create(PersonType::FIRE, this);
    ice_person = QSharedPointer<Person_UI>::create(PersonType::ICE, this);
    map = QSharedPointer<Map_UI>::create(this);
    const int GAP = 1; // 每隔0.001秒触发一次槽函数move
    timer->start(GAP);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

View::~View()
{
    delete ui;
}

void View::set_game_status_command(QSharedPointer<Commands> command)
{
    game_status_command = command;
}

void View::set_ice_jump_command(QSharedPointer<Commands> command)
{
    ice_jump_command = command;
}

void View::set_ice_left_command(QSharedPointer<Commands> command)
{
    ice_left_command = command;
}

void View::set_ice_right_command(QSharedPointer<Commands> command)
{
    ice_right_command = command;
}

void View::set_fire_jump_command(QSharedPointer<Commands> command)
{
    fire_jump_command = command;
}

void View::set_fire_left_command(QSharedPointer<Commands> command)
{
    fire_left_command = command;
}

void View::set_fire_right_command(QSharedPointer<Commands> command)
{
    fire_right_command = command;
}

void View::set_move_command(QSharedPointer<Commands> command)
{
    move_command = command;
}


void View::set_get_ice_pos(const std::function<QPoint (void)>&& func)
{
    this->get_ice_pos = func;
}

void View::set_get_fire_pos(const std::function<QPoint (void)>&& func)
{
    get_fire_pos = func;
}

void View::set_get_ice_speed(const std::function<QPoint (void)>&& func)
{
    get_ice_speed = func;
}

void View::set_get_fire_speed(const std::function<QPoint (void)>&& func)
{
    get_fire_speed = func;
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
    QPainter painter(this); // 构建画笔
//    qDebug() << this->size();

    ice_person->set_pos(get_ice_pos());
    fire_person->set_pos(get_fire_pos());
    ice_person->set_speed(get_ice_speed());
    fire_person->set_speed(get_fire_speed());

    // 绘制地图
    map->paint(painter);

    // 绘制人物
    ice_person->paint(painter, curFrame);
    fire_person->paint(painter, curFrame);
}

void View::move()
{
    curFrame ++;
    if (curFrame >= 128)
    { // 上限
        curFrame = 0;
    }

//    qDebug() << "Hello World!";
    if (keys_pressed.contains(Qt::Key_A))
    {
//        qDebug() << "ice left";
        ice_person->set_status(PersonStatus::turningLeft);
        ice_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_D))
    {
//        qDebug() << "ice right";
        ice_person->set_status(PersonStatus::turningRight);
        ice_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_W))
    {
//        qDebug() << "ice jump";
        ice_jump_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Left))
    {
//        qDebug() << "fire left";
        fire_person->set_status(PersonStatus::turningLeft);
        fire_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Right))
    {
//        qDebug() << "fire right";
        fire_person->set_status(PersonStatus::turningRight);
        fire_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Up))
    {
//        qDebug() << "fire jump";
        fire_jump_command->exec();
    }

    move_command->exec();
//    qDebug() << ice_person->pos;
    update();
}
