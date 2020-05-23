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
