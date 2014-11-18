#include "Feat.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Feat::nbFeats = 0;
Feat** Feat::listFeats = (Feat**)(malloc(sizeof(Feat*)*1000));

Feat::Feat()
{
    Feat::listFeats[Feat::nbFeats] = this;
    this->id = Feat::nbFeats;
    Feat::nbFeats++;
    this->name = (char*)"default name";
    this->listTalents = (Talent**)malloc(sizeof(Talent*)*300);
    this->nbTalents = 0;
}

Feat::~Feat()
{
    //dtor
}

int Feat::getId()
{
    return this->id;
}

int Feat::addTalent(Talent* newTalent)
{
    this->listTalents[this->nbTalents] = newTalent;
    this->nbTalents++;

    return 0;
}

Feat* Feat::getFeatByName(const char* featName)
{
    int i = 0;

    for(i=0; i<Feat::nbFeats; i++)
    {
        if(strcmp(featName,Feat::listFeats[i]->name) == 0)
        {
            return Feat::listFeats[i];
        }
    }
    printf("Feat not found\n");
    return NULL;
}
