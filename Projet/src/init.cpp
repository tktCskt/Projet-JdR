#include "init.h"
#include "Race.h"
#include "Talent.h"
#include <stdlib.h>
#include <string.h>

void initRaces()
{
    Race* demiElfe = new Race();
    demiElfe->setName("Demi-Elfe");
    demiElfe->setDescription("La race des demi elfes");

    Race* demiOrc = new Race();
    demiOrc->setName("Demi-Orc");
    demiOrc->setDescription("La race des demi orcs");

    Race* elfe = new Race();
    elfe->setName("Elfe");
    elfe->setDescription("La race des elfes");
    elfe->addFeat(Talent::getFeatByName("Intelligence modificator +2"));
    elfe->addFeat(Talent::getFeatByName("Dexterity modificator +2"));

    Race* gnome = new Race();
    gnome->setName("Gnome");
    gnome->setDescription("La race des gnomes");

    Race* halfelin = new Race();
    halfelin->setName("Halfelin");
    halfelin->setDescription("La race des halfelins");

    Race* humain = new Race();
    humain->setName("Humain");
    humain->setDescription("La race des humains");

    Race* nain = new Race();
    nain->setName("Nain");
    nain->setDescription("La race des nains");

}

void initFeats()
{
    int i = 0;

    Talent** f_strengthModif = (Talent**)malloc(sizeof(Talent*)*10);
    Talent** f_dexterityModif = (Talent**)malloc(sizeof(Talent*)*10);
    Talent** f_constitutionModif = (Talent**)malloc(sizeof(Talent*)*10);
    Talent** f_intelligenceModif = (Talent**)malloc(sizeof(Talent*)*10);
    Talent** f_wisdomModif = (Talent**)malloc(sizeof(Talent*)*10);
    Talent** f_charismaModif = (Talent**)malloc(sizeof(Talent*)*10);

    for(i=0; i<10; i++)
    {
        char* value = (char*)malloc(sizeof(char)*16);
        itoa(i,value,10);

        f_strengthModif[i] = new Talent();
        f_strengthModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_strengthModif[i]->name,"Strength modificator +");
        strcat(f_strengthModif[i]->name,value);
        f_strengthModif[i]->description = "Modify strength";
        f_strengthModif[i]->type = STRENGTH_MODIF;
        f_strengthModif[i]->value = i;

        f_dexterityModif[i] = new Talent();
        f_dexterityModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_dexterityModif[i]->name,"Dexterity modificator +");
        strcat(f_dexterityModif[i]->name,value);
        f_dexterityModif[i]->description = "Modify dexterity";
        f_dexterityModif[i]->type = DEXTERITY_MODIF;
        f_dexterityModif[i]->value = i;

        f_constitutionModif[i] = new Talent();
        f_constitutionModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_constitutionModif[i]->name,"Constitution modificator +");
        strcat(f_constitutionModif[i]->name,value);
        f_constitutionModif[i]->description = "Modify constitution";
        f_constitutionModif[i]->type = CONSTITUTION_MODIF;
        f_constitutionModif[i]->value = i;

        f_intelligenceModif[i] = new Talent();
        f_intelligenceModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_intelligenceModif[i]->name,"Intelligence modificator +");
        strcat(f_intelligenceModif[i]->name,value);
        f_intelligenceModif[i]->description = "Modify intelligence";
        f_intelligenceModif[i]->type = INTELLIGENCE_MODIF;
        f_intelligenceModif[i]->value = i;

        f_wisdomModif[i] = new Talent();
        f_wisdomModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_wisdomModif[i]->name,"Wisdom modificator +");
        strcat(f_wisdomModif[i]->name,value);
        f_wisdomModif[i]->description = "Modify wisdom";
        f_wisdomModif[i]->type = WISDOM_MODIF;
        f_wisdomModif[i]->value = i;

        f_charismaModif[i] = new Talent();
        f_charismaModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_charismaModif[i]->name,"Charisma modificator +");
        strcat(f_charismaModif[i]->name,value);
        f_charismaModif[i]->description = "Modify charisma";
        f_charismaModif[i]->type = CHARISMA_MODIF;
        f_charismaModif[i]->value = i;
    }
}
