#include "controller.h"

Controller *Controller::controller = nullptr;

Controller::Controller(QObject *parent)
{
    widget = Widget::get();
    widget->setGeometry((1920-450)*widget->getSSM(), (1080-850)*widget->getSSM(), 450*widget->getSSM(), 800*widget->getSSM());
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
