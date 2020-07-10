#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>
#include "common/Common.h"


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



// 人物移动参数
class moveParameters : public Parameters
{
public:
    moveParameters(bool Left, bool Right, bool Jump, bool Down)
        : Left(Left), Right(Right), Jump(Jump), Down(Down)
    {

    }
private:
    bool Left; // 是否向左
    bool Right; // 是否向右
    bool Jump; // 是否跳跃
    bool Down; // 是否向下
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
