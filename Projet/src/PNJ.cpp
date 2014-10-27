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

void PNJScenario::setId(int newId)
{
    this->id = newId;
}

int PNJScenario::getId()
{
    return this->id;
}

void PNJScenario::setCell(Cell* newCell)
{
    this->cell = newCell;
}

Cell* PNJScenario::getCell()
{
    return this->cell;
}

void PNJScenario::setArea(Area* newArea)
{
    this->area = newArea;
}

Area* PNJScenario::getArea()
{
    return this->area;
}

void PNJScenario::setName(char* newName)
{
    this->name = newName;
}

char* PNJScenario::getName()
{
    return this->name;
}

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

int PNJScenario::placeByCoordonate(Area* area, int x, int y)
{
    return placeOnCell(area,y*area->getXMax()+x);
}

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

int PNJScenario::moveByCoordonate(Area* area, int x, int y)
{
    return moveOnCell(area,y*area->getXMax()+x);
}
