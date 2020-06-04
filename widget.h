#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

#include "config.h"
#include "logic.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    Widget(QWidget *parent = 0);
    ~Widget();
    static Widget *widget;
    Logic *logic;
    double SSM = QApplication::desktop()->screen()->width()/1920;

    QFont H1 = QFont("Times", 13+4*SSM);
    QFont H3 = QFont("Times", 10+3*SSM);
    QFont H4 = QFont("Times", 9+3.7*SSM);
    QFont H5 = QFont("Times", 8+2*SSM);
    QFont H6 = QFont("Times", 6+2*SSM);

    QList<QString> cardhead = QList<QString>() << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "B" << "Q" << "K" << "A";
    QList<QString> cardHistory = QList<QString>();

    void drawHistory(QPainter *painter, QBrush brush, QFont font);
    void drawControls(QPainter *painter, QBrush brush);
    void drawCard(QPainter *painter, int i, QFont font, QPoint pos, QSize size, int space, int cardBeginning);
    void drawSingleCard(QPainter *painter, QPoint pos, QSize size, QFont font, QString cardhead);
    void drawCardsWithValueTen(QPainter *painter, QBrush brush);
    void drawAss(QPainter *painter, QBrush brush);
    void addCardToHistory(int cardValue);
    void drawBackground(QPainter *painter);
    void drawCardBar(QPainter *painter, QPoint pos, int cardCount);

    void drawHead(QPainter *painter);
    
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public:
    static Widget *get();
    double getSSM();
};

#endif // WIDGET_H
