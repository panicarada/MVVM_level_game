#ifndef COMMANDS_H
#define COMMANDS_H

#include "parameter/parameters.h"
#include <QSharedPointer>

class Commands
{
public:
    Commands();
public:
    // 即std::shared_ptr
    QSharedPointer<Parameters> params;
    void set_parameters(QSharedPointer<Parameters> parameters)
    {
        params = parameters;
    }

    // 执行程序
    virtual void exec() = 0;
};

#endif // COMMANDS_H
