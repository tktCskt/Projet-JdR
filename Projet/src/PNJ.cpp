#include "PNJ.h"
#include "stdio.h"

int PNJScenario::nbNPC = 0;

PNJScenario::PNJScenario()
{
    this->cell = NULL;
    this->area = NULL;
    this->id = nbNPC;
    this->nbNPC++;
}

PNJScenario::PNJScenario(Area* newArea, int idCell)
{
    this->placeOnCell(newArea,idCell);
    this->id = nbNPC;
    this->nbNPC++;
}

PNJScenario::~PNJScenario()
{
    //dtor
}

// ********** Getters **********

int PNJScenario::getId()
{
    return this->id;
}

Cell* PNJScenario::getCell()
{
    return this->cell;
}

Area* PNJScenario::getArea()
{
    return this->area;
}

char* PNJScenario::getName()
{
    return this->name;
}

// ********** Setters **********

void PNJScenario::setId(int newId)
{
    this->id = newId;
}

void PNJScenario::setCell(Cell* newCell)
{
    this->cell = newCell;
}

void PNJScenario::setArea(Area* newArea)
{
    this->area = newArea;
}

void PNJScenario::setName(char* newName)
{
    this->name = newName;
}

// ********** Functions **********

/**
  * Set the Monstre in the area on the idCell sent by PNJScenario::placeByCoordonate()
  * We check if the cell is valid
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PNJScenario::placeOnCell(Area* area, int idCell)
{
    /*TODO verification sur idCell qui appartient à Area*/
    Cell* areaCells = area->getCells();
    Cell* cell = &areaCells[idCell];
    if(cell->getB())
    {
        printf("Impossible de placer le PNJ ici, case occupee\n");
        return -1;
    }
    if(cell->getType() == BLOQUE)
    {
        printf("Impossible de placer le PNJ ici, type = bloque\n");
        return -2;
    }
    cell->setB(true);
    this->area = area;
    this->cell = cell;
    return 0;
}

/**
  * Set the Monstre in the area on (x,y) after an area travel or cutscene
  * or is sent by PNJScenario::moveOnCell() after consequences have been calculated
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PNJScenario::placeByCoordonate(Area* area, int x, int y)
{
    return placeOnCell(area,y*area->getXMax()+x);
}

/**
  * Move the Monstre in the area on the idCell sent by PNJScenario::moveByCoordonate()
  * We have to check if it's possible and if it triggers any event (eg attaque d'opportunité)
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PNJScenario::moveOnCell(Area* area, int idCell)
{
    /*TODO if cell == null*/
    /*TODO chemin + vitesse + attaques opportunité*/
    this->cell->setB(false);
    int r = this->placeOnCell(area,idCell);
    if(r != 0)
    {
        this->cell->setB(true);
    }
    return r;

}

/**
  * Move the Monstre in the area on (x,y)
  * @return 0 if the cell is valid
            -1 if the cell is occupied
            -2 if the cell is invalid to be on (eg wall)
  */
int PNJScenario::moveByCoordonate(Area* area, int x, int y)
{
    return moveOnCell(area,y*area->getXMax()+x);
}
