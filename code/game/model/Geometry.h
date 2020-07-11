//Geometry.h


#pragma once
#ifndef _GEOMETRY_H
#define _GEEMETRY_H

#include<cmath>

#define V_MOTIONLESS 0		//静止速度为0
#define V_JUMP 2			//起跳速度为10
#define V_MOVE 2
#define D_SPEED 0.5			//速度改变量
#define V_GRAVITY -2		//重力（用恒定速度体现）

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

Pos& Pos::operator=(const Pos& p) throw()
{
	if (this != &p)
	{
		x = p.x;
		y = p.y;
	}
	return *this;
}

Pos& Pos::operator=(Pos&& p) throw()
{
	if (this != &p)
	{
		x = p.x;
		y = p.y;
	}
	return *this;
}

bool Pos::operator==(const Pos& p) throw()
{
	if (x == p.x && y == p.y)
		return true;
	else return false;
}

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

//-1 - 点在线的右下方; 0 - 点在线上; 1 - 点在线的左上方; 2 - 点线无关
int Line::location(Pos p) throw()
{
	if ((p.x < dot1.x&&p.x < dot2.x) || (p.x > dot1.x&&p.x > dot2.x))
						return  2;

	double temp = (p.x - dot1.x) / (dot2.x - dot1.x) - (p.y - dot1.y) / (dot2.y - dot1.y);
	if (temp < 0)		return  1;
	else if (temp == 0) return  0;
	else				return -1;
}

class Floor :public Line
{
public:
	virtual bool isRoof() { return false; }
};

class Roof :public Line
{
public:
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

Velocity& Velocity::operator=(const Velocity& v) throw()
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
	}
	return *this;
}

Velocity& Velocity::operator=(Velocity&& v) throw()
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
	}
	return *this;
}

void Velocity::split(std::shared_ptr<Line> l) throw()
{
	if (l->isRoof())//撞到天花板
	{
		y = -D_SPEED;
	}
	else if (y > 0);//起跳
	else//沿地面移动
	{
		double tempx, tempy;
		tempx = y * l->get_sin()*l->get_cos() + x * l->get_cos()*l->get_cos();
		tempy = y * l->get_sin()*l->get_sin() + x * l->get_cos()*l->get_sin();
		x = tempx;
		y = tempy;
	}
}

#endif // !_GEOMETRY_H

