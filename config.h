#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtWidgets>


const int CARD_DECKS = 8;

const double DECK_PENETRATION = 0.5;
const double WIDGET_SIZE_MULTIPLICATOR = 1.0;
const double BLACKJACK_PAYOUT = 1.5;

const bool HIT_SOFT_17 = true;
const bool DOUBLE_DOWN_AFTER_SPLIT = true;
const bool HIT_SPLIT_ACES = false;

const QList<QString> UTF8SYMBOLES = QList<QString>() << "\u2665" << "\u2660" << "\u2666" << "\u2663" ;

#endif // CONFIG_H
