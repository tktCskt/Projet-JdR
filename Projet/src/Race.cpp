#include "race.h"
#include <stdlib.h>
#include <string.h>

int Race::nbRaces = 0;
Race** Race::listRaces = (Race**)(malloc(sizeof(Race*)*50));

Race::Race()
{
    this->id = Race::nbRaces;
    Race::listRaces[Race::nbRaces] = this;
    Race::nbRaces++;
    this->table_talent = (Talent**)malloc(sizeof(Talent*)*300);
    this->nbTalents = 0;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
}

Race::~Race()
{
    free(this->table_talent);
}

int Race::addTalent(Talent* newTalent)
{
    this->table_talent[nbTalents] = newTalent;
    this->nbTalents++;

    return 0;
}

int Race::getId()
{
    return this->id;
}

void Race::setSize(enum size_ newSize)
{
    this->raceSize = newSize;
    /*TODO ADD FEAT*/
}

enum size_ Race::getSize()
{
    return this->raceSize;
};
