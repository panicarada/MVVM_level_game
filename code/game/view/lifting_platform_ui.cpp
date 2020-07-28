#include "lifting_platform_ui.h"

lifting_platform_ui::lifting_platform_ui(const int &&id, const QPoint &&pos, QWidget *parent)
    : QWidget(parent), id(id), pos(pos), status(MOTIONLESS)
{

}

void lifting_platform_ui::set_pos(const QPoint &pos)
{
    this->pos = pos;
}

void lifting_platform_ui::set_status(const movable_item_status &status)
{
    this->status = status;
}

int &lifting_platform_ui::get_id()
{
    return id;
}

void lifting_platform_ui::paint(QPainter &painter)
{
    if (status == MOTIONLESS)
    {
        painter.drawPixmap(pos, img_motionless);
    }
    else
    {
        painter.drawPixmap(pos, img_moving);
    }
}
