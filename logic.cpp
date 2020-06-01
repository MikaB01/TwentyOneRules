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

int Logic::getCardCountSum()
{
    int cardCountSum = 0;
    for(int i = 0; i < deckCardCounts.length(); i++)
        cardCountSum += deckCardCounts[i];
    return cardCountSum;
}

void Logic::removeCardFromDeckCountAt(int index)
{
    deckCardCounts[index]--;
}
