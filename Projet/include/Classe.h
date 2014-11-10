#ifndef CLASSE_H
#define CLASSE_H
#include "evolution.h"
#include <iostream>
#include <string>
class Classe
{
    public:
        Classe();
        virtual ~Classe();
       char* getName();
       char* getDescription();
       int getDv();
       int getGain_comp();
       int getReq_niv();
       void setReq_niv(int r);
       void setName(char* n);
       void setDescription(char* desc);
       void setDv( int d);
       void setGain_comp(int g);
    protected:
    private:
    int iD_classe;
    char* name;
    char* description;
    int** table_bba;  // variable globale (haute, moyenne, faible) bonus
    int table_jet_ref[20];// variable globale (haute, moyenne, faible) reflexe
    int table_jet_vol[20];// variable globale (haute, moyenne, faible) volonte
    int table_jet_vig[20];// variable globale (haute, moyenne, faible) vigueur
    int table_talent[20];// niveau, id_talent
    int dv;
    int req_niv;
    int** table_race_req; // id_race
    char* table_alignement[];
    int table_competence[300][300]; // id_competence, point
    int gain_comp;
    int table_competence_de_classe[300];// id_competence
};

#endif // CLASSE_H
