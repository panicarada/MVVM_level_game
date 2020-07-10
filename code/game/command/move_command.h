#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H
#include "commands.h"


class move_command : public Commands
{
public:
    move_command();
    void exec() override;
};

#endif // MOVE_COMMAND_H
