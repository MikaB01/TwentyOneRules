#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>


#include "widget.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    Controller(QObject *parent = 0);
    ~Controller();
    static Controller *controller;
    Widget *widget;
public:
    static Controller *get();
};

#endif // CONTROLLER_H
