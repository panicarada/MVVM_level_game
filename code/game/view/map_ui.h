#ifndef MAP_UI_H
#define MAP_UI_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPoint>

class Map_UI : public QWidget
{
    Q_OBJECT
public:
    explicit Map_UI(QWidget *parent = nullptr);
    void paint(QPainter &);
private:
    QPixmap img;
};

#endif // MAP_UI_H
