#include "competence.h"

Competence::Competence()
{
    //ctor
}

Competence::~Competence()
{
    //dtor
}
char* Competence::getDescription()
{
    return description;
}

void Competence::setDescription(char* desc)
{
   description = desc;
}
