#ifndef COMMON_H
#define COMMON_H
#include <iostream>

enum GameStatus
{
    playing = 0,
    dead,
    pause,
    reset, // 游戏重启
};


#define PERSONSIZE_X 50
#define PERSONSIZE_Y 100

#define V_MOTIONLESS 0		//?????0
#define V_JUMP 2			//?????10
#define V_MOVE 2
#define D_SPEED 0.5			//?????
#define V_GRAVITY -2		//???????????


#endif // COMMON_H
