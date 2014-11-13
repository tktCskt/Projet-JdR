#ifndef RACE_H
#define RACE_H

#include "Talent.h"

class Race
{
     public:
        Race();
        virtual ~Race();
        char* getName();
        int setName(char* newName);
        char* getDescription();
        int setDescription(char* newDescription);
        int addFeat(Talent* newFeat);
        Talent** table_talent;
        int nbFeats;
        static int nbRaces;
        static Race** listRaces;
    protected:
        char* name;
        char* description;
    private:
    int iD_race;
};

#endif // RACE_H
