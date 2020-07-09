#include "view.h"
#include "ui_view.h"
#include <QDebug>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    { // 空格键
        qDebug() << "Jump";
    }
    else if (event->key() == Qt::Key_A)
    {
        qDebug() << "Left";
    }
    else if (event->key() == Qt::Key_D)
    {
        qDebug() << "Right";
    }
}

