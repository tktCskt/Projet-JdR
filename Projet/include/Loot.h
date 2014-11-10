#ifndef LOOT_H
#define LOOT_H
#include "objet.h"
#include "monstre.h"
#include <iostream>
#include <string>
class Loot
{
    public:
        Loot();
        virtual ~Loot();
    protected:
    private:
    float probabilite;
};

#endif // LOOT_H
