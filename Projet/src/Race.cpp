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
    this->listFeats = (Feat**)malloc(sizeof(Feat*)*30);
    this->nbFeats = 0;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
}

Race::~Race()
{
    free(this->listFeats);
}

int Race::addFeat(Feat* newFeat)
{
    this->listFeats[nbFeats] = newFeat;
    this->nbFeats++;

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
