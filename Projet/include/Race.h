#ifndef RACE_H
#define RACE_H

#include "Talent.h"

class Race
{
     public:
        Race();
        virtual ~Race();
        char* getName();
        void setName(char* newName);
        char* getDescription();
        void setDescription(char* desc);
        int addFeat(Talent* newFeat);
        Talent** table_talent;
        static int nbRaces;
        int nbFeats;
        static Race** listRaces;
    protected:
    private:
    int iD_race;
    char* name;
    char* description;


};

#endif // RACE_H
