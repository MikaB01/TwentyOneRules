#include "widget.h"

Widget *Widget::widget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

double Widget::getSSM()
{
    return SSM;
}

void Widget::drawControls(QPainter *painter, QBrush brush)
{
    brush.setColor(Qt::white);
    painter->setBrush(brush);
    painter->setFont(H3);

    painter->drawLine(20*SSM, 700*SSM, 190*SSM, 700*SSM);
    painter->drawText(QRect(190*SSM, 684*SSM, 70*SSM, 30*SSM), "Controls", QTextOption(Qt::AlignCenter));
    painter->drawLine(260*SSM, 700*SSM, 430*SSM, 700*SSM);

    for(int i = 0; i < 13; i++) {
        int tmp = 63;
        if( i < 4 ) tmp = i*21;
        painter->setFont(H5);
        painter->drawRect( (8+i*39-tmp)*SSM, 740*SSM, 24*SSM, 40*SSM );
        painter->drawText( QRect( (8+i*39-tmp)*SSM, 742*SSM, 16*SSM, 10*SSM ), "A", QTextOption(Qt::AlignCenter) );
        painter->rotate(180);
        painter->drawText(QRect( (-(8+i*39-tmp)-26)*SSM, (-740-38)*SSM, 16*SSM, 10*SSM ), "A", QTextOption(Qt::AlignCenter) );
        painter->rotate(-180);
        painter->drawText( QRect( (8+i*39-tmp)*SSM, 738*SSM, 26*SSM, 40*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
        painter->setFont(H3);
        if(i < 10)
            if( !i )
                painter->drawText(QRect(24*SSM, 698*SSM, 40*SSM, 40*SSM), "["+QString::number(i)+"]", QTextOption(Qt::AlignCenter));
            else
                painter->drawText(QRect((54+i*39)*SSM, 698*SSM, 40*SSM, 40*SSM), "["+QString::number(i)+"]", QTextOption(Qt::AlignCenter));

    }
}

void Widget::drawCard(QPainter *painter, int i, QFont font, QPoint pos, QSize size, int space)
{
    painter->setFont(font);
    painter->drawRect( (pos.x()+i*space)*SSM, pos.y()*SSM, size.width()*SSM, size.height()*SSM );
    painter->drawText( QRect( ((pos.x()-4)+i*space)*SSM, (pos.y()-2)*SSM, (size.width()-size.width()/3)*SSM, (size.width()-size.width()/3)*SSM ), "A", QTextOption(Qt::AlignCenter) );
    painter->rotate(180);
    painter->drawText(QRect( (-(pos.x()+i*space)-size.width()+4)*SSM, (-(pos.y()+2)-size.height())*SSM, (size.width()-size.width()/1.5)*SSM, (size.width()-size.width()/3)*SSM ), "A", QTextOption(Qt::AlignCenter) );
    painter->rotate(-180);
    painter->drawText( QRect( (pos.x()+i*space)*SSM, (pos.y()-2)*SSM, size.width()*SSM, size.height()*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
}

void Widget::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    QBrush brush = QBrush(Qt::SolidPattern);

    painter->setFont(H1);
    painter->drawText(QRect(20*SSM, 20*SSM, 450*SSM, 50*SSM), "Count: ", QTextOption());
    painter->drawText(QRect(20*SSM, 70*SSM, 450*SSM, 50*SSM), "Decks:", QTextOption());
    painter->drawText(QRect(20*SSM, 120*SSM, 450*SSM, 50*SSM), "Bet:", QTextOption());
    painter->drawLine(20*SSM, 165*SSM, 430*SSM, 165*SSM);
    painter->drawText(QRect(0, 170*SSM, 450*SSM, 50*SSM), "Recommended move:", QTextOption(Qt::AlignCenter));
    painter->drawLine(20*SSM, 320*SSM, 430*SSM, 320*SSM);

    brush.setColor(Qt::white);
    painter->setBrush(brush);

    for(int i = 0; i < 5; i++) {
        //int tmp = 63;
        //if( i < 4 ) tmp = i*21;
        drawCard( painter, i, H4, QPoint(20, 350), QSize( 48, 80 ), 90 );
        if( i > 0 && i < 4 )
            drawCard( painter, i, H4, QPoint(20, 450), QSize( 48, 80 ), 90 );
        drawCard( painter, i, H4, QPoint(20, 550), QSize( 48, 80 ), 90 );
    }

    painter->drawLine(20*SSM, 635*SSM, 190*SSM, 635*SSM);
    painter->drawText(QRect(190*SSM, 619*SSM, 70*SSM, 30*SSM), "History", QTextOption(Qt::AlignCenter));
    painter->drawLine(260*SSM, 635*SSM, 430*SSM, 635*SSM);


    drawControls(painter, brush);

}

Widget *Widget::get()
{
    if( !widget )
        widget = new Widget();
    return widget;
}
