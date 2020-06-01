#ifndef LOGIC_H
#define LOGIC_H

#include "config.h"

#include <QObject>

class Logic : public QObject
{
    Q_OBJECT
private:
    Logic(QObject *parent = 0);
    ~Logic();
    static Logic *logic;

    QList<int> deckCardCounts = QList<int>() << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS*4 << 4*CARD_DECKS;

public:
    static Logic *get();

    int getCardCountAt( int index );
    int getCardCountSum();

    void removeCardFromDeckCountAt( int index );
};

#endif // LOGIC_H
