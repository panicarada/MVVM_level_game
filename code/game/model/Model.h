#pragma once
//Model.h


#ifndef _MODEL_H
#define _MODEL_H

#include"Person.h"
#include"Map.h"
#include "./common/Common.h"

class Model
{
public:
    Model() noexcept;

    //person: 0-ice; 1-fire
    void set_speed(double v_x, double v_y, int person) noexcept;//person: 0-ice; 1-fire
    //person: 0-ice; 1-fire
    void set_speed_x(double v_x, int person) noexcept;//person: 0-ice; 1-fire
    //person: 0-ice; 1-fire
    void set_speed_y(double v_y, int person) noexcept;//person: 0-ice; 1-fire

    //person: 0-ice; 1-fire
    bool isAerial(int person) noexcept//person: 0-ice; 1-fire
    {
        if (person == 0) return ice_person->isAerial();
        if (person == 1) return fire_person->isAerial();
        return false;
    }

    const Pos& get_ice_pos() noexcept;
    const Pos& get_fire_pos() noexcept;

    void Move() noexcept;

private:
    std::shared_ptr<Map> m_map;
    std::shared_ptr<Person> ice_person;
    std::shared_ptr<Person> fire_person;
};

#endif // !_MODEL_H
