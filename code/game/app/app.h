#ifndef APP_H
#define APP_H

#include "./view_model/ViewModel.h"
#include "./view/view.h"
#include "model/Model.h"
#include <QSharedPointer>

class App
{
public:
    App();
    void run();
private:
    QSharedPointer<View> view;
    QSharedPointer<Model> model;
    QSharedPointer<ViewModel> view_model;
};

#endif // APP_H
