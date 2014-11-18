#include "init.h"
#include "Race.h"
#include "Talent.h"
#include "Competence.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define RANGE_MIN -10
#define RANGE_MAX 10

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
    elfe->addTalent(Talent::getTalentByName("Intelligence modificator 2"));
    elfe->addTalent(Talent::getTalentByName("Dexterity modificator 2"));
    elfe->addTalent(Talent::getTalentByName("Constitution modificator -2"));

    Race* gnome = new Race();
    gnome->name = (char*)"Gnome";
    gnome->description = (char*)"La race des gnomes";
    gnome->addTalent(Talent::getTalentByName("Constitution modificator 2"));
    gnome->addTalent(Talent::getTalentByName("Charisma modificator 2"));
    gnome->addTalent(Talent::getTalentByName("Strength modificator -2"));

    Race* halfelin = new Race();
    halfelin->name = (char*)"Halfelin";
    halfelin->description = (char*)"La race des halfelins";
    halfelin->addTalent(Talent::getTalentByName("Charisma modificator 2"));
    halfelin->addTalent(Talent::getTalentByName("Dexterity modificator 2"));
    halfelin->addTalent(Talent::getTalentByName("Strength modificator -2"));

    Race* humain = new Race();
    humain->name = (char*)"Humain";
    humain->description = (char*)"La race des humains";

    Race* nain = new Race();
    nain->name = (char*)"Nain";
    nain->description = (char*)"La race des nains";
    nain->addTalent(Talent::getTalentByName("Constitution modificator 2"));
    nain->addTalent(Talent::getTalentByName("Wisdom modificator 2"));
    nain->addTalent(Talent::getTalentByName("Charisma modificator -2"));

    return 0;

}

int initTalents()
{
    int i;

    Talent** t_strengthModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_dexterityModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_constitutionModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_intelligenceModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_wisdomModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_charismaModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);

    Talent** t_acrobaticsModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_appraiseModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_bluffModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_climbModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_craftModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_diplomacyModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_disableDeviceModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_disguiseModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_escapeModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_flyModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_handleAnimalModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_healModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_intimidateModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_knowledgeModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_linguisticsModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_perceptionModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_performModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_professionModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_rideModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_senseMotiveModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_sleightOfHandModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_spellCraftModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_stealthModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_survivalModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_swimModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);
    Talent** t_umdModif = (Talent**)malloc(sizeof(Talent*)*RANGE_MAX-RANGE_MIN+1);

    for(i=RANGE_MIN; i<=RANGE_MAX; i++)
    {
        char* value = (char*)malloc(sizeof(char)*16);
        itoa(i,value,10);

        t_strengthModif[i] = new Talent();
        t_strengthModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_strengthModif[i]->name,"Strength modificator ");
        strcat(t_strengthModif[i]->name,value);
        t_strengthModif[i]->description = (char*)"Modify strength";
        t_strengthModif[i]->type = STRENGTH_MODIF;
        t_strengthModif[i]->value = i;

        t_dexterityModif[i] = new Talent();
        t_dexterityModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_dexterityModif[i]->name,"Dexterity modificator ");
        strcat(t_dexterityModif[i]->name,value);
        t_dexterityModif[i]->description = (char*)"Modify dexterity";
        t_dexterityModif[i]->type = DEXTERITY_MODIF;
        t_dexterityModif[i]->value = i;

        t_constitutionModif[i] = new Talent();
        t_constitutionModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_constitutionModif[i]->name,"Constitution modificator ");
        strcat(t_constitutionModif[i]->name,value);
        t_constitutionModif[i]->description = (char*)"Modify constitution";
        t_constitutionModif[i]->type = CONSTITUTION_MODIF;
        t_constitutionModif[i]->value = i;

        t_intelligenceModif[i] = new Talent();
        t_intelligenceModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_intelligenceModif[i]->name,"Intelligence modificator ");
        strcat(t_intelligenceModif[i]->name,value);
        t_intelligenceModif[i]->description = (char*)"Modify intelligence";
        t_intelligenceModif[i]->type = INTELLIGENCE_MODIF;
        t_intelligenceModif[i]->value = i;

        t_wisdomModif[i] = new Talent();
        t_wisdomModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_wisdomModif[i]->name,"Wisdom modificator ");
        strcat(t_wisdomModif[i]->name,value);
        t_wisdomModif[i]->description = (char*)"Modify wisdom";
        t_wisdomModif[i]->type = WISDOM_MODIF;
        t_wisdomModif[i]->value = i;

        t_charismaModif[i] = new Talent();
        t_charismaModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_charismaModif[i]->name,"Charisma modificator ");
        strcat(t_charismaModif[i]->name,value);
        t_charismaModif[i]->description = (char*)"Modify charisma";
        t_charismaModif[i]->type = CHARISMA_MODIF;
        t_charismaModif[i]->value = i;

        t_acrobaticsModif[i] = new Talent();
        t_acrobaticsModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_acrobaticsModif[i]->name,"Acrobatics modificator ");
        strcat(t_acrobaticsModif[i]->name,value);
        t_acrobaticsModif[i]->description = (char*)"Modify acrobatics";
        t_acrobaticsModif[i]->type = ACROBATICS_MODIF;
        t_acrobaticsModif[i]->value = i;

        t_appraiseModif[i] = new Talent();
        t_appraiseModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_appraiseModif[i]->name,"Appraise modificator ");
        strcat(t_appraiseModif[i]->name,value);
        t_appraiseModif[i]->description = (char*)"Modify appraise";
        t_appraiseModif[i]->type = APPRAISE_MODIF;
        t_appraiseModif[i]->value = i;

        t_bluffModif[i] = new Talent();
        t_bluffModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_bluffModif[i]->name,"Bluff modificator ");
        strcat(t_bluffModif[i]->name,value);
        t_bluffModif[i]->description = (char*)"Modify bluff";
        t_bluffModif[i]->type = BLUFF_MODIF;
        t_bluffModif[i]->value = i;

        t_climbModif[i] = new Talent();
        t_climbModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_climbModif[i]->name,"Climb modificator ");
        strcat(t_climbModif[i]->name,value);
        t_climbModif[i]->description = (char*)"Modify climb";
        t_climbModif[i]->type = CLIMB_MODIF;
        t_climbModif[i]->value = i;

        t_craftModif[i] = new Talent();
        t_craftModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_craftModif[i]->name,"Craft modificator ");
        strcat(t_craftModif[i]->name,value);
        t_craftModif[i]->description = (char*)"Modify craft";
        t_craftModif[i]->type = CRAFT_MODIF;
        t_craftModif[i]->value = i;

        t_diplomacyModif[i] = new Talent();
        t_diplomacyModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_diplomacyModif[i]->name,"Diplomacy modificator ");
        strcat(t_diplomacyModif[i]->name,value);
        t_diplomacyModif[i]->description = (char*)"Modify diplomacy";
        t_diplomacyModif[i]->type = DIPLOMACY_MODIF;
        t_diplomacyModif[i]->value = i;

        t_disableDeviceModif[i] = new Talent();
        t_disableDeviceModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_disableDeviceModif[i]->name,"DisableDevice modificator ");
        strcat(t_disableDeviceModif[i]->name,value);
        t_disableDeviceModif[i]->description = (char*)"Modify disableDevice";
        t_disableDeviceModif[i]->type = DISABLEDEVICE_MODIF;
        t_disableDeviceModif[i]->value = i;

        t_disguiseModif[i] = new Talent();
        t_disguiseModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_disguiseModif[i]->name,"Disguise modificator ");
        strcat(t_disguiseModif[i]->name,value);
        t_disguiseModif[i]->description = (char*)"Modify disguise";
        t_disguiseModif[i]->type = DISGUISE_MODIF;
        t_disguiseModif[i]->value = i;

        t_escapeModif[i] = new Talent();
        t_escapeModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_escapeModif[i]->name,"Escape modificator ");
        strcat(t_escapeModif[i]->name,value);
        t_escapeModif[i]->description = (char*)"Modify escape";
        t_escapeModif[i]->type = ESCAPE_MODIF;
        t_escapeModif[i]->value = i;

        t_flyModif[i] = new Talent();
        t_flyModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_flyModif[i]->name,"Fly modificator ");
        strcat(t_flyModif[i]->name,value);
        t_flyModif[i]->description = (char*)"Modify fly";
        t_flyModif[i]->type = FLY_MODIF;
        t_flyModif[i]->value = i;

        t_handleAnimalModif[i] = new Talent();
        t_handleAnimalModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_handleAnimalModif[i]->name,"HandleAnimal modificator ");
        strcat(t_handleAnimalModif[i]->name,value);
        t_handleAnimalModif[i]->description = (char*)"Modify handleAnimal";
        t_handleAnimalModif[i]->type = HANDLEANIMAL_MODIF;
        t_handleAnimalModif[i]->value = i;

        t_healModif[i] = new Talent();
        t_healModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_healModif[i]->name,"Heal modificator ");
        strcat(t_healModif[i]->name,value);
        t_healModif[i]->description = (char*)"Modify heal";
        t_healModif[i]->type = HEAL_MODIF;
        t_healModif[i]->value = i;

        t_intimidateModif[i] = new Talent();
        t_intimidateModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_intimidateModif[i]->name,"Intimidate modificator ");
        strcat(t_intimidateModif[i]->name,value);
        t_intimidateModif[i]->description = (char*)"Modify intimidate";
        t_intimidateModif[i]->type = INTIMIDATE_MODIF;
        t_intimidateModif[i]->value = i;

        t_knowledgeModif[i] = new Talent();
        t_knowledgeModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_knowledgeModif[i]->name,"Knowledge modificator ");
        strcat(t_knowledgeModif[i]->name,value);
        t_knowledgeModif[i]->description = (char*)"Modify knowledge";
        t_knowledgeModif[i]->type = KNOWLEDGE_MODIF;
        t_knowledgeModif[i]->value = i;

        t_linguisticsModif[i] = new Talent();
        t_linguisticsModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_linguisticsModif[i]->name,"Linguistics modificator ");
        strcat(t_linguisticsModif[i]->name,value);
        t_linguisticsModif[i]->description = (char*)"Modify linguistics";
        t_linguisticsModif[i]->type = LINGUISTICS_MODIF;
        t_linguisticsModif[i]->value = i;

        t_perceptionModif[i] = new Talent();
        t_perceptionModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_perceptionModif[i]->name,"Perception modificator ");
        strcat(t_perceptionModif[i]->name,value);
        t_perceptionModif[i]->description = (char*)"Modify perception";
        t_perceptionModif[i]->type = PERCEPTION_MODIF;
        t_perceptionModif[i]->value = i;

        t_performModif[i] = new Talent();
        t_performModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_performModif[i]->name,"Perform modificator ");
        strcat(t_performModif[i]->name,value);
        t_performModif[i]->description = (char*)"Modify perform";
        t_performModif[i]->type = PERFORM_MODIF;
        t_performModif[i]->value = i;

        t_professionModif[i] = new Talent();
        t_professionModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_professionModif[i]->name,"Profession modificator ");
        strcat(t_professionModif[i]->name,value);
        t_professionModif[i]->description = (char*)"Modify profession";
        t_professionModif[i]->type = PROFESSION_MODIF;
        t_professionModif[i]->value = i;

        t_rideModif[i] = new Talent();
        t_rideModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_rideModif[i]->name,"Ride modificator ");
        strcat(t_rideModif[i]->name,value);
        t_rideModif[i]->description = (char*)"Modify ride";
        t_rideModif[i]->type = RIDE_MODIF;
        t_rideModif[i]->value = i;

        t_senseMotiveModif[i] = new Talent();
        t_senseMotiveModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_senseMotiveModif[i]->name,"SenseMotive modificator ");
        strcat(t_senseMotiveModif[i]->name,value);
        t_senseMotiveModif[i]->description = (char*)"Modify senseMotive";
        t_senseMotiveModif[i]->type = SENSEMOTIVE_MODIF;
        t_senseMotiveModif[i]->value = i;

        t_sleightOfHandModif[i] = new Talent();
        t_sleightOfHandModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_sleightOfHandModif[i]->name,"SleightOfHand modificator ");
        strcat(t_sleightOfHandModif[i]->name,value);
        t_sleightOfHandModif[i]->description = (char*)"Modify sleightOfHand";
        t_sleightOfHandModif[i]->type = SLEIGHTOFHAND_MODIF;
        t_sleightOfHandModif[i]->value = i;

        t_spellCraftModif[i] = new Talent();
        t_spellCraftModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_spellCraftModif[i]->name,"SpellCraft modificator ");
        strcat(t_spellCraftModif[i]->name,value);
        t_spellCraftModif[i]->description = (char*)"Modify spellCraft";
        t_spellCraftModif[i]->type = SPELLCRAFT_MODIF;
        t_spellCraftModif[i]->value = i;

        t_stealthModif[i] = new Talent();
        t_stealthModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_stealthModif[i]->name,"Stealth modificator ");
        strcat(t_stealthModif[i]->name,value);
        t_stealthModif[i]->description = (char*)"Modify stealth";
        t_stealthModif[i]->type = STEALTH_MODIF;
        t_stealthModif[i]->value = i;

        t_survivalModif[i] = new Talent();
        t_survivalModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_survivalModif[i]->name,"Survival modificator ");
        strcat(t_survivalModif[i]->name,value);
        t_survivalModif[i]->description = (char*)"Modify survival";
        t_survivalModif[i]->type = SURVIVAL_MODIF;
        t_survivalModif[i]->value = i;

        t_swimModif[i] = new Talent();
        t_swimModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_swimModif[i]->name,"Swim modificator ");
        strcat(t_swimModif[i]->name,value);
        t_swimModif[i]->description = (char*)"Modify swim";
        t_swimModif[i]->type = SWIM_MODIF;
        t_swimModif[i]->value = i;

        t_umdModif[i] = new Talent();
        t_umdModif[i]->name = (char*)malloc(sizeof(char)*64);
        strcpy(t_umdModif[i]->name,"UseMagicDevice modificator ");
        strcat(t_umdModif[i]->name,value);
        t_umdModif[i]->description = (char*)"Modify useMagicDevice";
        t_umdModif[i]->type = UMD_MODIF;
        t_umdModif[i]->value = i;

        free(value);
    }

    return 0;
}

int initSkills()
{
    Competence* acrobatics = new Competence();
    acrobatics->name = (char*)"Acrobatics";
    acrobatics->description = (char*)"Acrobatics skill";
    acrobatics->ability = DEXTERITY;

    Competence* appraise = new Competence();
    appraise->name = (char*)"appraise";
    appraise->description = (char*)"Appraise skill";
    appraise->ability = INTELLIGENCE;

    Competence* bluff = new Competence();
    bluff->name = (char*)"Bluff";
    bluff->description = (char*)"Bluff skill";
    bluff->ability = CHARISMA;

    Competence*climb = new Competence();
    climb->name = (char*)"Climb";
    climb->description = (char*)"Climb skill";
    climb->ability = STRENGTH;

    Competence* craft = new Competence();
    craft->name = (char*)"Craft";
    craft->description = (char*)"Craft skill";
    craft->ability = INTELLIGENCE;

    Competence* diplomacy = new Competence();
    diplomacy->name = (char*)"Diplomacy";
    diplomacy->description = (char*)"Diplomacy skill";
    diplomacy->ability = CHARISMA;

    Competence* disableDevice = new Competence();
    disableDevice->name = (char*)"Disable Device";
    disableDevice->description = (char*)"Disable Device skill";
    disableDevice->ability = DEXTERITY;

    Competence* disguise = new Competence();
    disguise->name = (char*)"Disguise";
    disguise->description = (char*)"Disguise skill";
    disguise->ability = CHARISMA;

    Competence* escape = new Competence();
    escape->name = (char*)"Escape";
    escape->description = (char*)"Escape skill";
    escape->ability = DEXTERITY;

    Competence* fly = new Competence();
    fly->name = (char*)"Fly";
    fly->description = (char*)"Fly skill";
    fly->ability = DEXTERITY;

    Competence* handleAnimal = new Competence();
    handleAnimal->name = (char*)"Handle animal";
    handleAnimal->description = (char*)"Handle animal skill";
    handleAnimal->ability = CHARISMA;

    Competence* heal = new Competence();
    heal->name = (char*)"Heal";
    heal->description = (char*)"Heal skill";
    heal->ability = WISDOM;

    Competence* intimidate = new Competence();
    intimidate->name = (char*)"Intimidate";
    intimidate->description = (char*)"Intimidate skill";
    intimidate->ability = CHARISMA;

    Competence* knowledge = new Competence();
    knowledge->name = (char*)"Knowledge";
    knowledge->description = (char*)"Knowledge skill";
    knowledge->ability = INTELLIGENCE;

    Competence* linguistics = new Competence();
    linguistics->name = (char*)"Linguistics";
    linguistics->description = (char*)"Linguistics skill";
    linguistics->ability = INTELLIGENCE;

    Competence* perception = new Competence();
    perception->name = (char*)"Perception";
    perception->description = (char*)"Perception skill";
    perception->ability = WISDOM;

    Competence* perform = new Competence();
    perform->name = (char*)"Perform";
    perform->description = (char*)"Perform skill";
    perform->ability = CHARISMA;

    Competence* profession = new Competence();
    profession->name = (char*)"Profession";
    profession->description = (char*)"Profession skill";
    profession->ability = WISDOM;

    Competence* ride = new Competence();
    ride->name = (char*)"Ride";
    ride->description = (char*)"Ride skill";
    ride->ability = DEXTERITY;

    Competence* senseMotive = new Competence();
    senseMotive->name = (char*)"Sense Motive";
    senseMotive->description = (char*)"Sense motive skill";
    senseMotive->ability = WISDOM;

    Competence* soh = new Competence();
    soh->name = (char*)"Sleight of hand";
    soh->description = (char*)"Sleight of hand skill";
    soh->ability = DEXTERITY;

    Competence* spellcraft = new Competence();
    spellcraft->name = (char*)"Spellcraft";
    spellcraft->description = (char*)"Spellcraft skill";
    spellcraft->ability = INTELLIGENCE;

    Competence* stealth = new Competence();
    stealth->name = (char*)"Stealth";
    stealth->description = (char*)"Stealth skill";
    stealth->ability = DEXTERITY;

    Competence* survival = new Competence();
    survival->name = (char*)"Survival";
    survival->description = (char*)"Survival skill";
    survival->ability = WISDOM;

    Competence* swim = new Competence();
    swim->name = (char*)"Swim";
    swim->description = (char*)"Swim skill";
    swim->ability = STRENGTH;

    Competence* umd = new Competence();
    umd->name = (char*)"Use magic device";
    umd->description = (char*)"Use magic device skill";
    umd->ability = CHARISMA;

    return 0;
}
