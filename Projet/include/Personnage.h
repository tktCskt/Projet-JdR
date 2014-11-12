#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
#include "Classe.h"
#include "Race.h"

class Personnage
{
     public:
        Personnage();
        virtual ~Personnage();
        int getXp();
        void setXp(int x);
        char* getLastName();
        void setLastName(char* ln);
        char* getFirstName();
        void setFirstName(char* fn);
        char* getNickName();
        void setNickName(char* nm);
        char* getAlignement();
        void setAlignement(char* a);
        char* getDescription();
        void setDescription(char* desc);
        int getAge();
        void setAge(int a);
        char* getM_taille();
        void setM_taille(char* m_taille);
        int getForce();
        void setForce(int f);
        int getDexterite();
        void setDexterite(int d);
        int getConstitution();
        void setConstitution(int c);
        int getIntelligence();
        void setIntelligence(int i);
        int getSagesse();
        void setSagesse(int s);
        int getCharisme();
        void setCharisme(int c);
        int getId_race();
        void setId_race(int r);
        int getPv_max();
        void setPv_max(int p);
        int getSauv_ref();
        void setSauv_ref(int r);
        int getSauv_vig();
        void setSauv_vig(int v);
        int getSauv_vol();
        void setSauv_vol(int v);
         int getCa_temp();
        void setCa_temp(int c);
        int getBba();
        void setBba(int b);
        int getInit();
        void setInit(int i);

        Race getRace();
        int setRace(char* newRace, char* bonus);
        int setRace(Race newRace, char* bonus);

        Classe getClasse();
        int setClasse(char* newClasse);
        int setClasse(Classe newClasse);

        int setAbilities(char* mode, int newAbilities[6]);



    int XP;
    int table_classe[20][20];// id_classe, niveau
    int iD_perso;
    char* lastName;
    char* firstName;
    char* nickName;
    char* alignement;
    char* description;
    int age;
    char* m_taille;
    int force;
    int dexterite;
    int constitution;
    int intelligence;
    int sagesse;
    int charisme;
    int id_race;
    int pv_max;
    int sauv_ref;
    int sauv_vig;
    int sauv_vol;
    int ca_temp;
    int bba;
    int init;
    int speed; //en case
    int** table_comp;// id_comp, points
    protected:
        Race race;
        Classe classe;
    private:

};

#endif // PERSONNAGE_H
