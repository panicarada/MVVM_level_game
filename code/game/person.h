#ifndef PERSON_H
#define PERSON_H

#include <QWidget>

class Person : public QWidget
{
    Q_OBJECT
public:
    explicit Person(QWidget *parent = nullptr);

signals:

};

#endif // PERSON_H
