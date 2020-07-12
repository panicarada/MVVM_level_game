#pragma once
//person.h


#ifndef _PERSON_H
#define _PERSON_H

#include<memory>
#include<string>
#include"Geometry.h"
#include "./common/Common.h"

class Map;

class Person
{
public:
    Person() noexcept :m_pos(0, 0), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(V_MOTIONLESS, V_MOTIONLESS), aerial(false) {}
    Person(std::string name) noexcept :m_pos(0, 0), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(V_MOTIONLESS, V_MOTIONLESS), aerial(false)

    {
        m_name = std::make_shared<std::string>(name);
    }

    Person(const Person& p) noexcept :
        m_name(p.m_name), m_map(p.m_map), m_pos(p.m_pos), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(p.m_speed), aerial(p.aerial) {}
    Person(Person&& p) noexcept:
        m_name(p.m_name), m_map(p.m_map), m_pos(p.m_pos), m_sizeX(PERSONSIZE_X), m_sizeY(PERSONSIZE_Y), m_speed(p.m_speed), aerial(p.aerial) {}


    void set_map(const std::shared_ptr<Map>& m);

    void set_pos_x(double x)noexcept;
    double get_pos_x() noexcept;
    void set_pos_y(double y) noexcept;
    double get_pos_y() noexcept;
    void set_pos(double x, double y) noexcept;
    const Pos& get_pos() noexcept;
    void get_pos(double& x, double& y) noexcept;
    const Pos get_pos_right() noexcept;

    const std::string& get_name() const noexcept;

    void set_speed_x(double x) noexcept;
    double get_speed_x() noexcept;
    void set_speed_y(double y) noexcept;
    double get_speed_y() noexcept;
    Velocity& get_speed() noexcept;

    void set_aerial(bool isAerial) noexcept;
    bool isAerial() noexcept { return aerial; }

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
