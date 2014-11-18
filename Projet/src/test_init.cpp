#include "test_init.h"
#include "Race.h"
#include "Talent.h"
#include "Competence.h"
#include <stdio.h>
#include <string.h>

int test_init_races()
{
    int i = 0;
    int j = 0;

    printf("nb_races = %d\n", Race::nbRaces);

    for(i=0; i<Race::nbRaces; i++)
    {
        printf("Race %d : %s\nDescription : %s\n", i, Race::listRaces[i]->name, Race::listRaces[i]->description);
        for(j=0; j<Race::listRaces[i]->nbTalents; j++)
        {
            printf("Talent %d of %ss, name = %s id = %d\n", j, Race::listRaces[i]->name, Race::listRaces[i]->table_talent[j]->name, Race::listRaces[i]->table_talent[j]->id);
        }
    }

    return 0;
}

int test_init_talents()
{
    int i = 0;

    printf("nb_Talents = %d\n", Talent::nbTalents);

    for(i=0; i<Talent::nbTalents; i++)
    {
        printf("Talent %d : %s, type = %d, value %d\nDescription : %s\n", i, Talent::listTalents[i]->name, Talent::listTalents[i]->type, Talent::listTalents[i]->value, Talent::listTalents[i]->description);
    }

    return 0;
}

int test_init_skills()
{
    int i = 0;

    printf("nb_skills = %d\n", Competence::nbSkills);

    for(i=0; i<Competence::nbSkills; i++)
    {
        printf("Skill %d id %d name %s \nDescription %s\n", i, Competence::listSkills[i]->id, Competence::listSkills[i]->name, Competence::listSkills[i]->description);
    }

    return 0;
}
