#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>
#include "./common/Common.h"


class Parameters
{
public:
    Parameters();
};


// 文件路径参数
class PathParameters : public Parameters
{
public:
    PathParameters(std::string path)
        : path(path){}

    std::string get_path()
    {
        return path;
    }
private:
    std::string path;
};


// 游戏状态参数
class gameParameters : public Parameters
{
public:
    gameParameters(GameStatus &&game_status)
        : game_status(game_status){}

private:
    GameStatus game_status;
};



#endif // PARAMETERS_H
