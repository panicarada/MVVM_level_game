#ifndef PERSON_H
#define PERSON_H

#include <QWidget>

enum GameStatus
{
    playing = 0,
    dead,
    pause,
};

// 人物
class Person : public QWidget
{
    Q_OBJECT
public:
    explicit Person(QWidget *parent = nullptr);

private:
    QPoint pos; // 位置

signals:
    void game_status_changed(GameStatus gameStatus);


};

#endif // PERSON_H
