#include "race.h"
#include <stdlib.h>

int Race::nbRaces = 0;
Race** Race::listRaces = (Race**)(malloc(sizeof(Race*)*50));

Race::Race()
{
    Race::listRaces[Race::nbRaces] = this;
    Race::nbRaces++;
    this->table_talent = (Talent**)malloc(sizeof(Talent*)*300);
    this->nbFeats = 0;
}

Race::~Race()
{
    free(this->table_talent);
}

char *Race::getName()
{
    return this->name;
}

char *Race::getDescription()
{
    return description;
}

void Race::setName(char* newName)
{
    this->name = newName;
}
void Race::setDescription(char* desc)
{
    description = desc;
}

int Race::addFeat(Talent* newFeat)
{
    this->table_talent[nbFeats] = newFeat;
    this->nbFeats++;

    return 0;
}
