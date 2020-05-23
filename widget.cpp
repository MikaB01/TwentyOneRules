#include "widget.h"

Widget *Widget::widget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

Widget *Widget::get()
{
    if( !widget )
        widget = new Widget();
    return widget;
}
