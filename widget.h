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
    double SSM = QApplication::desktop()->screen()->width()/1920;

    void drawControls(QPainter *painter, QBrush brush);

protected:
    void paintEvent(QPaintEvent *event);

public:
    static Widget *get();
    double getSSM();
};

#endif // WIDGET_H
