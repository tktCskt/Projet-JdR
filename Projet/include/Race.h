#ifndef RACE_H
#define RACE_H

#include "Talent.h"

class Race
{
     public:
        Race();
        virtual ~Race();
        int addFeat(Talent* newFeat);
        Talent** table_talent;
        int nbFeats;
        static int nbRaces;
        static Race** listRaces;
        char* name;
        char* description;
    protected:
    private:
    int iD_race;
};

#endif // RACE_H
