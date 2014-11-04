#include "Cell.h"

Cell::Cell()
{
    //ctor
}

Cell::~Cell()
{
    //dtor
}

// ********** Getters **********

int Cell::getX()
{
    return this->x;
}

int Cell::getY()
{
    return this->y;
}

int Cell::getId()
{
    return this->id;
}

int Cell::getType()
{
    return this->type;
}

bool Cell::getB()
{
    return this->b;
}

// ********** Setters **********

void Cell::setX(int x)
{
    this->x = x;
}

void Cell::setY(int y)
{
    this->y = y;
}

void Cell::setId(int id)
{
    this->id = id;
}

void Cell::setType(int type)
{
    this->type = type;
}

void Cell::setB(bool b)
{
    this->b = b;
}
