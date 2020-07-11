#ifndef GAME_STATUS_COMMAND_H
#define GAME_STATUS_COMMAND_H

#include "commands.h"

class game_status_command : public Commands
{
public:
    game_status_command();
    void exec() override;
};

#endif // GAME_STATUS_COMMAND_H
