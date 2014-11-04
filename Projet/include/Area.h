#include "Cell.h"
#ifndef AREA_H
#define AREA_H


/**
  * An Area is composed of xMax*yMax Cells
  */
class Area
{
    public:
        Area();
        virtual ~Area();

        int getId();
        int getXMax();
        int getYmax();
        char* getName();
        char* getDescription();
        void getCoordonate(int idCell, int* x, int* y);

        void setId(int id);
        void setXMax(int xMax);
        void setYMax(int yMax);
        void setName(char* name);
        void setDescription(char* description);
        void setCells(Cell* Cells);
        Cell* getCells();

        /*TODO generer cellules+Id cellules avec xMax/yMax*/

    private:
        int id;
        int xMax;
        int yMax;
        char* name;
        char* description;
        Cell* listCells;
};

#endif // AREA_H
