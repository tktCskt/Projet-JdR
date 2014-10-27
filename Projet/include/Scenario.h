#include "Area.h"
#include <list>
#ifndef SCENARIO_H
#define SCENARIO_H


class Scenario
{
    public:
        Scenario();
        virtual ~Scenario();
        int addArea(Area area);
        int deleteAreaById(int id);
        Area* getAreas();


    protected:
    private:
        int id;
        int level;
        int alignement;
        char* name;
        char* description;
        Area *listAreas;
};

#endif // SCENARIO_H
