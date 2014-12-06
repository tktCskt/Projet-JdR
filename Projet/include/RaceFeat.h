#ifndef RACEFEAT_H
#define RACEFEAT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <winsock.h>
#include <MYSQL/mysql.h>

class RaceFeat
{
    public:
        RaceFeat();
        virtual ~RaceFeat();
        static void save(MYSQL* con, int id_race, int id_feat);
    protected:
    private:
    int id_race;
    int id_feat;
};

#endif // RACEFEAT_H
