#ifndef CLASSE_H
#define CLASSE_H
#include "evolution.h"
#include "Feat.h"
#include <iostream>
#include <string>

#define LOW_BAB {0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10}
#define MEDIUM_BAB {0,1,2,3,3,4,5,6,6,7,8,9,9,10,11,12,12,13,14,15}
#define HIGH_BAB {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}


class Classe
{
    public:
        Classe();
        virtual ~Classe();

        static int nbClasses;
        static Classe* listClasses;
        char* name;
        char* description;
        int dv;
        int* bab;
        int* reflexe;
        int* volonte;
        int* vigueur;
        Feat** dons[20];
        bool* skills;

        int addSkillByName(char*);
    protected:
    private:
    int id;



    int table_talent[20];
    int table_competence[300][300]; // id_competence, point
    int gain_comp;
};

#endif // CLASSE_H
