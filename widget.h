#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "config.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    Widget(QWidget *parent = 0);
    ~Widget();
    static Widget *widget;

protected:
    void paintEvent(QPaintEvent *event);

public:
    static Widget *get();
};

#endif // WIDGET_H
