#include "controller.h"

Controller *Controller::controller = nullptr;

Controller::Controller(QObject *parent)
{

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
