#include "race.h"
#include <stdlib.h>

int Race::nbRaces = 0;
Race* Race::listRaces = (Race*)(malloc(sizeof(Race)*50));

Race::Race()
{
    //ctor
}

Race::~Race()
{
    //dtor
}
// getter possible
char *Race::getName()
{
    return nom;
}

char *Race::getDescription()
{
    return description;
}




//setter possible

void Race::setName(char* n)
{
    nom = n;
}
void Race::setDescription(char* desc)
{
    description = desc;
}
