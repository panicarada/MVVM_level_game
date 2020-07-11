//Map.h


#pragma once
#ifndef _MAP_H
#define _MAP_H

#include "Person.h"
#include "Geometry.h"
#include <vector>


class Map
{
public:
    Map();

    void set_ice_person(const std::shared_ptr<Person>& ice) throw();
    void set_fire_person(const std::shared_ptr<Person>& fire) throw();

    void splitVelocity(const std::shared_ptr<Person>& p);
private:
    std::vector<std::shared_ptr<Line>> Walls;
    std::shared_ptr<Person> ice_person;
    std::shared_ptr<Person> fire_person;
};





#endif // !_MAP_H
