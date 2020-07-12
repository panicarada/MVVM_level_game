#pragma once
//Geometry.h


#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <cmath>
#include "./common/Common.h"
#include <memory>

class Pos
{
public:
    double x;
    double y;
    Pos() noexcept :x(0), y(0) {}
    Pos(double xx, double yy) noexcept :x(xx), y(yy) {}
    Pos(const Pos& p) noexcept :x(p.x), y(p.y) {}
    Pos(Pos&& p) noexcept :x(p.x), y(p.y) {}
    Pos& operator=(const Pos& p) noexcept;
    Pos& operator=(Pos&& p) noexcept;
    bool operator==(const Pos& p) noexcept;
};
class Line
{
public:
    Line() noexcept {}
    Line(double x1, double y1, double x2, double y2) noexcept :dot1(x1, y1), dot2(x2, y2)
    {
        sin = (y2 - y1) / (sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)));
        cos = (x2 - x1) / (sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)));
    }
    Line(Pos p1, Pos p2) noexcept :dot1(p1), dot2(p2)
    {
        sin = (p2.y - p1.y) / (sqrt((p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.y)*(p2.x - p1.x)));
        cos = (p2.x - p1.x) / (sqrt((p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x)));
    }

    const double& get_sin() const noexcept { return sin; }
    const double& get_cos() const noexcept { return cos; }
    virtual bool isRoof() = 0;
    virtual bool isWall() = 0;
    virtual bool isFloor() = 0;

    int location(Pos p) noexcept;
protected:
    Pos dot1;
    Pos dot2;
    double cos;
    double sin;
};

class Floor :public Line
{
public:
    Floor() noexcept :Line() {}
    Floor(double x1, double y1, double x2, double y2) noexcept :Line(x1, y1, x2, y2) {}
    Floor(Pos p1, Pos p2) noexcept :Line(p1, p2) {}
    virtual bool isRoof() { return false; }
    virtual bool isWall() { return false; }
    virtual bool isFloor() { return true; }
};

class Roof :public Line
{
public:
    Roof() noexcept :Line() {}
    Roof(double x1, double y1, double x2, double y2) noexcept :Line(x1, y1, x2, y2) {}
    Roof(Pos p1, Pos p2) noexcept :Line(p1, p2) {}
    virtual bool isRoof() { return true; }
    virtual bool isWall() { return false; }
    virtual bool isFloor() { return false; }
};

class Wall :public Line
{
public:
    Wall() noexcept :Line() {}
    Wall(double x1, double y1, double x2, double y2) noexcept :Line(x1, y1, x2, y2) {}
    Wall(Pos p1, Pos p2) noexcept :Line(p1, p2) {}
    virtual bool isRoof() { return false; }
    virtual bool isWall() { return true; }
    virtual bool isFloor() { return false; }
};

class Velocity
{
public:
    double x;
    double y;
    Velocity() noexcept :x(0), y(0) {}
    Velocity(double xx, double yy) noexcept :x(xx), y(yy) {}
    Velocity(const Velocity& v) noexcept :x(v.x), y(v.y) {}
    Velocity(Velocity&& v) noexcept :x(v.x), y(v.y) {}
    Velocity& operator=(const Velocity& v) noexcept;
    Velocity& operator=(Velocity&& v) noexcept;
    void split(std::shared_ptr<Line> l) noexcept;
};

#endif // !_GEOMETRY_H
