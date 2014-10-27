#include "Area.h"

Area::Area()
{
    //ctor
}

Area::~Area()
{
    //dtor
}

void Area::setId(int id)
{
    this->id = id;
}

int Area::getId()
{
    return this->id;
}

void Area::setXMax(int xMax)
{
    this->xMax = xMax;
}

int Area::getXMax()
{
    return this->xMax;
}

void Area::setYMax(int yMax)
{
    this->yMax = yMax;
}

int Area::getYmax()
{
    return this->yMax;
}

void Area::setName(char* name)
{
    this->name = name;
}

char* Area::getName()
{
    return this->name;
}

void Area::setDescription(char* description)
{
    this->description = description;
}

char* Area::getDescription()
{
    return this->description;
}

void Area::setCells(Cell* Cells)
{
    this->listCells = Cells;
}

Cell* Area::getCells()
{
    return this->listCells;
}

void Area::getCoordonate(int idCell, int* x, int* y)
{
    *x = idCell%this->getXMax();
    *y = idCell/this->getXMax();
}
