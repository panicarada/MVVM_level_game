//Geometry.cpp


#include"Geometry.h"



Pos& Pos::operator=(const Pos& p) noexcept
{
    if (this != &p)
    {
        x = p.x;
        y = p.y;
    }
    return *this;
}

Pos& Pos::operator=(Pos&& p) noexcept
{
    if (this != &p)
    {
        x = p.x;
        y = p.y;
    }
    return *this;
}

bool Pos::operator==(const Pos& p) noexcept
{
    if (x == p.x && y == p.y)
        return true;
    else return false;
}

//-1 - ???????; 0 - ????; 1 - ???????; 2 - ????
int Line::location(Pos p) noexcept
{
    if ((p.x < dot1.x&&p.x < dot2.x) || (p.x > dot1.x&&p.x > dot2.x))
                        return  2;

    double temp = (p.x - dot1.x) / (dot2.x - dot1.x) - (p.y - dot1.y) / (dot2.y - dot1.y);
    if (temp < 0)		return  1;
    else if (temp == 0) return  0;
    else				return -1;
}

Velocity& Velocity::operator=(const Velocity& v) noexcept
{
    if (this != &v)
    {
        x = v.x;
        y = v.y;
    }
    return *this;
}

Velocity& Velocity::operator=(Velocity&& v) noexcept
{
    if (this != &v)
    {
        x = v.x;
        y = v.y;
    }
    return *this;
}

void Velocity::split(std::shared_ptr<Line> l) noexcept
{
    if (l->isRoof())//?????
    {
        y = -D_SPEED;
    }
    else if (y > 0);//??
    else//?????
    {
        double tempx, tempy;
        tempx = y * l->get_sin()*l->get_cos() + x * l->get_cos()*l->get_cos();
        tempy = y * l->get_sin()*l->get_sin() + x * l->get_cos()*l->get_sin();
        x = tempx;
        y = tempy;
    }
}
