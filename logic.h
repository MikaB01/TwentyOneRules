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

    bool isPlayerHandSoft = false;

    QList<int> deckCardCounts = QList<int>() << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS << 4*CARD_DECKS*4 << 4*CARD_DECKS;
    QList<int> deckCardCountsMax = deckCardCounts;
    QList<int> betMultiplier = QList<int>() << 1 << 2 << 4 << 8 << 10 << 12;

    QList<QString> heads = QList<QString>() << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "A";

    QList<QString> playerHand;
    QList<QString> dealerHand;

    int  getPlayerHandSum();

public:
    static Logic *get();

    enum action {
        Stand     = 0,
        Hit       = 1,
        Double    = 2,
        Split     = 3,
        Empty     = 4,
        Overbuyed = 5
    };

    QList<action> twentyOneRules = QList<action>() << Hit    << Hit    << Hit    << Hit    << Hit    << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Hit    << Double << Double << Double << Double << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Double << Double << Double << Double << Double << Double << Double << Double << Hit    << Hit    <<
                                                      Double << Double << Double << Double << Double << Double << Double << Double << Hit    << Hit    <<
                                                      Hit    << Hit    << Stand  << Stand  << Stand  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  <<
                                                      Hit    << Hit    << Hit    << Hit    << Double << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Hit    << Hit    << Hit    << Double << Double << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Hit    << Hit    << Hit    << Double << Double << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Hit    << Hit    << Double << Double << Double << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Hit    << Double << Double << Double << Double << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Stand  << Double << Double << Double << Double << Stand  << Stand  << Hit    << Hit    << Hit    <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  <<
                                                      Split  << Split  << Split  << Split  << Split  << Split  << Hit    << Hit    << Hit    << Hit    <<
                                                      Split  << Split  << Split  << Split  << Split  << Split  << Hit    << Hit    << Hit    << Hit    <<
                                                      Hit    << Hit    << Hit    << Split  << Split  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Double << Double << Double << Double << Double << Double << Double << Double << Hit    << Hit    <<
                                                      Split  << Split  << Split  << Split  << Split  << Hit    << Hit    << Hit    << Hit    << Hit    <<
                                                      Split  << Split  << Split  << Split  << Split  << Split  << Hit    << Hit    << Hit    << Hit    <<
                                                      Split  << Split  << Split  << Split  << Split  << Split  << Split  << Split  << Stand  << Stand  <<
                                                      Split  << Split  << Split  << Split  << Split  << Stand  << Split  << Split  << Stand  << Stand  <<
                                                      Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  << Stand  <<
                                                      Split  << Split  << Split  << Split  << Split  << Split  << Split  << Split  << Split  << Hit    ;
    int getCardCountAt( int index );
    int getCardCountMaxAt( int index );
    int getCardCountSum();
    int calcCount();
    action calcRecommendedMove();
    int getBetMultiplierAt( int index );

    void removeCardFromDeckCountAt( int index );
    void addCardFromDeckCountAt( int index );

    void addCardToPlayerHand( QString cardHead );
    void removeLastCardFromPlayerHand();
    void addCardToDealerHand( QString cardHead  );
    void removeLastCardFromDealerHand();

    void resetDeckCardCounts();
    void resetCurrentHands();
};

#endif // LOGIC_H
