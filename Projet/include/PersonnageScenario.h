#ifndef PERSONNAGESCENARIO_H
#include "Personnage.h"
#include "Cell.h"
#include "Area.h"

/**
  * This is Personnage with coordinates, which allows it to move and interact within the scenario
  */
class PersonnageScenario : public Personnage
{
    public:
        PersonnageScenario();
        virtual ~PersonnageScenario();

        int getId();
        Cell* getCell();
        Area* getArea();

        void setId(int newId);
        void setCell(Cell* cell);
        void setArea(Area* area);

        int placeOnCell(Area* area, int idCell);
        int placeByCoordonate(Area* area, int x, int y);
        int moveOnCell(Area* area, int idCell);
        int moveByCoordonate(Area* area, int x, int y);

    private:
        int id;
        Cell* cell;
        Area* area;
};

#endif // PERSONNAGESCENARIO_H
#define PERSONNAGESCENARIO_H
