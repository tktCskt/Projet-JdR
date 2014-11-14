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

Competence::~Competence()
{
}
