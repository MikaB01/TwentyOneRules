#include "widget.h"

Widget *Widget::widget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::drawHistory(QPainter *painter, QBrush brush, QFont font)
{
    QPen pen = QPen(Qt::SolidLine);
    painter->setFont(H4);
    brush.setColor(Qt::white);
    painter->setBrush(brush);
    painter->drawLine(20*SSM, 300*SSM, 190*SSM, 300*SSM);
    painter->drawText(QRect(190*SSM, 284*SSM, 70*SSM, 30*SSM), "History", QTextOption(Qt::AlignCenter));
    painter->drawLine(260*SSM, 300*SSM, 430*SSM, 300*SSM);


    int historyCardStartPointIndex = cardHistory.length();
    if( historyCardStartPointIndex > 7 ) historyCardStartPointIndex = 7;
    for(int i = 0; i < historyCardStartPointIndex; i++)
        drawSingleCard(painter, QPoint((208+i*25)-(historyCardStartPointIndex-i-1)*25, 314), QSize(34, 57), H5, cardHistory[cardHistory.length()-historyCardStartPointIndex+i]);

    pen.setColor( Qt::white );
    painter->setPen( pen );
    painter->drawLine(20*SSM, 380*SSM, 430*SSM, 380*SSM);
}

double Widget::getSSM()
{
    return SSM;
}


void Widget::drawCardsWithValueTen(QPainter *painter, QBrush brush)
{
    for(int i = 0; i < 4; i++) {
        int tmp = 63;
        if( i < 4 ) tmp = i*21;
        painter->setFont(H6);
        painter->drawRect( (8+i*39-tmp)*SSM, 740*SSM, 24*SSM, 40*SSM );
        painter->drawText( QRect( (8+i*39-tmp)*SSM, 742*SSM, 16*SSM, 10*SSM ), cardhead[i+8], QTextOption(Qt::AlignCenter) );
        painter->rotate(180);
        painter->drawText(QRect( (-(8+i*39-tmp)-26)*SSM, (-740-38)*SSM, 16*SSM, 10*SSM ), cardhead[i+8], QTextOption(Qt::AlignCenter) );
        painter->rotate(-180);
        painter->drawText( QRect( (8+i*39-tmp)*SSM, 738*SSM, 26*SSM, 40*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
        painter->setFont(H3);
    }
}

void Widget::drawAss(QPainter *painter, QBrush brush)
{
    painter->setFont(H6);
    painter->drawRect( (100)*SSM, 740*SSM, 24*SSM, 40*SSM );
    painter->drawText( QRect( (100)*SSM, 742*SSM, 16*SSM, 10*SSM ), cardhead[12], QTextOption(Qt::AlignCenter) );
    painter->rotate(180);
    painter->drawText(QRect( (-(100)-26)*SSM, (-740-38)*SSM, 16*SSM, 10*SSM ), cardhead[12], QTextOption(Qt::AlignCenter) );
    painter->rotate(-180);
    painter->drawText( QRect( (100)*SSM, 738*SSM, 26*SSM, 40*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
}

void Widget::drawControls(QPainter *painter, QBrush brush)
{
    QPen pen = QPen(Qt::SolidLine);
    pen.setColor( Qt::white );
    brush.setColor(Qt::white);
    painter->setPen( pen );
    painter->setBrush(brush);
    painter->setFont(H4);

    painter->drawLine(20*SSM, 690*SSM, 190*SSM, 690*SSM);
    painter->drawText(QRect(190*SSM, 674*SSM, 70*SSM, 30*SSM), "Controls", QTextOption(Qt::AlignCenter));
    painter->drawLine(260*SSM, 690*SSM, 430*SSM, 690*SSM);

    // Die Tasten
    for(int i = 0; i < 10; i++)
            if( !i )
                painter->drawText(QRect(24*SSM, 698*SSM, 40*SSM, 40*SSM), "["+QString::number(i)+"]", QTextOption(Qt::AlignCenter));
            else
                painter->drawText(QRect((54+i*39)*SSM, 698*SSM, 40*SSM, 40*SSM), "["+QString::number(i)+"]", QTextOption(Qt::AlignCenter));


    pen.setColor( Qt::black );
    painter->setPen( pen );
    drawCardsWithValueTen(painter, brush);

    //Das Ass
    drawAss(painter, brush);
/*
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(5);
    effect->setXOffset(5);
    effect->setYOffset(5);
    effect->setColor(Qt::black);

    QLabel *label = new QLabel(this);
    label->setGeometry( 200, 100, 500, 500);
    label->setFont(H1);
    label->setText("Lul");
    label->setGraphicsEffect(effect);
*/

    //Die Zahlen-Karten
    for(int i = 0; i < 8; i++) {
        int tmp = 63;
        painter->setFont(H6);
        painter->drawRect( (203+i*39-tmp)*SSM, 740*SSM, 24*SSM, 40*SSM );
        painter->drawText( QRect( (203+i*39-tmp)*SSM, 742*SSM, 16*SSM, 10*SSM ), cardhead[i], QTextOption(Qt::AlignCenter) );
        painter->rotate(180);
        painter->drawText(QRect( (-(203+i*39-tmp)-26)*SSM, (-740-38)*SSM, 16*SSM, 10*SSM ), cardhead[i], QTextOption(Qt::AlignCenter) );
        painter->rotate(-180);
        painter->drawText( QRect( (203+i*39-tmp)*SSM, 738*SSM, 26*SSM, 40*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
    }



}


void Widget::drawCard(QPainter *painter, int i, QFont font, QPoint pos, QSize size, int space, int cardBeginning)
{
    QPen pen = QPen(Qt::SolidLine);
    pen.setColor( Qt::black );
    painter->setPen( pen );
    painter->setFont(font);
    painter->drawRect( (pos.x()+i*space)*SSM, pos.y()*SSM, size.width()*SSM, size.height()*SSM );
    if(i < 5)
        painter->drawText( QRect( ((pos.x()-4)+i*space)*SSM, (pos.y()-2)*SSM, (size.width()-size.width()/3)*SSM, (size.width()-size.width()/3)*SSM ), cardhead[i+cardBeginning] , QTextOption(Qt::AlignCenter) );
    painter->rotate(180);
    painter->drawText(QRect( (-(pos.x()+i*space)-size.width()+4)*SSM, (-(pos.y()+2)-size.height())*SSM, (size.width()-size.width()/1.5)*SSM, (size.width()-size.width()/3)*SSM ), cardhead[i+cardBeginning], QTextOption(Qt::AlignCenter) );
    painter->rotate(-180);
    painter->drawText( QRect( (pos.x()+i*space)*SSM, (pos.y()-2)*SSM, size.width()*SSM, size.height()*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
}

void Widget::drawSingleCard(QPainter *painter, QPoint pos, QSize size, QFont font, QString cardhead)
{
    QPen pen = QPen(Qt::SolidLine);
    pen.setColor( Qt::black );
    painter->setPen( pen );
    painter->setFont(font);
    painter->drawRect( pos.x()*SSM, pos.y()*SSM, size.width()*SSM, size.height()*SSM );
    painter->drawText( QRect( (pos.x()-4)*SSM, (pos.y()-2)*SSM, (size.width()-size.width()/3)*SSM, (size.width()-size.width()/3)*SSM ), cardhead , QTextOption(Qt::AlignCenter) );
    painter->rotate(180);
    painter->drawText(QRect( (-pos.x()-size.width()+4)*SSM, (-(pos.y()-1)-size.height())*SSM, (size.width()-size.width()/3)*SSM, (size.width()-size.width()/3)*SSM ), cardhead, QTextOption(Qt::AlignLeft) );
    painter->rotate(-180);
    painter->drawText( QRect( pos.x()*SSM, (pos.y()-2)*SSM, size.width()*SSM, size.height()*SSM ), UTF8SYMBOLES[1], QTextOption(Qt::AlignCenter) );
}


void Widget::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    QBrush brush = QBrush(Qt::SolidPattern);
    QPen pen = QPen(Qt::SolidLine);
    pen.setColor( Qt::white );
    painter->setPen( pen );

    QFile file( "images/backgroundv4-4k.png" );
    qDebug() << file.exists();
    brush.setColor(Qt::black);
    painter->setBrush(brush);
    painter->drawRect(0, 0, 450*SSM, 800*SSM);
    painter->drawImage( 0, 0, QImage("images/backgroundv4-true4k.png") );
    painter->setBrush(Qt::black);

    painter->setFont(H1);
    painter->drawText(QRect(20*SSM, 20*SSM, 450*SSM, 50*SSM), "Count: ", QTextOption());
    painter->drawText(QRect(20*SSM, 70*SSM, 450*SSM, 50*SSM), "Decks:", QTextOption());
    painter->drawText(QRect(20*SSM, 120*SSM, 450*SSM, 50*SSM), "Bet:", QTextOption());
    painter->drawLine(20*SSM, 165*SSM, 430*SSM, 165*SSM);
    painter->drawText(QRect(0, 170*SSM, 450*SSM, 50*SSM), "Recommended move:", QTextOption(Qt::AlignCenter));

    drawHistory(painter, brush, H4);

    brush.setColor(Qt::white);
    painter->setBrush(brush);

    int cardSkip = 0;
    for(int i = 0; i < 5; i++) {
        drawCard( painter, i, H4, QPoint(20, 427), QSize( 48, 80 ), 90, 0);
        if(i == 4) cardSkip += 3;

        drawCard( painter, i, H4, QPoint(20, 557), QSize( 48, 80 ), 90, 5+cardSkip);
    }

    drawControls(painter, brush);

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    for(int i = 0; i < 10; i++)
        if( event->key() == 48 + i )
        qDebug() << "Space hitted" << event->key();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{

}


Widget *Widget::get()
{
    if( !widget )
        widget = new Widget();
    return widget;
}
