#include "move_command.h"
#include <QDebug>

move_command::move_command()
{

}

void move_command::exec()
{
    qDebug() << "Moving!";
}
