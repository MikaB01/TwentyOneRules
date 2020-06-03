#include "logic.h"

Logic *Logic::logic = nullptr;

Logic::Logic(QObject *parent)
{
}

Logic::~Logic()
{

}

Logic *Logic::get()
{
    if( !logic )
        logic = new Logic();
    return logic;
}

int Logic::getCardCountAt(int index)
{
    return deckCardCounts[index];
}

int Logic::getCardCountMaxAt(int index)
{
    return deckCardCountsMax[index];
}

int Logic::getCardCountSum()
{
    int cardCountSum = 0;
    for(int i = 0; i < deckCardCounts.length(); i++)
        cardCountSum += deckCardCounts[i];
    return cardCountSum;
}

int Logic::calcCount()
{
    int count = 0;
    for(int i = 0; i < 5; i++)
        count -= deckCardCounts[i];
    for(int i = 8; i < 10; i++)
        count += deckCardCounts[i];
    return count;
}

int Logic::getBetMultiplierAt(int index)
{
    return betMultiplier[index];
}

void Logic::removeCardFromDeckCountAt(int index)
{
    deckCardCounts[index]--;
}

void Logic::addCardFromDeckCountAt(int index)
{
    deckCardCounts[index]++;
}
