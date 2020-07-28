#include "app/app.h"

#include <QApplication>
#include <QPixmap>
#include <QtMath>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App app;
    app.run();
    return a.exec();
}
