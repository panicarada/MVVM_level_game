#include "app.h"
#include <QDebug>


App::App()
{
    model = QSharedPointer<Model>::create();
    view_model = QSharedPointer<ViewModel>::create(model);
    view_model->setup_command(view_model);
    view = QSharedPointer<View>::create();

    /* 将command绑定到view层 */
    view->set_fire_jump_command(view_model->get_fire_jump_move_command());
    view->set_fire_left_command(view_model->get_fire_left_move_command());
    view->set_fire_right_command(view_model->get_fire_right_move_command());
    view->set_ice_jump_command(view_model->get_ice_jump_move_command());
    view->set_ice_left_command(view_model->get_ice_left_move_command());
    view->set_ice_right_command(view_model->get_ice_right_move_command());
    view->set_move_command(view_model->get_move_command());
    // 利用lambda表达式对仿函数进行绑定
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


    // 绑定信号与槽
    QObject::connect(model.data(), &Model::diamond_notification_model, view.data(), &View::react_diamond_notification);
}


void App::run()
{


    view->show();
}
