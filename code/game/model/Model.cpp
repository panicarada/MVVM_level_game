//Model.cpp


#include"Model.h"

Model::Model() throw()
{
	m_map = std::make_shared<Map>();
	ice_person = std::make_shared<Person>("ice_person");
	ice_person->set_pos(5, 15);
	fire_person = std::make_shared<Person>("fire_person");
	ice_person->set_pos(5, 15);
	m_map->set_ice_person(ice_person);
	m_map->set_fire_person(fire_person);
	ice_person->set_map(m_map);
	fire_person->set_map(m_map);
}

void Model::set_speed(double v_x, double v_y, int person) throw()//person: 0-ice; 1-fire
{
	if (person == 0)
	{
		ice_person->set_speed_x(v_x);
		ice_person->set_speed_y(v_y);
	}
	else if (person == 1)
	{
		fire_person->set_speed_x(v_x);
		fire_person->set_speed_y(v_y);
	}
}

void Model::set_speed_x(double v_x, int person) throw()//person: 0-ice; 1-fire
{
	if (person == 0)
	{
		ice_person->set_speed_x(v_x);
	}
	else if (person == 1)
	{
		fire_person->set_speed_x(v_x);
	}
}

void Model::set_speed_y(double v_y, int person) throw()//person: 0-ice; 1-fire
{
	if (person == 0)
	{
		ice_person->set_speed_y(v_y);
	}
	else if (person == 1)
	{
		fire_person->set_speed_y(v_y);
	}
}

const Pos& Model::get_ice_pos() throw()
{
	return ice_person->get_pos();
}

const Pos& Model::get_fire_pos() throw()
{
	return fire_person->get_pos();
}

void Model::Move() throw()
{
	ice_person->move();
	fire_person->move();
}