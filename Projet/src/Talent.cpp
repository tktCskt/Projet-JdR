#include "talent.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Talent::nbTalents = 0;
Talent** Talent::listTalents = (Talent**)(malloc(sizeof(Talent*)*3000));

Talent::Talent()
{
    Talent::listTalents[Talent::nbTalents] = this;
    this->id = nbTalents;
    this->value = 0;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
    Talent::nbTalents++;
}

Talent::~Talent()
{
    //dtor
}

Talent* Talent::getTalentByName(const char* talentName)
{
    int i = 0;

    for(i=0; i<Talent::nbTalents; i++)
    {
        if(strcmp(talentName,Talent::listTalents[i]->name) == 0)
        {
            return Talent::listTalents[i];
        }
    }
    return NULL;
}
