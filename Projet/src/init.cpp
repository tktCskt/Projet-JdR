#include "init.h"
#include "Race.h"
#include "Talent.h"
#include "Competence.h"
#include <stdlib.h>
#include <string.h>

int initRaces()
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

    return 0;

}

int initFeats()
{
    int i;

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

    return 0;
}

int initSkills()
{
    int r = 0;

    Competence* acrobaties = new Competence();
    r+=acrobaties->setName("Acrobaties");
    r+=acrobaties->setDescription("Competence d'acrobaties");

    Competence* adm = new Competence();
    r+=adm->setName("Art de la magie");
    r+=adm->setDescription("Competence d'art de la magie");

    Competence* art_ = new Competence();
    r+=art_->setName("Artisanat");
    r+=art_->setDescription("Competence d'artisanat");

    Competence* bluff = new Competence();
    r+=bluff->setName("Bluff");
    r+=bluff->setDescription("Competence de bluff");

    Competence* con_ = new Competence();
    r+=con_->setName("Connaissance");
    r+=con_->setDescription("Competence de connaissance");

    Competence* deguisement = new Competence();
    r+=deguisement->setName("Deguisement");
    r+=deguisement->setDescription("Competence de deguisement");

    Competence* diplomatie = new Competence();
    r+=diplomatie->setName("Diplomatie");
    r+=diplomatie->setDescription("Competence de diplomatie");

    Competence* discretion = new Competence();
    r+=discretion->setName("Discretion");
    r+=discretion->setDescription("Competence de discretion");

    Competence* dressage = new Competence();
    r+=dressage->setName("Dressage");
    r+=dressage->setDescription("Competence de discretion");

    Competence* equitation = new Competence();
    r+=equitation->setName("Equitation");
    r+=equitation->setDescription("Competence d'equitation");

    Competence* escalade = new Competence();
    r+=escalade->setName("Escalade");
    r+=escalade->setDescription("Competence d'escalade");

    Competence* escamotage = new Competence();
    r+=escamotage->setName("Escamotage");
    r+=escamotage->setDescription("Competence d'escamotage");

    Competence* estimation = new Competence();
    r+=estimation->setName("Estimation");
    r+=estimation->setDescription("Competence d'estimation");

    Competence* evasion = new Competence();
    r+=evasion->setName("Evasion");
    r+=evasion->setDescription("Competence d'Evasion");

    Competence* intimidation = new Competence();
    r+=intimidation->setName("Intimidation");
    r+=intimidation->setDescription("Competence d'intimidation");

    Competence* linguistique = new Competence();
    r+=linguistique->setName("Linguistique");
    r+=linguistique->setDescription("Competence de linguistique");

    Competence* natation = new Competence();
    r+=natation->setName("Natation");
    r+=natation->setDescription("Competence de natation");

    Competence* perception = new Competence();
    r+=perception->setName("Perception");
    r+=perception->setDescription("Competence de perception");

    Competence* pSecours = new Competence();
    r+=pSecours->setName("Premiers secours");
    r+=pSecours->setDescription("Competence de premiers secours");

    Competence* profession = new Competence();
    r+=profession->setName("Profession");
    r+=profession->setDescription("Competence de profession");

    Competence* representation = new Competence();
    r+=representation->setName("Representation");
    r+=representation->setDescription("Competence de representation");

    Competence* sabotage = new Competence();
    r+=sabotage->setName("Sabotage");
    r+=sabotage->setDescription("Competence de sabotage");

    Competence* survie = new Competence();
    r+=survie->setName("Survie");
    r+=survie->setDescription("Competence de survie");

    Competence* uom = new Competence();
    r+=uom->setName("Utilisation d'objets magiques");
    r+=uom->setDescription("Competence d'utilisation des objets magiques");

    Competence* vol = new Competence();
    r+=vol->setName("Vol");
    r+=vol->setDescription("Competence de vol");

    return r;
}
