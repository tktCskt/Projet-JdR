#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
#include <string>
class Monstre
{
    public:
        Monstre();
        virtual ~Monstre();
    protected:
            char* name;
    private:
    int idMonstre;

    int level;
    int XP;
};

#endif // MONSTRE_H
