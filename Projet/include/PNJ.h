#ifndef PNJ_H
#define PNJ_H

#include "Monstre.h"
#include "Area.h"
#include "Cell.h"
#include <stdio.h>

/**
  * This is Monstre with coordinates, which allows it to move and interact within the scenario
  */
class PNJScenario : public Monstre
{
    // TODO Add dialogs
    public:
        PNJScenario();
        PNJScenario(Area* newArea, int idCell);
        virtual ~PNJScenario();

        int getId();
        Cell* getCell();
        Area* getArea();
        char* getName();

        void setId(int newId);
        void setCell(Cell* cell);
        void setArea(Area* area);
        void setName(char* newName);

        int placeOnCell(Area* area, int idCell);
        int placeByCoordonate(Area* area, int x, int y);
        int moveOnCell(Area* area, int idCell);
        int moveByCoordonate(Area* area, int x, int y);

        void (*discuss)();
        static int nbNPC;

    private:
        int id;
        Cell* cell;
        Area* area;

};

inline void npcDiscussion()
{
    printf("Bonjour je suis un PNJ\n\n");
}
#endif // PNJ_H
