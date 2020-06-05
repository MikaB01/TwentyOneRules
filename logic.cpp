#include "logic.h"

Logic *Logic::logic = nullptr;

Logic::Logic(QObject *parent)
{
}

Logic::~Logic()
{

}

int Logic::getPlayerHandSum()
{
    int sum = 0;
    int assCount = 0;
    isPlayerHandSoft = false;

    for(int i = 0; i < playerHand.length(); i++)
        if( heads.indexOf(playerHand[i]) == 9 ) assCount++;

    for(int i = 0; i < playerHand.length(); i++)
        if( heads.indexOf(playerHand[i]) != 9 )
            sum += heads.indexOf(playerHand[i])+2;

    for(int i = 0; i < playerHand.length(); i++)
        if( heads.indexOf(playerHand[i]) == 9 )
            if( sum < 11 && sum+11+assCount*1 <= 22) {
                sum += 11;
                isPlayerHandSoft = true;
            } else sum += 1;

    return sum;
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

Logic::action Logic::calcRecommendedMove()
{
    if( dealerHand.isEmpty() || playerHand.isEmpty() ) return Hit;
    int column = heads.indexOf(dealerHand.first());
    int row = 0;

    for(int i = 0; i <= 13; i++)
        if( getPlayerHandSum() == i+8 ) {
            row = i;
            if( row > 9 ) row = 9;
        }

    for(int i = 0; i < 8; i++)
        if( getPlayerHandSum() == 13+i && isPlayerHandSoft )
            row = i+10;

    for(int i = 0; i < 10; i++)
        if(playerHand.length() == 2 && playerHand.at(0) == playerHand.at(1) && heads.indexOf(playerHand.first()) == i )
            row = i+18;

    qDebug() << "Row: " << row << " Column: " << column << " Index: " << row*10+column;
    return twentyOneRules[row*10+column];
}

int Logic::getBetMultiplierAt(int index)
{
    return betMultiplier[index];
}

void Logic::removeCardFromDeckCountAt(int index)
{
    if(deckCardCounts[index])
        deckCardCounts[index]--;
}

void Logic::addCardFromDeckCountAt(int index)
{
    if(deckCardCounts[index] < deckCardCountsMax[index])
        deckCardCounts[index]++;
}

void Logic::addCardToPlayerHand(QString cardHead)
{
    playerHand << cardHead;
}

void Logic::removeLastCardFromPlayerHand()
{
    if( !playerHand.isEmpty() )
        playerHand.pop_back();
}

void Logic::addCardToDealerHand(QString cardHead)
{
    dealerHand << cardHead;
}

void Logic::removeLastCardFromDealerHand()
{
    if( !dealerHand.isEmpty() )
        dealerHand.pop_back();
}
