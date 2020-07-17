#include "app.h"
#include <QDebug>


App::App()
{
    model = QSharedPointer<Model>::create();
    view_model = QSharedPointer<ViewModel>::create();
    view_model->setup_command(view_model);
    view = QSharedPointer<View>::create();

    view->resize(1200, 900); //分辨率


    /* 将command绑定到view层 */
    view->set_fire_jump_command(view_model->get_fire_jump_move_command());
    view->set_fire_left_command(view_model->get_fire_left_move_command());
    view->set_fire_right_command(view_model->get_fire_right_move_command());
    view->set_ice_jump_command(view_model->get_ice_jump_move_command());
    view->set_ice_left_command(view_model->get_ice_left_move_command());
    view->set_ice_right_command(view_model->get_ice_right_move_command());
    view->set_move_command(view_model->get_move_command());
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
