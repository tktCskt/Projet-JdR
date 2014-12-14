#include "classe.h"
#include "evolution.h"
#include "stdlib.h"
#include "Competence.h"
#include <stdio.h>

int Classe::nbClasses = 0;
Classe* Classe::listClasses = (Classe*)(malloc(sizeof(Classe)*50));

Classe::Classe()
{
    this->skills = (bool*)malloc(sizeof(bool)*Competence::nbSkills);
    this->bab = (int*)malloc(sizeof(int)*20);
    this->reflexe = (int*)malloc(sizeof(int)*20);
    this->volonte = (int*)malloc(sizeof(int)*20);
    this->vigueur = (int*)malloc(sizeof(int)*20);
    int i = 0;
    for(i = 0; i < Competence::nbSkills; i++)
    {
        this->skills[i] = false;
    }
}

Classe::~Classe()
{
    //dtor
}

int Classe::addSkillByName(char* skillName)
{
    int i = 0;
    while(i < Competence::nbSkills && strcmp(skillName, Competence::listSkills[i]->name))
    {
        i++;
    }
    if(i >= Competence::nbSkills)
    {
        printf("Error addSkillByName : %s\n", skillName);
        return -1;
    }
    else
    {
        this->skills[i] = true;
    }
    return 0;
}
