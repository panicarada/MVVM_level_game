#pragma once
//Geometry.h


#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <cmath>
#include <memory>

#define V_MOTIONLESS 0		//?????0
#define V_JUMP 2			//?????10
#define V_MOVE 2
#define D_SPEED 0.5			//?????
#define V_GRAVITY -2		//???????????

class Pos
{
public:
    double x;
    double y;
    Pos() throw() :x(0), y(0) {}
    Pos(double xx, double yy) throw() :x(xx), y(yy) {}
    Pos(const Pos& p) throw() :x(p.x), y(p.y) {}
    Pos(Pos&& p) throw() :x(p.x), y(p.y) {}
    Pos& operator=(const Pos& p) throw();
    Pos& operator=(Pos&& p) throw();
    bool operator==(const Pos& p) throw();
};
class Line
{
public:
    Line() throw() {}
    Line(double x1, double y1, double x2, double y2) throw() :dot1(x1, y1), dot2(x2, y2)
    {
        sin = (y2 - y1) / (sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)));
        cos = (x2 - x1) / (sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)));
    }
    Line(Pos p1, Pos p2) throw() :dot1(p1), dot2(p2)
    {
        sin = (p2.y - p1.y) / (sqrt((p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.y)*(p2.x - p1.x)));
        cos = (p2.x - p1.x) / (sqrt((p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x)));
    }

    const double& get_sin() const throw() { return sin; }
    const double& get_cos() const throw() { return cos; }
    virtual bool isRoof() = 0;

    int location(Pos p) throw();
protected:
    Pos dot1;
    Pos dot2;
    double cos;
    double sin;
};

class Floor :public Line
{
public:
    Floor() throw() :Line() {}
    Floor(double x1, double y1, double x2, double y2) throw() :Line(x1, y1, x2, y2) {}
    Floor(Pos p1, Pos p2) throw() :Line(p1, p2) {}
    virtual bool isRoof() { return false; }
};

class Roof :public Line
{
public:
    Roof() throw() :Line() {}
    Roof(double x1, double y1, double x2, double y2) throw() :Line(x1, y1, x2, y2) {}
    Roof(Pos p1, Pos p2) throw() :Line(p1, p2) {}
    virtual bool isRoof() { return true; }
};

class Velocity
{
public:
    double x;
    double y;
    Velocity() throw() :x(0), y(0) {}
    Velocity(double xx, double yy) throw() :x(xx), y(yy) {}
    Velocity(const Velocity& v) throw() :x(v.x), y(v.y) {}
    Velocity(Velocity&& v) throw() :x(v.x), y(v.y) {}
    Velocity& operator=(const Velocity& v) throw();
    Velocity& operator=(Velocity&& v) throw();
    void split(std::shared_ptr<Line> l) throw();
};

#endif // !_GEOMETRY_H
