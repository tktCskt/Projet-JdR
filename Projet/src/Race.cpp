#include "race.h"
#include <stdlib.h>
#include <string.h>

int Race::nbRaces = 0;
Race** Race::listRaces = (Race**)(malloc(sizeof(Race*)*50));

Race::Race()
{
    Race::listRaces[Race::nbRaces] = this;
    Race::nbRaces++;
    this->table_talent = (Talent**)malloc(sizeof(Talent*)*300);
    this->nbFeats = 0;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
}

Race::~Race()
{
    free(this->table_talent);
}

int Race::addFeat(Talent* newFeat)
{
    this->table_talent[nbFeats] = newFeat;
    this->nbFeats++;

    return 0;
}
