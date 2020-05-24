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
    QBrush brush = QBrush(Qt::SolidPattern);

    painter->setFont(H1);
    painter->drawText(QRect(20, 20 , 450, 50), "Count: ", QTextOption());
    painter->drawText(QRect(20, 70 , 450, 50), "Decks:", QTextOption());
    painter->drawText(QRect(20, 120, 450, 50), "Bet:", QTextOption());
    painter->drawLine(20, 205, 430, 205);
    painter->drawText(QRect(0 , 240, 450, 50), "Recommended move:", QTextOption(Qt::AlignCenter));
    painter->drawLine(20, 420, 430, 420);

    painter->setFont(H3);
    painter->drawLine(20, 700, 190, 700);
    painter->drawText(QRect(190 , 684, 70, 30), "Controls", QTextOption(Qt::AlignCenter));
    painter->drawLine(260, 700, 430, 700);
    painter->drawText(QRect(0, 698 , 450, 50), "    [0]         [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]   [9]", QTextOption(Qt::AlignCenter));


    brush.setColor(Qt::white);
    painter->setBrush(brush);

    for(int i = 0; i < 13; i++) {
        int tmp = 63;
        if( i < 4 ) tmp = i*21;
        painter->setFont(H5);
        painter->drawRect( 8+i*39-tmp, 740, 24, 40 );
        painter->drawText( QRect( 8+i*39-tmp, 742, 16, 10 ), "A", QTextOption(Qt::AlignCenter) );
        painter->rotate(180);
        painter->drawText(QRect( -(8+i*39-tmp)-26, -740-38, 16, 10 ), "A", QTextOption(Qt::AlignCenter) );
        painter->rotate(-180);
        painter->drawText( QRect( 8+i*39-tmp, 738, 26, 40 ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
    }

}

Widget *Widget::get()
{
    if( !widget )
        widget = new Widget();
    return widget;
}
