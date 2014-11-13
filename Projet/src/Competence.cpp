#include "competence.h"
#include <stdlib.h>
#include <string.h>

#define SKILL_NAME_SIZE_MAX 50
#define SKILL_DESCRIPTION_SIZE_MAX 1024

int Competence::nbSkills = 0;
Competence** Competence::listSkills = (Competence**)(malloc(sizeof(Competence*)*50));

Competence::Competence()
{
    Competence::listSkills[Competence::nbSkills] = this;
    this->id = nbSkills;
    Competence::nbSkills++;
    this->name = (char*)malloc(sizeof(char)*SKILL_NAME_SIZE_MAX);
    strcpy(this->name, "default name");
    this->description = (char*)malloc(sizeof(char)*SKILL_DESCRIPTION_SIZE_MAX);
    strcpy(this->description, "default description");
}

Competence::~Competence()
{
    free(this->name);
    free(this->description);
}

int Competence::setName(char* newName)
{
    if(strlen(newName) > SKILL_NAME_SIZE_MAX)
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

int Competence::setDescription(char* newDescription)
{
    if(strlen(newDescription) > SKILL_DESCRIPTION_SIZE_MAX)
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

char* Competence::getName()
{
    return this->name;
}

char* Competence::getDescription()
{
    return this->description;
}
