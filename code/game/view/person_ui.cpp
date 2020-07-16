#include "person_ui.h"
#include "./common/Common.h"
#include <QDebug>
#include <QDir>


Person_UI::Person_UI(const PersonType &&person_type, QWidget *parent)
    : QWidget(parent), person_type(person_type)
{
    Assets.load(":/source/image/Assets.png");
    Assets_left.load(":/source/image/Assets_left.png");
}



/*************************************
 *  |
 * -O------------------------>X轴正方向
 *  |
 *  |
 *  |
 *  |
 *  |
 *  ↓
 * Y轴正方向
*************************************/

int fire_head_idle[4][4] =
{
    {134,862,130,162},
    {268,862,130,162},
    {402,862,130,162},
    {536,862,130,162}
};

int fire_legs_idle[4] =
{
    134,354,130,172
};

//通关离开
int fire_stairs[6][4] = {
    {1962,292,71,103},
    {328,1341,71,103},
    {858,1571,71,103},
    {424,1652,71,103},
    {106,1674,71,103},
    {181,1674,71,103},
};

int fire_legs_running[6][4] =
{
    {1004,226,130,172},
    {1138,226,130,172},
    {1272,226,130,172},
    {1406,310,130,172},
    {1540,310,130,172},
    {1674,310,130,172},
};

int fire_legs_running_left[6][4] =
{
    {886,226,130,172},
    {752,226,130,172},
    {618,226,130,172},
    {484,310,130,172},
    {350,310,130,172},
    {216,310,130,172},
};

int fire_head_right[4][4] =
{
    {856,1058,156,130},
    {1016,1058,156,130},
    {1176,1058,156,130},
    {1336,1132,156,130}
};

int fire_head_left[5][4] =
{
    {1036,1058,156,130},
    {876,1058,156,130},
    {716,1058,156,130},
    {556,1132,156,130}
};

int ice_head_idle[4][4] =
{
    {1340,468,130,162},
    {1474,468,130,162},
    {1608,468,130,162},
    {1742,468,130,162}
};

int ice_legs_idle[4] =
{
    890,208,130,172
};


int ice_legs_running[6][4] =
{
    {248,365,130,172},
    {382,365,130,172},
    {516,365,130,172},
    {650,365,130,172},
    {784,395,130,172},
    {918,395,130,172}
};

int ice_legs_running_left[6][4] =
{
    {1630,365,130,172},
    {1496,365,130,172},
    {1362,365,130,172},
    {1228,365,130,172},
    {1094,395,130,172},
    {960,395,130,172}
};

//int ice_head_right[5][4] =
//{
//    {0,208,174,142},
//    {178,208,174,142},
//    {356,208,174,142},
//    {534,208,174,142},
//    {712,208,174,142}
//};

int ice_head_right[5][4] =
{
    {1474,0,174,142},
    {1652,0,174,142},
    {1830,0,174,142},
    {1474,146,174,142},
    {1652,146,174,142}
};

int ice_head_left[5][4] =
{
    {400,0,174,142},
    {222,0,174,142},
    {44,0,174,142},
    {400,146,174,142},
    {222,146,174,142}
};

int ice_head_jump[6][4] =
{
    {1474,0,174,142},
    {1652,0,174,142},
    {1830,0,174,142},
    {1474,146,174,142},
    {1652,146,174,142},
    {1830,146,174,142}
};


void Person_UI::paint(QPainter &painter, int Frame)
{

    int i = Frame % 4;
    int j = Frame % 6;


    if (person_type == ICE)
    { // 冰人
        if(person_status == turningLeft)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),Assets_left, ice_head_left[i][0], ice_head_left[i][1], ice_head_left[i][2], ice_head_left[i][3]);
            painter.drawPixmap(pos.rx(), pos.ry(),Assets_left, ice_legs_running_left[j][0], ice_legs_running_left[j][1], ice_legs_running_left[j][2], ice_legs_running_left[j][3]);
        }
        else if(person_status == turningRight)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, ice_head_right[i][0], ice_head_right[i][1], ice_head_right[i][2], ice_head_right[i][3]);
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, ice_legs_running[j][0], ice_legs_running[j][1], ice_legs_running[j][2], ice_legs_running[j][3]);
        }
        else
        {
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, ice_head_idle[i][0], ice_head_idle[i][1], ice_head_idle[i][2], ice_head_idle[i][3]);
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, ice_legs_idle[0],ice_legs_idle[1],ice_legs_idle[2],ice_legs_idle[3]);
        }

    }
    else
    {
 //       qDebug()<<speed;
        if(person_status == turningLeft)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),Assets_left, fire_head_left[i][0], fire_head_left[i][1], fire_head_left[i][2], fire_head_left[i][3]);
            painter.drawPixmap(pos.rx(), pos.ry(),Assets_left, fire_legs_running_left[j][0], fire_legs_running_left[j][1], fire_legs_running_left[j][2], fire_legs_running_left[j][3]);
        }
        else if(person_status == turningRight)
        {
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, fire_head_right[i][0], fire_head_right[i][1], fire_head_right[i][2], fire_head_right[i][3]);
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, fire_legs_running[j][0], fire_legs_running[j][1], fire_legs_running[j][2], fire_legs_running[j][3]);
        }
        else
        {
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, fire_head_idle[i][0], fire_head_idle[i][1], fire_head_idle[i][2], fire_head_idle[i][3]);
            painter.drawPixmap(pos.rx(), pos.ry(),Assets, fire_legs_idle[0],fire_legs_idle[1],fire_legs_idle[2],fire_legs_idle[3]);
        }
    }
  //  qDebug() << pos;

}


void Person_UI::set_pos(const QPoint &pos)
{
    this->pos = pos;
}

void Person_UI::set_speed(const QPoint &speed)
{
    this->speed = speed;
}

void Person_UI::set_status(const PersonStatus &&status)
{
    this->person_status = status;
}
