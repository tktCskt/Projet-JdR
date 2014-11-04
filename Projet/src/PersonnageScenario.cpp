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

// ********** Getters **********

int PersonnageScenario::getId()
{
    return this->id;
}

Cell* PersonnageScenario::getCell()
{
    return this->cell;
}

Area* PersonnageScenario::getArea()
{
    return this->area;
}

// ********** Setters **********

void PersonnageScenario::setId(int newId)
{
    this->id = newId;
}

void PersonnageScenario::setCell(Cell* newCell)
{
    this->cell = newCell;
}

void PersonnageScenario::setArea(Area* newArea)
{
    this->area = newArea;
}

// ********** Functions **********

/**
  * Set the Personnage in the area on the idCell sent by PersonnageScenario::placeByCoordonate()
  * We check if the cell is valid
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PersonnageScenario::placeOnCell(Area* area, int idCell)
{
    // TODO verification sur idCell qui appartient à Area

    Cell* areaCells = area->getCells();
    Cell* cell = &areaCells[idCell];
    // Check if it's occupied
    if(cell->getB())
    {
        return -1;
    }
    // Check if it's a wall
    if(cell->getType() == BLOQUE)
    {
        return -2;
    }
    cell->setB(true);
    this->area = area;
    this->cell = cell;
    return 0;
}

/**
  * Set the Personnage in the area on (x,y) after an area travel or cutscene
  * or is sent by PersonnageScenario::moveOnCell() after consequences have been calculated
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PersonnageScenario::placeByCoordonate(Area* area, int x, int y)
{
    return placeOnCell(area,y*area->getXMax()+x);
}

/**
  * Move the Personnage in the area on the idCell sent by PersonnageScenario::moveByCoordonate()
  * We have to check if it's possible and if it triggers any event (eg attaque d'opportunité)
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PersonnageScenario::moveOnCell(Area* area, int idCell)
{
    // TODO chemin + vitesse + attaques opportunité

    Cell* oldCell = this->cell;

    int r = this->placeOnCell(area,idCell);

    // We check if the selected cell is valid
    if(r == 0) // We set the old cell busy
        oldCell->setB(false);

    return r;
}

/**
  * Move the Personnage in the area on (x,y)
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PersonnageScenario::moveByCoordonate(Area* area, int x, int y)
{
    return moveOnCell(area,y*area->getXMax()+x);
}

