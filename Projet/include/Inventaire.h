#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "personnage.h"
#include "objet.h"
#include <iostream>
#include <string>
class Inventaire
{
    public:
        Inventaire();
        virtual~Inventaire();

    protected:
    private:
    int id_personnage;
    int id_objet;
    bool equipe;
};

#endif // INVENTAIRE_H
