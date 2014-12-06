#ifndef FEAT_H
#define FEAT_H
#include <conio.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "Talent.h"

class Feat
{
    public:
        Feat();
        virtual ~Feat();
        void save(MYSQL* con, int i);
        char* getName();

        /*TODO prerequis*/
        char* name;
        int nbTalents;
        Talent** listTalents;
        void save(MYSQL* con, Feat** listFeats, int i);
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
