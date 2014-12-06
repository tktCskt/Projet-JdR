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
    this->name = (char*)"default name";
    this->description = (char*)"default description";
    this->type = 0;
    this->value = 0;
    Talent::nbTalents++;
}

void Talent::save(MYSQL* con)
 {
     char* typeString = (char*)malloc(10);
     itoa(this->type, typeString,10);
     char* valueString = (char*)malloc(10);
     itoa(this->value, valueString,10);

     char* request = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO talent(name, description, type, value) VALUES ( \"");
     strcat(request, this->name);
     strcat(request, "\",\"");
     strcat(request, this->description);
     strcat(request, "\", ");
     strcat(request, typeString);
     strcat(request, ", ");
     strcat(request, valueString);
     strcat(request, ");");
     mysql_query(con, request);
 }

Talent::~Talent()
{
    //dtor
}

char* Talent::getName()
{
    return name;
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
    printf("Talent not found\n");
    return NULL;
}
