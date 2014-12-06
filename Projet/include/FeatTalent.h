#ifndef FEATTALENT_H
#define FEATTALENT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <winsock.h>
#include <MYSQL/mysql.h>

class FeatTalent
{
    public:
        FeatTalent();
        virtual ~FeatTalent();
    static void save(MYSQL* con, int id_feat, int id_talent);
    protected:
    private:
    int id_feat;
    int id_talent;
};

#endif // FEATTALENT_H
