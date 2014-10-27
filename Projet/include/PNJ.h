#ifndef PNJ_H
#define PNJ_H

#include "Monstre.h"
#include "Area.h"
#include "Cell.h"

class PNJScenario : public Monstre
{
    public:
        PNJScenario();
        PNJScenario(Area* newArea, int idCell);
        virtual ~PNJScenario();
        void setId(int newId);
        int getId();
        void setCell(Cell* cell);
        Cell* getCell();
        void setArea(Area* area);
        Area* getArea();
        void setName(char* newName);
        char* getName();
        int placeOnCell(Area* area, int idCell);
        int placeByCoordonate(Area* area, int x, int y);
        int moveOnCell(Area* area, int idCell);
        int moveByCoordonate(Area* area, int x, int y);

        static int nbNPC;
    protected:
    private:
        int id;
        Cell* cell;
        Area* area;

};

#endif // PNJ_H
