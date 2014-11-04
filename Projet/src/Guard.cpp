#include "Guard.h"
#include <stdio.h>

Guard::Guard()
{
    //ctor
    this->discuss = guardDiscussion;
}

Guard::Guard(Area* newArea, int idCell)
{
    this->placeOnCell(newArea,idCell);
    this->discuss = guardDiscussion;
}

Guard::~Guard()
{
    //dtor
}

