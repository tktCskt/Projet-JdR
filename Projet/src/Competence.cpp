#include "competence.h"
#include <stdlib.h>
#include <string.h>


int Competence::nbSkills = 0;
Competence** Competence::listSkills = (Competence**)(malloc(sizeof(Competence*)*50));

Competence::Competence()
{
    Competence::listSkills[Competence::nbSkills] = this;
    this->id = nbSkills;
    Competence::nbSkills++;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
}

 void Competence::save(MYSQL* con)
 {
     char* abilityString = (char*)malloc(10);
     itoa(this->ability, abilityString,10);

     char* request = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO competence(ability, name, description) VALUES (");
     strcat(request, abilityString);
     strcat(request, ",\"");
     strcat(request, this->name);
     strcat(request, "\",\"");
     strcat(request, this->description);
     strcat(request, "\");");

     mysql_query(con, request);
 }
Competence::~Competence()
{
}
