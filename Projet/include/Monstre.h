#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
#include <string>
#include "loot.h"
class Monstre
{
    public:
        Monstre();
        virtual ~Monstre();
        char* getName();
        void setName(char* n);
        float getLevel();
        void setLevel( float l);
        int getXp();
        void setXp(int x);
    protected:
        int iD_monstre;
        char* name;
        float level;
        int xp;
        int speed; //en case
    private:

};

#endif // MONSTRE_H
