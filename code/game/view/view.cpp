#include "view.h"
#include "ui_view.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include "common/Common.h"
#include <QProcess>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , timer(new QTimer) // 定时器
    , curFrame(0), game_status(PLAYING)
{
    ui->setupUi(this);
    fire_person = QSharedPointer<Person_UI>::create(PersonType::FIRE, this);
    ice_person = QSharedPointer<Person_UI>::create(PersonType::ICE, this);
    map = QSharedPointer<Map_UI>::create(this);
    const int GAP = 1; // 每隔0.001秒触发一次槽函数move
    timer->start(GAP);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // 连接暂停信号
    connect(this, &View::pause_signal, this, &View::react_game_status_change);

    // 屏幕设置，切勿改动！
    // 如果完全贴合图片大小，某些屏幕上可能显示不全
    this->setFixedSize(1100, 900);
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


void View::set_get_ice_pos(const std::function<QPointF (void)>&& func)
{
    this->get_ice_pos = func;
}

void View::set_get_fire_pos(const std::function<QPointF (void)>&& func)
{
    get_fire_pos = func;
}

void View::set_get_ice_speed(const std::function<QPointF (void)>&& func)
{
    get_ice_speed = func;
}

void View::set_get_fire_speed(const std::function<QPointF (void)>&& func)
{
    get_fire_speed = func;
}

void View::keyPressEvent(QKeyEvent *event)
{
    keys_pressed += Qt::Key(event->key());

    /* 1.游戏暂停 */
    if (keys_pressed.contains(Qt::Key_Space))
    { // 暂停或取消暂停
        qDebug() << "Pause";
        emit pause_signal(PAUSE);
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
    map->paint(painter, this->width(), this->height());

    // 绘制人物
    ice_person->paint(painter, curFrame);
    fire_person->paint(painter, curFrame);
}

void View::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->pos() << ",";
}

void View::react_diamond_notification(int id)
{ // 标示码为id的钻石在Model层中被检测到发射有效碰撞，今后不再显示它
    map->remove_diamond(id); // 在地图中删除这一钻石
    map->update(); // 重绘图像
}

void View::react_lever_notification(const int &id, const double &angle, const movable_item_status &status)
{
    map->set_property_lever(id, angle, status);
    //    qDebug() << "lever signal accepted, id = " << id << ", angle = " << angle << ", status = " << status;
}

void View::react_platform_notification(const int &id, const QPointF &pos, const movable_item_status &status)
{
    map->set_property_platform(id, pos, status);
//    qDebug() << "platform signal accepted, id = " << id << ", pos = " << pos << ", status = " << status;
}


void View::react_game_status_change(const GameStatus &status)
{
    if (status == DEAD)
    { // 角色死亡
        qDebug() << "game dead status accepted";
        // 断开计时器连接
        disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));

        // 创建弹窗
        auto msg_box = QSharedPointer<QMessageBox>::create();
        msg_box->setIcon(QMessageBox::Information);
        // tr是为了显示中文
        msg_box->setWindowTitle(tr("提示")); // 设置弹窗标题
        msg_box->setText(tr("通关失败，是否重新游戏？")); // 设置弹窗信息
        msg_box->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg_box->setDefaultButton(QMessageBox::Yes);
        msg_box->button(QMessageBox::Yes)->setText(tr("重启")); // 设置弹窗按钮的文字
        msg_box->button(QMessageBox::No)->setText(tr("退出"));

        msg_box->show();
        // click_result判断用户点击了什么按钮
        auto click_result = msg_box->exec();
        if (click_result == QMessageBox::Yes)
        {
            qDebug() << tr("游戏重启");
            QString program = QApplication::applicationFilePath();
            QStringList arguments = QApplication::arguments();
            QString workingDirectory = QDir::currentPath();
            QProcess::startDetached(program, arguments, workingDirectory);
            QApplication::exit();
        }
        else if (click_result == QMessageBox::No)
        {
            qDebug() << tr("退出游戏");
            this->close();
        }
    }
    else if (status == PAUSE)
    {
        if (game_status == PAUSE)
        { // 正在暂停
            qDebug() << tr("取消暂停");
            connect(timer, SIGNAL(timeout()), this, SLOT(move())); // 重连计时器
            game_status = PLAYING; // 修改游戏状态
        }
        else if (game_status == PLAYING)
        {
            qDebug() << tr("暂停");
            // 清除所有按键
            keys_pressed.clear();

            // 断开计时器连接
            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
            game_status = PAUSE;
            // 创建弹窗
            auto msg_box = QSharedPointer<QMessageBox>::create();
            msg_box->setIcon(QMessageBox::Information);
            // tr是为了显示中文
            msg_box->setWindowTitle(tr("提示")); // 设置弹窗标题
            msg_box->setText(tr("通关失败，是否重新游戏？")); // 设置弹窗信息
            msg_box->setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Save);
            msg_box->setDefaultButton(QMessageBox::Save);
            msg_box->button(QMessageBox::Yes)->setText(tr("重启游戏")); // 设置弹窗按钮的文字
            msg_box->button(QMessageBox::No)->setText(tr("退出"));
            msg_box->button(QMessageBox::Save)->setText(tr("继续游戏"));

            msg_box->show();
            // click_result判断用户点击了什么按钮
            auto click_result = msg_box->exec();
            if (click_result == QMessageBox::Yes)
            {
                qDebug() << tr("游戏重启");
                QString program = QApplication::applicationFilePath();
                QStringList arguments = QApplication::arguments();
                QString workingDirectory = QDir::currentPath();
                QProcess::startDetached(program, arguments, workingDirectory);
                QApplication::exit();
            }
            else if (click_result == QMessageBox::No)
            {
                qDebug() << tr("退出游戏");
                this->close();
            }
            else if (click_result == QMessageBox::Save)
            { // 继续游戏
                emit pause_signal(PAUSE);
            }
        }
    }
}


void View::move()
{
    static int counter = 0;
    counter ++;
    if (counter >= 10)
    {
        curFrame++;
        counter = 0;
    }
    if (curFrame >= 128)
    { // 上限
        curFrame = 0;
    }

//    qDebug() << "Hello World!";
    if (keys_pressed.contains(Qt::Key_A))
    {
//        qDebug() << "ice left";
        ice_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_D))
    {
//        qDebug() << "ice right";
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
        fire_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Right))
    {
//        qDebug() << "fire right";
        fire_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Up))
    {
//        qDebug() << "fire jump";
        fire_jump_command->exec();
    }
    if (get_ice_speed().x() < 0)
    {
        ice_person->set_status(PersonStatus::turningLeft);
    }
    else if (get_ice_speed().x() > 0)
    {
        ice_person->set_status(PersonStatus::turningRight);
    }
    else
    {
        ice_person->set_status(PersonStatus::Facing);
    }

    if (get_fire_speed().x() < 0)
    {
        fire_person->set_status(PersonStatus::turningLeft);
    }
    else if (get_fire_speed().x() > 0)
    {
        fire_person->set_status(PersonStatus::turningRight);
    }
    else
    {
        fire_person->set_status(PersonStatus::Facing);
    }


    move_command->exec();
//    qDebug() << ice_person->pos;
    update();
}
