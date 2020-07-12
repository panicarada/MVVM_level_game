//Map.cpp


#include"Map.h"

Map::Map()
{
        std::shared_ptr<Line> floor = std::static_pointer_cast<Line, Floor>(std::make_shared<Floor>(0, 10, 200, 10));
        std::shared_ptr<Line> lWall = std::static_pointer_cast<Line, Floor>(std::make_shared<Floor>(0, 10, 0, 110));
        std::shared_ptr<Line> rWall = std::static_pointer_cast<Line, Floor>(std::make_shared<Floor>(0, 10, 200, 110));
        Walls.push_back(floor);
        Walls.push_back(lWall);
        Walls.push_back(rWall);
}

void Map::set_ice_person(const std::shared_ptr<Person>& ice) noexcept
{
        ice_person = ice;
}

void Map::set_fire_person(const std::shared_ptr<Person>& fire) noexcept
{
        fire_person = fire;
}

void Map::splitVelocity(const std::shared_ptr<Person>& p)
{
        bool aerial = true;
        auto iter(Walls.begin());
        for (; iter != Walls.end(); ++iter)
        {
                if (((*iter)->location(p->get_pos()) == 0 && p->get_speed_x() <= 0) || ((*iter)->location(p->get_pos_right()) == 0 && p->get_speed_y() >= 0))
                {
                        aerial = false;
                        if ((!(*iter)->isRoof() && p->get_speed_y() > 0) || (*iter)->isRoof())//起跳或撞到天花板
                        {
                                p->set_aerial(true);
                        }
                        else p->set_aerial(false);//落地或沿地面移动
                        p->get_speed().split(*iter);
                }
        }
        if (aerial)
        {
                p->set_aerial(true);
        }
}
