#include "race.h"
#include <stdlib.h>
#include <string.h>

#define RACE_NAME_SIZE_MAX 50
#define RACE_DESCRIPTION_SIZE_MAX 1024

int Race::nbRaces = 0;
Race** Race::listRaces = (Race**)(malloc(sizeof(Race*)*50));

Race::Race()
{
    Race::listRaces[Race::nbRaces] = this;
    Race::nbRaces++;
    this->table_talent = (Talent**)malloc(sizeof(Talent*)*300);
    this->nbFeats = 0;
    this->name = (char*)malloc(sizeof(char)*RACE_NAME_SIZE_MAX);
    strcpy(this->name, "default name");
    this->description = (char*)malloc(sizeof(char)*RACE_DESCRIPTION_SIZE_MAX);
    strcpy(this->description, "default description");
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

int Race::setName(char* newName)
{
    if(strlen(newName) > RACE_NAME_SIZE_MAX)
    {
        strcpy(this->name, "default name");
        return -1;
    }
    else
    {
        strcpy(this->name, newName);
        return 0;
    }
}
int Race::setDescription(char* newDescription)
{
    if(strlen(newDescription) > RACE_DESCRIPTION_SIZE_MAX)
    {
        strcpy(this->description, "default description");
        return -1;
    }
    else
    {
        strcpy(this->description, newDescription);
        return 0;
    }
}

int Race::addFeat(Talent* newFeat)
{
    this->table_talent[nbFeats] = newFeat;
    this->nbFeats++;

    return 0;
}
