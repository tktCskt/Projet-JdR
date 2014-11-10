#include "race.h"

Race::Race()
{
    //ctor
}

Race::~Race()
{
    //dtor
}
// getter possible
char *Race::getNom()
{
    return nom;
}

char *Race::getDescription()
{
    return description;
}




//setter possible

void Race::setNom(char* n)
{
    nom = n;
}
void Race::setDescription(char* desc)
{
    description = desc;
}
