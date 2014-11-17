#include "Area.h"

Area::Area()
{
    //ctor
}

Area::~Area()
{
    //dtor
}

// ********** Getters **********

int Area::getId()
{
    return this->id;
}

int Area::getXMax()
{
    return this->xMax;
}

int Area::getYMax()
{
    return this->yMax;
}

char* Area::getName()
{
    return this->name;
}

char* Area::getDescription()
{
    return this->description;
}

Cell* Area::getCells()
{
    return this->listCells;
}

Cell Area::getCell(int x, int y)
{
    return this->getCells()[y*xMax+x];
}

void Area::getCoordonate(int idCell, int* x, int* y)
{
    *x = idCell%this->getXMax();
    *y = idCell/this->getXMax();
}

// ********** Setters **********

void Area::setId(int id)
{
    this->id = id;
}

void Area::setXMax(int xMax)
{
    this->xMax = xMax;
}

void Area::setYMax(int yMax)
{
    this->yMax = yMax;
}

void Area::setName(char* name)
{
    this->name = name;
}

void Area::setDescription(char* description)
{
    this->description = description;
}

void Area::setCells(Cell* Cells)
{
    this->listCells = Cells;
}
