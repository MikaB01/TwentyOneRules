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
    QList<int> deckCardCountsMax = deckCardCounts;
    QList<int> betMultiplier = QList<int>() << 1 << 2 << 4 << 8 << 10 << 12;

public:
    static Logic *get();

    int getCardCountAt( int index );
    int getCardCountMaxAt( int index );
    int getCardCountSum();
    int calcCount();
    int getBetMultiplierAt( int index );

    void removeCardFromDeckCountAt( int index );
};

#endif // LOGIC_H
