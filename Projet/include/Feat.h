#ifndef FEAT_H
#define FEAT_H

#include "Talent.h"

class Feat
{
    public:
        Feat();
        virtual ~Feat();

        /*TODO prerequis*/
        char* name;
        int nbTalents;
        Talent** listTalents;

        static int nbFeats;
        static Feat** listFeats;

        int getId();
        int addTalent(Talent* newTalent);
        static Feat* getFeatByName(const char* featName);


    protected:
        int id;
    private:
};

#endif // FEAT_H
