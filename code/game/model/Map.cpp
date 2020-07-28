//Map.cpp


#include"Map.h"
#include <QRect>
#include <QDebug>

Map::Map()
    : walls_set(QSet<QSharedPointer<Wall>>())
{
    // 墙体数据的写入
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,800),  QPoint(24,714)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(365,712), QPoint(365,688)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,685), QPoint(24,599)), LEFT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,573), QPoint(24,341)), LEFT_BLOCK));


    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,800), QPoint(508,800)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,685), QPoint(365,685)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(648,800), QPoint(733,800)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(876,800), QPoint(991,799)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(1018,715), QPoint(1075,714)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(817,630), QPoint(933,632)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(538,632), QPoint(680,630)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(538,817), QPoint(619,817)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(763,817), QPoint(846,817)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,573), QPoint(481,574)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(707,646), QPoint(791,646)), FLOOR));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(142,432), QPoint(565,432    )), FLOOR));






    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,714), QPoint(365,712)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,599), QPoint(422,599)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(422,598), QPoint(478,654)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(478,654), QPoint(957,656)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(1017,569), QPoint(1075,569)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(963,513), QPoint(1017,569)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(932,514), QPoint(963,513)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(904,484), QPoint(932,514)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(535,484), QPoint(904,484)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(142,455), QPoint(507,456)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(507,456), QPoint(535,484)), CEIL));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(24,341), QPoint(790,343)), CEIL));



    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(991, 801), QPoint(991, 743)), RIGHT_BLOCK));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(1075, 714), QPoint(1075, 569)), RIGHT_BLOCK));

    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(991, 743), QPoint(1018, 715)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(933, 632), QPoint(957, 656)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(481, 574), QPoint(538, 632)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(508, 800), QPoint(537, 817)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(620, 817), QPoint(648, 800)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(733, 800), QPoint(763, 817)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(846, 817), QPoint(876, 800)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(680, 630), QPoint(707, 646)), SLOPE));
    walls_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(791, 646), QPoint(817, 630)), SLOPE));



    // 池水
    fire_pools_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(512,802), QPoint(643,802)), FIRE_POOL));
    ice_pools_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(738,802), QPoint(871,802)), ICE_POOL));
    poison_pools_set.insert(QSharedPointer<Wall>::create(QLineF(QPoint(685, 632), QPoint(812, 632)), POISON_POOL));



    // 钻石数据的写入
    diamonds_set.insert(QSharedPointer<Diamond>::create(FIRE, 0, QPointF(558, 740)));
    diamonds_set.insert(QSharedPointer<Diamond>::create(ICE, 1, QPointF(785, 740)));


    // 升降台数据和对应机关的写入
    auto platform_0 = QSharedPointer<lifting_platform>::create(0, QPointF(24, 546), 546, 432);
    platforms_set.insert(platform_0);
    levers_set.insert(QSharedPointer<trigger_lever>::create(0, platform_0, true, QPoint(264, 570)));


    // 连接机关发出的信号
    for (auto platform : platforms_set)
    {
        QObject::connect(platform.data(), &lifting_platform::lifting_platform_notification, this, [&](const int& id, const QPointF& pos, const movable_item_status& status){
//            qDebug() << "platform signal sented, id = " << id;
            emit this->lifting_platform_notification(id, pos, status);
        });
    }
    for (auto lever : levers_set)
    {
        QObject::connect(lever.data(), &trigger_lever::trigger_lever_notification, this, [&](const int& id, const double& angle, const movable_item_status& status){
//            qDebug() << "lever signal sented, id = " << id;
            emit this->trigger_lever_notification(id, angle, status);
        });
    }

}

QSharedPointer<Wall_crashed_union> Map::intersect_wall(const QRectF &rect)
{
    QSharedPointer<Wall_crashed_union> crashed_walls = nullptr;
    for (auto wall : walls_set)
    { // 遍历每个墙体
        if (wall->intersect(rect))
        {
            if (crashed_walls == nullptr)
            {
                crashed_walls = QSharedPointer<Wall_crashed_union>::create();
            }
            if (wall->wall_type == FLOOR)
            {
                crashed_walls->floor = wall;
            }
            else if (wall->wall_type == CEIL)
            {
                crashed_walls->ceil = wall;
            }
            else if (wall->wall_type == LEFT_BLOCK)
            {
                crashed_walls->left_block = wall;
            }
            else if (wall->wall_type == RIGHT_BLOCK)
            {
                crashed_walls->right_block = wall;
            }
            else if (wall->wall_type == SLOPE)
            {
                crashed_walls->slope = wall;
            }
        }
    }
    return crashed_walls;
}

bool Map::intersect_wrong_pool(const QRectF &rect, const PersonType &type)
{
    if (type == ICE)
    { // 冰人不能碰火池
        for (auto fire_pool : fire_pools_set)
        {
            if (fire_pool->intersect(rect))
            {
                return true;
            }
        }
    }
    else if (type == FIRE)
    { // 火人不能碰冰池
        for (auto ice_pool : ice_pools_set)
        {
            if (ice_pool->intersect(rect))
            {
                return true;
            }
        }
    }
    for (auto poison_pool : poison_pools_set)
    { // 都不能碰毒池
        if (poison_pool->intersect(rect))
        {
            return true;
        }
    }

    return false;
}

QSharedPointer<Diamond> Map::intersect_diamond(const QRectF &rect, const PersonType &type)
{
    for (auto diamond : diamonds_set)
    {
        if (diamond->intersect(rect, type))
        { // 一次只可能碰到一个钻石
            return diamond;
        }
    }
    return nullptr;
}

QSharedPointer<trigger_lever> Map::intersect_lever(const QRectF &rect)
{
    for (auto lever : levers_set)
    {
        if (lever->intersect(rect))
        {
            return lever;
        }
    }
    return nullptr;
}


QSharedPointer<lifting_platform> Map::intersect_platform(const QRectF &rect, QSharedPointer<Wall> &wall_ptr)
{
    for (auto platform : platforms_set)
    {
        auto crashed_wall = platform->intersect(rect);
        if (crashed_wall)
        {
            wall_ptr = crashed_wall;
            return platform;
        }
    }
    wall_ptr = nullptr;
    return nullptr;
}

void Map::update()
{
    for (auto lever : levers_set)
    {
        lever->move();
    }
    for (auto platform : platforms_set)
    {
        platform->move();
    }
}


