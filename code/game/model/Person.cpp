//Person.cpp


#include"Person.h"

Person::Person(std::string name) throw() :m_pos(0, 0), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(0, -10)
{
	m_name = std::make_shared<std::string>(name);
}

void Person::set_map(const std::shared_ptr<Map>& m)
{
	m_map = m;
}

void Person::set_pos_x(double x) throw()
{
	m_pos.x = x;
}

double Person::get_pos_x() throw()
{
	return m_pos.x;
}

void Person::set_pos_y(double y) throw()
{
	m_pos.y = y;
}

double Person::get_pos_y() throw()
{
	return m_pos.y;
}

void Person::set_pos(double x, double y) throw()
{
	m_pos.x = x;
	m_pos.y = y;
}

const Pos& Person::get_pos()
{
	return m_pos;
}

void Person::get_pos(double& x, double& y) throw()
{
	x = m_pos.x;
	y = m_pos.y;
}

const Pos& Person::get_pos_right()
{
	return Pos(m_pos.x + PERSONSIZE_X, m_pos.y);
}

const std::string& Person::get_name() const throw()
{
	return *m_name.get();
}

void Person::set_speed_x(double x) throw()
{
	m_speed.x = x;
}

double Person::get_speed_x() throw()
{
	return m_speed.x;
}

void Person::set_speed_y(double y) throw()
{
	m_speed.y = y;
}

double Person::get_speed_y() throw()
{
	return m_speed.y;
}

Velocity& Person::get_speed() throw()
{
	return m_speed;
}

void Person::set_aerial(bool isAerial) throw()
{
	aerial = isAerial;
}

void Person::move()
{
	m_map->splitVelocity(*this);

	m_pos.x += m_speed.x;
	m_pos.y += m_speed.y;

	//»ºÂý¼õËÙ
	if (aerial)
		if (m_speed.y > V_GRAVITY + D_SPEED)
			m_speed.y -= D_SPEED;
		else m_speed.y = V_GRAVITY;
	else
	{
		m_speed.x = V_MOTIONLESS;
		m_speed.y = V_MOTIONLESS;
	}
}

