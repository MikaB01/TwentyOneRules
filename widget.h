#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
private:
    Widget(QWidget *parent = 0);
    ~Widget();
    static Widget *widget;
public:
    static Widget *get();
};

#endif // WIDGET_H
