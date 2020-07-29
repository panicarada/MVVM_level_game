#ifndef RESTART_COMMAND_H
#define RESTART_COMMAND_H


#include"./common/commands.h"

template <class ViewModel>
class Restart_command :public Commands
{
public:
    Restart_command(QSharedPointer<ViewModel> vm) { m_VM = vm; }
    void exec() override
    {
        m_VM->Exec_Restart_command();
    }
private:
    QSharedPointer<ViewModel> m_VM;
};
#endif // RESTART_COMMAND_H
