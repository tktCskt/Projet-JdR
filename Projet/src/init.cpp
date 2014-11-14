#include "init.h"
#include "Race.h"
#include "Talent.h"
#include "Competence.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int initRaces()
{
    Race* demiElfe = new Race();
    demiElfe->name = (char*)"Demi-Elfe";
    demiElfe->description = (char*)"La race des demi elfes";

    Race* demiOrc = new Race();
    demiOrc->name = (char*)"Demi-Orc";
    demiOrc->description = (char*)"La race des demi orcs";

    Race* elfe = new Race();
    elfe->name = (char*)"Elfe";
    elfe->description = (char*)"La race des elfes";
    elfe->addFeat(Talent::getFeatByName("Intelligence modificator 2"));
    elfe->addFeat(Talent::getFeatByName("Dexterity modificator 2"));
    elfe->addFeat(Talent::getFeatByName("Constitution modificator -2"));

    Race* gnome = new Race();
    gnome->name = (char*)"Gnome";
    gnome->description = (char*)"La race des gnomes";
    gnome->addFeat(Talent::getFeatByName("Constitution modificator 2"));
    gnome->addFeat(Talent::getFeatByName("Charisma modificator 2"));
    gnome->addFeat(Talent::getFeatByName("Strength modificator -2"));

    Race* halfelin = new Race();
    halfelin->name = (char*)"Halfelin";
    halfelin->description = (char*)"La race des halfelins";
    halfelin->addFeat(Talent::getFeatByName("Charisma modificator 2"));
    halfelin->addFeat(Talent::getFeatByName("Dexterity modificator 2"));
    halfelin->addFeat(Talent::getFeatByName("Strength modificator -2"));

    Race* humain = new Race();
    humain->name = (char*)"Humain";
    humain->description = (char*)"La race des humains";

    Race* nain = new Race();
    nain->name = (char*)"Nain";
    nain->description = (char*)"La race des nains";
    nain->addFeat(Talent::getFeatByName("Constitution modificator 2"));
    nain->addFeat(Talent::getFeatByName("Wisdom modificator 2"));
    nain->addFeat(Talent::getFeatByName("Charisma modificator -2"));

    return 0;

}

int initFeats()
{
    int i;

    Talent** f_strengthModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_dexterityModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_constitutionModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_intelligenceModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_wisdomModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_charismaModif = (Talent**)malloc(sizeof(Talent*)*21);

    for(i=-10; i<=10; i++)
    {
        char* value = (char*)malloc(sizeof(char)*16);
        itoa(i,value,10);

        f_strengthModif[i] = new Talent();
        f_strengthModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_strengthModif[i]->name,"Strength modificator ");
        strcat(f_strengthModif[i]->name,value);
        f_strengthModif[i]->description = (char*)"Modify strength";
        f_strengthModif[i]->type = STRENGTH_MODIF;
        f_strengthModif[i]->value = i;

        f_dexterityModif[i] = new Talent();
        f_dexterityModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_dexterityModif[i]->name,"Dexterity modificator ");
        strcat(f_dexterityModif[i]->name,value);
        f_dexterityModif[i]->description = (char*)"Modify dexterity";
        f_dexterityModif[i]->type = DEXTERITY_MODIF;
        f_dexterityModif[i]->value = i;

        f_constitutionModif[i] = new Talent();
        f_constitutionModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_constitutionModif[i]->name,"Constitution modificator ");
        strcat(f_constitutionModif[i]->name,value);
        f_constitutionModif[i]->description = (char*)"Modify constitution";
        f_constitutionModif[i]->type = CONSTITUTION_MODIF;
        f_constitutionModif[i]->value = i;

        f_intelligenceModif[i] = new Talent();
        f_intelligenceModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_intelligenceModif[i]->name,"Intelligence modificator ");
        strcat(f_intelligenceModif[i]->name,value);
        f_intelligenceModif[i]->description = (char*)"Modify intelligence";
        f_intelligenceModif[i]->type = INTELLIGENCE_MODIF;
        f_intelligenceModif[i]->value = i;

        f_wisdomModif[i] = new Talent();
        f_wisdomModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_wisdomModif[i]->name,"Wisdom modificator ");
        strcat(f_wisdomModif[i]->name,value);
        f_wisdomModif[i]->description = (char*)"Modify wisdom";
        f_wisdomModif[i]->type = WISDOM_MODIF;
        f_wisdomModif[i]->value = i;

        f_charismaModif[i] = new Talent();
        f_charismaModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(f_charismaModif[i]->name,"Charisma modificator ");
        strcat(f_charismaModif[i]->name,value);
        f_charismaModif[i]->description = (char*)"Modify charisma";
        f_charismaModif[i]->type = CHARISMA_MODIF;
        f_charismaModif[i]->value = i;

        free(value);
    }

    Talent** f_acrobaticsModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_appraiseModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_bluffModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_climbModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_craftModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_diplomacyModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_disableDeviceModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_disguiseModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_escape = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_fly = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_handleAnimalModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_healModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_intimidateModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_knowledgeModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_linguisticsModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_perceptionModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_performModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_professionModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_rideModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_sleightOfHandModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_spellCraftmodif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_stealthModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_survivalModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_swimModif = (Talent**)malloc(sizeof(Talent*)*21);
    Talent** f_umdModif = (Talent**)malloc(sizeof(Talent*)*21);

    for(i=-10; i<=10; i++)
    {
        char* value = (char*)malloc(sizeof(char)*16);
        itoa(i,value,10);

        f_acrobaticsModif[i] = new Talent();
    }

    return 0;
}

int initSkills()
{
    Competence* acrobaties = new Competence();
    acrobaties->name = (char*)"Acrobaties";
    acrobaties->description = (char*)"Competence d'acrobaties";

    Competence* adm = new Competence();
    adm->name = (char*)"Art de la magie";
    adm->description = (char*)"Competence d'art de la magie";

    Competence* art_ = new Competence();
    art_->name = (char*)"Artisanat";
    art_->description = (char*)"Competence d'artisanat";

    Competence* bluff = new Competence();
    bluff->name = (char*)"Bluff";
    bluff->description = (char*)"Competence de bluff";

    Competence* con_ = new Competence();
    con_->name = (char*)"Connaissance";
    con_->description = (char*)"Competence de connaissance";

    Competence* deguisement = new Competence();
    deguisement->name = (char*)"Deguisement";
    deguisement->description = (char*)"Competence de deguisement";

    Competence* diplomatie = new Competence();
    diplomatie->name = (char*)"Diplomatie";
    diplomatie->description = (char*)"Competence de diplomatie";

    Competence* discretion = new Competence();
    discretion->name = (char*)"Discretion";
    discretion->description = (char*)"Competence de discretion";

    Competence* dressage = new Competence();
    dressage->name = (char*)"Dressage";
    dressage->description = (char*)"Competence de dressage";

    Competence* equitation = new Competence();
    equitation->name = (char*)"Equitation";
    equitation->description = (char*)"Competence d'equitation";

    Competence* escalade = new Competence();
    escalade->name = (char*)"Escalade";
    escalade->description = (char*)"Competence d'escalade";

    Competence* escamotage = new Competence();
    escamotage->name = (char*)"Escamotage";
    escamotage->description = (char*)"Competence d'escamotage";

    Competence* estimation = new Competence();
    estimation->name = (char*)"Estimation";
    estimation->description = (char*)"Competence d'estimation";

    Competence* evasion = new Competence();
    evasion->name = (char*)"Evasion";
    evasion->description = (char*)"Competence d'Evasion";

    Competence* intimidation = new Competence();
    intimidation->name = (char*)"Intimidation";
    intimidation->description = (char*)"Competence d'intimidation";

    Competence* linguistique = new Competence();
    linguistique->name = (char*)"Linguistique";
    linguistique->description = (char*)"Competence de linguistique";

    Competence* natation = new Competence();
    natation->name = (char*)"Natation";
    natation->description = (char*)"Competence de natation";

    Competence* perception = new Competence();
    perception->name = (char*)"Perception";
    perception->description = (char*)"Competence de perception";

    Competence* pSecours = new Competence();
    pSecours->name = (char*)"Premiers secours";
    pSecours->description = (char*)"Competence de premiers secours";

    Competence* profession = new Competence();
    profession->name = (char*)"Profession";
    profession->description = (char*)"Competence de profession";

    Competence* representation = new Competence();
    representation->name = (char*)"Representation";
    representation->description = (char*)"Competence de representation";

    Competence* sabotage = new Competence();
    sabotage->name = (char*)"Sabotage";
    sabotage->description = (char*)"Competence de sabotage";

    Competence* survie = new Competence();
    survie->name = (char*)"Survie";
    survie->description = (char*)"Competence de survie";

    Competence* uom = new Competence();
    uom->name = (char*)"Utilisation d'objets magiques";
    uom->description = (char*)"Competence d'utilisation des objets magiques";

    Competence* vol = new Competence();
    vol->name = (char*)"Vol";
    vol->description = (char*)"Competence de vol";

    return 0;
}
