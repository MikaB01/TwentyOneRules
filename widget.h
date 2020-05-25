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

    QFont H1 = QFont("Times", 12+4*SSM, QFont::Bold);
    QFont H3 = QFont("Times", 9+3*SSM, QFont::Bold);
    QFont H4 = QFont("Times", 9+3*SSM);
    QFont H5 = QFont("Times", 6+2*SSM);

    void drawControls(QPainter *painter, QBrush brush);

    void drawCard(QPainter *painter, int i, QFont font, QPoint pos, QSize size, int space);

protected:
    void paintEvent(QPaintEvent *event);

public:
    static Widget *get();
    double getSSM();
};

#endif // WIDGET_H
