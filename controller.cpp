#include "controller.h"

Controller *Controller::controller = nullptr;

Controller::Controller(QObject *parent)
{
    widget = Widget::get();
    widget->setGeometry(1920 - 450, 1080 - 800, 450, 800);
    widget->show();
}

Controller::~Controller()
{

}

Controller *Controller::get()
{
    if( !controller )
        controller = new Controller();
    return controller;
}
