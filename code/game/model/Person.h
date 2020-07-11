
//person.h


#ifndef _PERSON_H
#define _PERSON_H

#include<memory>
#include<string>
#include"Geometry.h"

#define PERSONSIZE_X 5
#define PERSONSIZE_Y 10

class Map;

class Person
{
public:
    Person() throw() :m_pos(0, 0), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(0, -10) {};
    Person(std::string) throw();
    Person(const Person& p) throw() :m_name(p.m_name), m_map(p.m_map), m_pos(p.m_pos), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(p.m_speed) {};
    Person(Person&& p) throw() :m_name(p.m_name), m_map(p.m_map), m_pos(p.m_pos), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(p.m_speed) {};

    void set_map(const std::shared_ptr<Map>& m);

    void set_pos_x(double x) throw();
    double get_pos_x() throw();
    void set_pos_y(double y) throw();
    double get_pos_y() throw();
    void set_pos(double x, double y) throw();
    const Pos& get_pos() throw();
    void get_pos(double& x, double& y) throw();
    const Pos get_pos_right() throw();

    const std::string& get_name() const throw();

    void set_speed_x(double x) throw();
    double get_speed_x() throw();
    void set_speed_y(double y) throw();
    double get_speed_y() throw();
    Velocity& get_speed() throw();

    void set_aerial(bool isAerial) throw();
    bool isAerial() throw() { return aerial; }

    void move();

private:
    std::shared_ptr<std::string> m_name;
    std::shared_ptr<Map> m_map;
    Velocity m_speed;
    Pos m_pos;
    double m_sizeX;
    double m_sizeY;
    bool aerial;
};


#endif // !_PERSON_H
