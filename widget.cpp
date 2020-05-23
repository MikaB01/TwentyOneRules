#include "widget.h"

Widget *Widget::widget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->setFont(H1);
    painter->drawText(QRect(0, 20, 450, 30), "True-Count: ", QTextOption(Qt::AlignCenter));
}

Widget *Widget::get()
{
    if( !widget )
        widget = new Widget();
    return widget;
}
