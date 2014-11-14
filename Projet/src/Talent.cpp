#include "talent.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Talent::nbFeats = 0;
Talent** Talent::listFeats = (Talent**)(malloc(sizeof(Talent*)*300));

Talent::Talent()
{
    Talent::listFeats[Talent::nbFeats] = this;
    this->id = nbFeats;
    this->value = 0;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
    Talent::nbFeats++;
}

Talent::~Talent()
{
    //dtor
}

Talent* Talent::getFeatByName(const char* featName)
{
    int i = 0;

    for(i=0; i<Talent::nbFeats; i++)
    {
        if(strcmp(featName,Talent::listFeats[i]->name) == 0)
        {
            return Talent::listFeats[i];
        }
    }
    return NULL;
}
