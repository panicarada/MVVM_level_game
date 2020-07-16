#include "app.h"
#include "./command/FIRE_jump_move_command.h"
#include "./command/FIRE_left_move_command.h"
#include "./command/FIRE_right_move_command.h"
#include "./command/game_status_command.h"
#include "./command/ICE_jump_move_command.h"
#include "./command/ICE_left_move_command.h"
#include "./command/ICE_right_move_command.h"
#include "./command/move_command.h"
#include <QDebug>


App::App()
{
//    view = QSharedPointer<View>::create();
    model = QSharedPointer<Model>::create();
    view_model = QSharedPointer<ViewModel>::create();
    view = QSharedPointer<View>::create();
    view->resize(1200, 900); //分辨率

    /* 创建command */
    auto fire_jump_move_command = QSharedPointer<Fire_jump_move_command>::create(view_model);
    auto fire_left_move_command = QSharedPointer<Fire_left_move_command>::create(view_model);
    auto fire_right_move_command = QSharedPointer<Fire_right_move_command>::create(view_model);
    auto ice_jump_move_command = QSharedPointer<Ice_jump_move_command>::create(view_model);
    auto ice_left_move_command = QSharedPointer<Ice_left_move_command>::create(view_model);
    auto ice_right_move_command = QSharedPointer<Ice_right_move_command>::create(view_model);
    auto move_command = QSharedPointer<Move_command>::create(view_model);



    /* 将command绑定到view层 */
    view->set_fire_jump_command(fire_jump_move_command);
    view->set_fire_left_command(fire_left_move_command);
    view->set_fire_right_command(fire_right_move_command);
    view->set_ice_jump_command(ice_jump_move_command);
    view->set_ice_left_command(ice_left_move_command);
    view->set_ice_right_command(ice_right_move_command);
    view->set_move_command(move_command);
    view->set_get_ice_pos([&]()
    {
        return view_model->get_ice_pos();
    });
    view->set_get_fire_pos([&]()
    {
        return view_model->get_fire_pos();
    });
    view->set_get_ice_speed([&]()
    {
        return view_model->get_ice_speed();
    });
    view->set_get_fire_speed([&]()
    {
        return view_model->get_fire_speed();
    });
}


void App::run()
{
    view->resize(1200, 900); //分辨率
    view->show();
}
