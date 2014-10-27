#ifndef PERSONNAGESCENARIO_H
#include "Personnage.h"
#include "Cell.h"
#include "Area.h"


class PersonnageScenario : public Personnage
{
    public:
        PersonnageScenario();
        virtual ~PersonnageScenario();
        void setId(int newId);
        int getId();
        void setCell(Cell* cell);
        Cell* getCell();
        void setArea(Area* area);
        Area* getArea();
        int placeOnCell(Area* area, int idCell);
        int placeByCoordonate(Area* area, int x, int y);
        int moveOnCell(Area* area, int idCell);
        int moveByCoordonate(Area* area, int x, int y);
    protected:
    private:
        int id;
        Cell* cell;
        Area* area;
};

#endif // PERSONNAGESCENARIO_H
#define PERSONNAGESCENARIO_H
