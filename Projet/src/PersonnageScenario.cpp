#include "PersonnageScenario.h"
#include <stdio.h>

PersonnageScenario::PersonnageScenario()
{
    //ctor
}

PersonnageScenario::~PersonnageScenario()
{
    //dtor
}

void PersonnageScenario::setId(int newId)
{
    this->id = newId;
}

int PersonnageScenario::getId()
{
    return this->id;
}

void PersonnageScenario::setCell(Cell* newCell)
{
    this->cell = newCell;
}

Cell* PersonnageScenario::getCell()
{\
    return this->cell;
}

void PersonnageScenario::setArea(Area* newArea)
{
    this->area = newArea;
}

Area* PersonnageScenario::getArea()
{
    return this->area;
}

int PersonnageScenario::placeOnCell(Area* area, int idCell)
{
    /*TODO verification sur idCell qui appartient à Area*/
    Cell* areaCells = area->getCells();
    Cell* cell = &areaCells[idCell];
    if(cell->getB())
    {
        return -1;
    }
    if(cell->getType() == BLOQUE)
    {
        return -2;
    }
    cell->setB(true);
    this->area = area;
    this->cell = cell;
    return 0;
}

int PersonnageScenario::placeByCoordonate(Area* area, int x, int y)
{
    return placeOnCell(area,y*area->getXMax()+x);
}

int PersonnageScenario::moveOnCell(Area* area, int idCell)
{
    /*TODO chemin + vitesse + attaques opportunité*/
    this->cell->setB(false);
    int r = this->placeOnCell(area,idCell);
    if(r != 0)
    {
        this->cell->setB(true);
    }
    return r;

}

int PersonnageScenario::moveByCoordonate(Area* area, int x, int y)
{
    return moveOnCell(area,y*area->getXMax()+x);
}

