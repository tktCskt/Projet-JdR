#ifndef RACE_H
#define RACE_H

#include "Feat.h"

enum size_ {s_I,s_Min,s_TP,s_P,s_M,s_G,s_TG,s_Gig,s_C};
class Race
{
     public:
        Race();
        virtual ~Race();
        Feat** listFeats;
        int nbFeats;
        static int nbRaces;
        static Race** listRaces;
        char* name;
        char* description;

        int getId();
        int addFeat(Feat* newFeat);
        void setSize(enum size_ newSize);
        enum size_ getSize();

    protected:
        size_ raceSize;
        int id;
    private:
};

#endif // RACE_H
