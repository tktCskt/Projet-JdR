#include "Cell.h"
#ifndef AREA_H
#define AREA_H


class Area
{
    public:
        Area();
        virtual ~Area();
        void setId(int id);
        int getId();
        void setXMax(int xMax);
        int getXMax();
        void setYMax(int yMax);
        int getYmax();
        void setName(char* name);
        char* getName();
        void setDescription(char* description);
        char* getDescription();
        void setCells(Cell* Cells);
        void getCoordonate(int idCell, int* x, int* y);
        Cell* getCells();
        /*TODO generer cellules+Id cellules avec xMax/yMax*/
    protected:
    private:
        int id;
        int xMax;
        int yMax;
        char* name;
        char* description;
        Cell* listCells;
};

#endif // AREA_H
