#ifndef RACE_H
#define RACE_H

#include "Talent.h"

enum size_ {s_I,s_Min,s_TP,s_P,s_M,s_G,s_TG,s_Gig,s_C};
class Race
{
     public:
        Race();
        virtual ~Race();
        Talent** table_talent;
        int nbTalents;
        static int nbRaces;
        static Race** listRaces;
        char* name;
        char* description;

        int getId();
        int addTalent(Talent* newTalent);
        void setSize(enum size_ newSize);
        enum size_ getSize();

    protected:
        size_ raceSize;
        int id;
    private:
};

#endif // RACE_H
