#include "trigger_lever_ui.h"



trigger_lever_ui::trigger_lever_ui(const int &&id, const QPoint &&pos, QWidget *parent)
    :  QWidget(parent), id(id), angle(trigger_lever_angle_threshold_lower_bound), status(MOTIONLESS), hinge_pos(pos)
{
    img_motionless.load(":/source/image/lever_motionless.png");
    img_moving.load(":/source/image/lever_move.png");
}

void trigger_lever_ui::set_angle(const double &angle)
{
    this->angle = angle;
}

void trigger_lever_ui::set_status(const movable_item_status &status)
{
    this->status = status;
}

int &trigger_lever_ui::get_id()
{
    return id;
}

void trigger_lever_ui::paint(QPainter &painter)
{
    painter.save();
    painter.translate(hinge_pos);
    painter.rotate(-90-angle);
    if (status == MOTIONLESS)
    {
        painter.drawPixmap(QPoint(-4, 0), img_motionless);
    }
    else
    {
        painter.drawPixmap(QPoint(-4, 0), img_moving);
    }

    painter.restore();
}
