#include <iostream>
#include "Cell.h"
#include "Area.h"
#include "PersonnageScenario.h"
#include "PNJ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Guard.h>
#include "Race.h"
#include "Classe.h"
#include "Personnage.h"
#include "init.h"
#include "Competence.h"
#include "test_init.h"
#include <winsock.h>
#include <MYSQL/mysql.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

/* Set these below to true to test related functions
   Set them to false if you don't care
   */
#define TEST_INIT true
#define TEST_CAMPAGNE false
#define TEST_BDD false
#define CREATE_CHARACTER false

#define NB_ZONES 2
#define TAILLE_ZONE_X 10
#define TAILLE_ZONE_Y 10
#define NB_NPC_MAX 10

int init_test_skills_feats_races();
int init_test_campagne();

int menu (PersonnageScenario*, Area*, PNJScenario**);
int menu_deplacer (PersonnageScenario*, Area*);
int menu_interraction (PersonnageScenario*, PNJScenario**);

void displayCarte(Area* area);

int getNPCNearTo(Area*, int, PNJScenario**, PNJScenario**);
bool adjacence(Area*, int, int);

void discussion(PNJScenario* npc);
void discussionQuest();

void combat(PNJScenario** npcList, PNJScenario* npc);
bool attaquer(PNJScenario* npc);
void mort(PNJScenario* npc);

void add_competence();
void add_talent();
void add_feat();
void add_race();

Personnage* newCharacter();

/**
  * The Epic Quest to kill the Rat King, now available on your computer!
  * @return 0 if it went well
  */
int main()
{

    // ********** Initialisation Skills / Feats / Races **********
    if(TEST_INIT)
    {
        if (init_test_skills_feats_races()!=0)
            return 1;
    }
    //Test BDD
    if(TEST_BDD)
    {
        // pour faire marcher, n'oubliez pas de clique droit sur r駱ertoire projet, build option et cr馥r un lien vers le librairie libmysqlclient.a
     add_competence();
     add_talent();
     // ça coince au niveau de feat talent
     //add_feat();
     //add_race();

    }
    // ********** Initialisation Campagne **********
    if (TEST_CAMPAGNE)
    {
        if (init_test_campagne()!=0)
            return 1;
    }
    if(CREATE_CHARACTER)
    {
        newCharacter();
    }

    return 0;
}

void add_competence()
{

    MYSQL *con = mysql_init(NULL);
      if (con == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          exit(1);
      }
      // ・tester avec une vraie adresse ip, pas en local
        if (mysql_real_connect(con, "localhost", "root", "morganeetclaire45",
              "bddjeuderoles", 0, NULL, 0) == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          mysql_close(con);
      }
        mysql_query(con,"DROP TABLE competence;");
        /* mysql_query(con,"DROP TABLE objet;");
        mysql_query(con,"DROP TABLE personnage;");
        mysql_query(con,"DROP TABLE classe;");
        mysql_query(con,"DROP TABLE classe_jet_vig;");
        mysql_query(con,"DROP TABLE classe_jet_ref;");
        mysql_query(con,"DROP TABLE classe_jet_vol;");
        mysql_query(con,"DROP TABLE classe_competence;");
        mysql_query(con,"DROP TABLE classe_competence_classe;");
        mysql_query(con,"DROP TABLE classe_race_req;");
        mysql_query(con,"DROP TABLE classe_alignement;");
        mysql_query(con,"DROP TABLE classe_bba;");
        mysql_query(con,"DROP TABLE inventaire;");
        mysql_query(con,"DROP TABLE loot;");
        mysql_query(con,"DROP TABLE monstre;");
        mysql_query(con,"DROP TABLE new_table;");*/
        mysql_query(con,"CREATE TABLE competence(id_comp INT NOT NULL AUTO_INCREMENT,PRIMARY KEY (id_comp), ability INTEGER NOT NULL,name VARCHAR(45) NOT NULL,description VARCHAR(300) NOT NULL);");
       // mysql_query(con, "INSERT INTO competence(ability, name, description) VALUES(1,\"lol\",\"lolz\");");
        int i = 0;
    for(i = 0; i < Competence::nbSkills; i++)
    {
        Competence::listSkills[i]->save(con);
    }
}

void add_talent()
{

    MYSQL *con = mysql_init(NULL);
      if (con == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          exit(1);
      }
      // ・tester avec une vraie adresse ip, pas en local
        if (mysql_real_connect(con, "localhost", "root", "morganeetclaire45",
              "bddjeuderoles", 0, NULL, 0) == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          mysql_close(con);
      }
        mysql_query(con,"DROP TABLE talent;");

        mysql_query(con,"CREATE TABLE Talent(id_talent INT NOT NULL AUTO_INCREMENT,PRIMARY KEY (id_talent), name VARCHAR(45) NOT NULL, description VARCHAR(300) NOT NULL, type INTEGER, value INTEGER);");
        //mysql_query(con, "INSERT INTO talent(name, description, type, value) VALUES(\"lol\",\"lolz\", 0, 0);");
        int i = 0;
    for(i = 0; i < Talent::nbTalents; i++)
    {
        Talent::listTalents[i]->save(con);
    }
}

void add_feat()
{

    MYSQL *con = mysql_init(NULL);
      if (con == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          exit(1);
      }
      // ・tester avec une vraie adresse ip, pas en local
        if (mysql_real_connect(con, "localhost", "root", "morganeetclaire45",
              "bddjeuderoles", 0, NULL, 0) == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          mysql_close(con);
      }
        mysql_query(con,"DROP TABLE feat;");
        mysql_query(con,"DROP TABLE feat_talent;");

        mysql_query(con,"CREATE TABLE feat(id_feat INT NOT NULL AUTO_INCREMENT,PRIMARY KEY (id_feat), name VARCHAR(45) NOT NULL, nb_talents INTEGER);");
        mysql_query(con,"CREATE TABLE feat_talent(id_feat INTEGER NOT NULL, id_talent INTEGER NOT NULL);");
        //mysql_query(con, "INSERT INTO feat(name, nb_talents) VALUES(\"lol\",1);");
        int i = 0;
    for(i = 0; i < Feat::nbFeats; i++)
    {
        Feat::listFeats[i]->save(con, i);
    }
}

void add_race()
{
    MYSQL *con = mysql_init(NULL);
      if (con == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          exit(1);
      }
      // ・tester avec une vraie adresse ip, pas en local
        if (mysql_real_connect(con, "localhost", "root", "morganeetclaire45",
              "bddjeuderoles", 0, NULL, 0) == NULL)
      {
          fprintf(stderr, "%s\n", mysql_error(con));
          mysql_close(con);
      }
        mysql_query(con,"DROP TABLE race;");
        mysql_query(con,"DROP TABLE race_feat;");


        mysql_query(con,"CREATE TABLE race(id_race INT NOT NULL AUTO_INCREMENT,PRIMARY KEY (id_race),name VARCHAR(45) NOT NULL,description VARCHAR(300) NOT NULL,);");
        mysql_query(con,"CREATE TABLE race_feat(id_race INTEGER NOT NULL ,id_feat INTEGER NOT NULL);");
        mysql_query(con, "INSERT INTO race(name, description) VALUES(\"lol\",\"lolz\");");

        int i = 0;
    for(i = 0; i < Race::nbRaces; i++)
    {
        Race::listRaces[i]->save(con, i);
    }
}

/**
 * Initialize the creation of skills / feats / races classes for test use
 * @return 0 if it went well
 */
int init_test_skills_feats_races()
{
        int r = 0;
        r += initSkills();
        int i = 0;

        //r += test_init_skills();
        r += initTalents();
        r += test_init_talents();
        r += initFeats();
        //r += test_init_feats();
        r += initRaces();
        //r += test_init_races();
        r += initClasses();
        //r += test_init_classes();
        printf("r = %d\n", r);
        return 0;
}

/**
 * Launch the "Rat King" campaign for test use
 * @return 0 if it went well
 */
int init_test_campagne()
{
    /* We create NB_ZONES table of Cells according to the size of the Areas TAILLE_ZONE_X*TAILLE_ZONE_Y
       They are all NORMAL and not Busy */
    int i,j,n = 0;
    Cell** cellules;
    cellules = (Cell**)(malloc(sizeof(Cell*)*NB_ZONES));
    for(n=0; n<NB_ZONES; n++)
    {
        cellules[n] = (Cell*)(malloc(sizeof(Cell)*TAILLE_ZONE_X*TAILLE_ZONE_Y));
        for(i=0; i<TAILLE_ZONE_X; i++)
        {
            for(j=0; j<TAILLE_ZONE_Y; j++)
            {
                cellules[n][j*TAILLE_ZONE_X+i].setX(i);
                cellules[n][j*TAILLE_ZONE_X+i].setY(j);
                cellules[n][j*TAILLE_ZONE_X+i].setId(j*TAILLE_ZONE_X+i);
                cellules[n][j*TAILLE_ZONE_X+i].setType(NORMAL);
                cellules[n][j*TAILLE_ZONE_X+i].setB(false);
            }
        }
    }

    /* We create NB_ZONES Area within it we put the Cells */
    Area* areas;
    areas = (Area*)(malloc(sizeof(Area)*NB_ZONES));
    char** name = (char**)(malloc(sizeof(char*)*NB_ZONES));
    char** description = (char**)(malloc(sizeof(char*)*NB_ZONES));
    for(n=0; n<NB_ZONES; n++)
    {
        areas[n].setId(n);
        areas[n].setXMax(TAILLE_ZONE_X);
        areas[n].setYMax(TAILLE_ZONE_Y);

        name[n] = (char*)(malloc(sizeof(char)*256));
        char* numero = (char*)(malloc(sizeof(char)*16));
        itoa(n,numero,10);
        strcpy(name[n],"Zone ");
        strcat(name[n],numero);
        areas[n].setName(name[n]);
        description[n] = (char*)(malloc(sizeof(char)*1024));
        strcpy(description[n], "Cette zone est une zone de test");
        areas[n].setDescription(description[n]);

        areas[n].setCells(cellules[n]);
    }

    /* We create a Rat and a guard which give the quest to kill the King Rat */
    printf("Initialisation PNJ...\n");
    PNJScenario** pnjs = (PNJScenario**)(malloc(sizeof(PNJScenario*)*NB_NPC_MAX));
    pnjs[0] = new PNJScenario(&areas[0],1);
    pnjs[1] = new Guard(&areas[0],11);
    pnjs[2] = new Guard(&areas[0],21);
    pnjs[0]->setName((char*)"King Rat");
    pnjs[1]->setName((char*)"Garde un peu nul");
    pnjs[2]->setName((char*)"Garde trop baleze");
    pnjs[1]->discuss = discussionQuest;

    /* We create a Personnage which will have to kill the King Rat to free the world from rat domination */
    printf("Initialisation personnage...\n\n");
    PersonnageScenario* ganjoTest = (PersonnageScenario*)(malloc(sizeof(PersonnageScenario)));
    ganjoTest->placeOnCell(&areas[0], 0);

    printf("Termine\n\n");

    /* The game may now begin! */
    int fin = 0;
    while(!fin)
    {
        fin = menu(ganjoTest,areas,pnjs);
    }

    // We free the PNJ

    // We free the Personnage
    free(ganjoTest);
    printf("ganjoTest freed\n");

    // We free the Areas
    for(n=0; n<NB_ZONES; n++)
    {
        free(areas);
    }
    printf("areas freed\n");

    // We free the Cells
    for(n=0; n<NB_ZONES; n++)
    {
        free(cellules[n]);
    }
    free(cellules);
    printf("cells freed\n");
    free(Race::listRaces);
    free(Classe::listClasses);
    return 0;
}

/**
  * We get the list of PNJ near the idCell
  * @return r The number of PNJ
  */
int getNPCNearTo(Area* area, int idCell, PNJScenario** npcList, PNJScenario** npcListReturned)
{
    int n = PNJScenario::nbNPC;
    int i = 0;
    int r = 0;
    for(i=0; i<n; i++)
    {
        if (npcList[i]!=NULL && npcList[i]->getArea() == area)
        {
            if(adjacence(area, idCell, npcList[i]->getCell()->getId()))
            {
                npcListReturned[r++] = npcList[i];
            }
        }
    }
    return r;
}

/**
  * We check if idCell1 and idCell2 of area are adjacent or not
  * @return Whether the two cells where adjacent or not
  */
bool adjacence(Area* area, int idCell1, int idCell2)
{
    int x1,x2,y1,y2;
    area->getCoordonate(idCell1,&x1,&y1);
    area->getCoordonate(idCell2,&x2,&y2);
    if(x1 > x2+1 || x2 > x1+1 || y1 > y2+1 || y2 > y1+1)
    {
        return false;
    }
    return true;
}

/**
  * The main ergonomic way to play the game
  */
int menu (PersonnageScenario* PJ, Area* areas, PNJScenario** npcList)
{
    displayCarte(PJ->getArea());

    int choice;
    int x,y;
    PJ->getArea()->getCoordonate(PJ->getCell()->getId(),&x,&y);

    printf("--- Vous etes en %s (%d,%d) ---\n", PJ->getArea()->getName(), PJ->getCell()->getX(), PJ->getCell()->getY());
    printf("1)Se deplacer\n2)Agir sur les PNJs\n3)Fin\n\n");
    scanf("%d",&choice); printf("\n");

    switch(choice)
    {
    case 1 :
        menu_deplacer(PJ,areas);
        break;
    case 2 :
        menu_interraction(PJ,npcList);
        break;
    default :
        return 1;
        break;
    }
    return 0;
}

/**
  * Who needs a map?
  */
void displayCarte(Area* area)
{
    int xmax = area->getXMax();
    int ymax = area->getYMax();

    for (int j=ymax; j>=0; j--) {
        for (int i=0; i<xmax; i++) {
            Cell cell = area->getCell(i,j);
            if (cell.getB()==true)
                printf("@");
            else
                printf("-");
        }
        printf("\n");
    }
    printf("\n");
}

/**
  * Sport is good for health
  */
int menu_deplacer (PersonnageScenario* PJ, Area* areas)
{
    int choice;
    printf("--- Deplacement : ---\n");
    printf("1)Avancer horizontalement\n2)Reculer Horizontalement\n3)Avancer verticalement\n4)Reculer vreticalement\n5)Changer de zone\n\n");
    scanf("%d",&choice); printf("\n");
     switch(choice)
        {
        case 1 : // Avancer horizontalement aka ・droite
            if(!(PJ->getCell()->getX() == TAILLE_ZONE_X-1))
            {
                 if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX()+1,PJ->getCell()->getY()) == 0)
                 {
                     printf("Vous avez avance horizontalement.\n\n");
                 }
                 else
                 {
                     printf("Erreur deplacement\n\n");
                 }
            }
            else
            {
                printf("Vous ne pouvez pas avancer, PJ->idCell=%d\n\n",PJ->getCell()->getId());
            }
            break;
        case 2 : // Reculer horizontalement aka ・gauche
            if(!(PJ->getCell()->getX() == 0))
            {
                if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX()-1,PJ->getCell()->getY()) == 0)
                {
                    printf("Vous avez recule horizontalement.\n\n");
                }
                else
                {
                      printf("Erreur deplacement\n\n");
                }
            }
            else
            {
                printf("Vous ne pouvez pas reculer, PJ->idCell=%d\n\n",PJ->getCell()->getId());
            }
            break;
        case 3 : // Avancer verticalement aka en haut
            if(!(PJ->getCell()->getY() == TAILLE_ZONE_Y-1))
            {
                if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX(),PJ->getCell()->getY()+1) == 0)
                {
                    printf("Vous avez avance verticalement.\n\n");
                }
                else
                {
                    printf("Erreur deplacement\n\n");
                }
            }
            else
            {
                printf("Vous ne pouvez pas avancer, PJ->idCell=%d\n\n",PJ->getCell()->getId());
            }
            break;
        case 4 : // Reculer verticalement aka en bas
            if(!(PJ->getCell()->getY() == 0))
            {
                if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX(),PJ->getCell()->getY()-1) == 0)
                {
                    printf("Vous avez recule verticalement.\n\n");
                }
                else
                {
                    printf("Erreur deplacement\n\n");
                }
            }
            else
            {
                printf("Vous ne pouvez pas reculer, PJ->idCell=%d\n\n",PJ->getCell()->getId());
            }
            break;
        case 5 :
            PJ->setArea(&(areas[(PJ->getArea()->getId()+1)%NB_ZONES]));
            PJ->setCell(PJ->getArea()->getCells());
            printf("--- Vous avez change de zone ---\n\n");
            break;
        }
    return 0;
}

/**
  * The best way to be happy is to befriend people
  */
int menu_interraction(PersonnageScenario* PJ, PNJScenario** npcList)
{
    PNJScenario** pnjs2 = (PNJScenario**)(malloc(sizeof(PNJScenario*)*NB_NPC_MAX));
    int x,y;
    PJ->getArea()->getCoordonate(PJ->getCell()->getId(),&x,&y);
    printf("Cell id = %d, x = %d, y = %d\n\n",PJ->getCell()->getId(),x,y);
    //bug ici apres d駱lacement + 3 "agir"
    int r = getNPCNearTo(PJ->getArea(),PJ->getCell()->getId(),npcList,pnjs2);

    if (r==0) { // Aucun PNJ
        printf("Mais il n'y a aucun PNJ a cote...\n\n");
        return 0;
    } else {
        printf("%d pnjs a cote\n\n", r);
        for(int n=0; n<r; n++)
        {
            pnjs2[n]->getArea()->getCoordonate(pnjs2[n]->getCell()->getId(),&x,&y);
            printf("%d)%s sur la cellule id=%d,x=%d,y=%d\n", n, pnjs2[n]->getName(), pnjs2[n]->getCell()->getId(), x, y);
        }
        printf("\n");

        int nPNJ = 0;
        printf("--- Interragir avec quel PNJ ? ---\n\n");
        scanf("%d",&nPNJ); printf("\n");

        // TODO Gerer erreur
        printf("--- Que faire sur %s ? ---\n1)Attaquer\n2)Discuter\n3)Examiner\n\n",pnjs2[nPNJ]->getName());
        int choice = 0;
        scanf("%d",&choice); printf("\n");
        switch(choice)
        {
            case 1 :
                combat(npcList, pnjs2[nPNJ]);
                break;
            case 2 :
                discussion(pnjs2[nPNJ]);
                break;
            case 3 :
                break;
            default :
                break;
        }
        return 0;
    }
}

void discussion(PNJScenario* npc)
{
    npc->discuss();
}

void discussionQuest()
{
    int choice;
    printf("Slt tapa un peo stplz ?\n");
    printf("1)Donner 1 peo\n");
    printf("2)Refuser\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1 :
        printf("ty, tu le ra stp.. jte donere 1 tresor apre\n\n");
        break;
    default :
        printf("kastoi tupu\n\n");
    }
}

/**
  * The whole process of getting stronger or die trying
  */
void combat(PNJScenario** npcList, PNJScenario* npc) {
    bool mechant = true;
    int choice;

    // get which npc will fight alongside npc

    while (mechant) {
        printf("--- Combat ---\n1)Taper avec sa grosse epee\n2)Implorer pardon\n\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (attaquer(npc)) { // le npc est mort
                    /* on d騁ruit le npc */
                    int n = PNJScenario::nbNPC;
                    for (int i=0; i<n; i++) {
                        if (npcList[i]!=NULL && npcList[i]==npc) {
                            npcList[i]=NULL;
                            free(npc);
                        }
                    }

                    /* on regarde si tous les monstres sont morts */
                    mechant = false;
                }
                break;
            default:
                printf("%s vous regarde avec d馘ain alors que vous fuyez\n\n", npc->getName());
                mechant=false;
        }
    }
}

/**
  * Get stronger or die trying
  * @return true if the enemy is dead
  */
bool attaquer(PNJScenario* npc) {
    printf("COUP CRITIQUE ! C'est super efficace.\n");
    //if (npc->getHPLeft()==0)
        mort(npc);
        return true;
    //else
    //  return false;
}

/**
  * You got stronger
  */
void mort(PNJScenario* npc) {
    npc->getCell()->setB(false);

    printf("Vous avez detruit le vil %s!\n\n", npc->getName());
    printf("Vous obtenez %d xp et aucun objet. (C'est un rat, vous vous attendiez a quoi ?)\n\n", npc->getXp());
}

Personnage* newCharacter()
{
    printf("newCharacter..\n");

    char* firstName = (char*)(malloc(sizeof(char)*50));
    char* lastName = (char*)(malloc(sizeof(char)*50));
    char* race = (char*)(malloc(sizeof(char)*50));
    char* classe = (char*)(malloc(sizeof(char)*50));
    char* bonus = NULL;
    int r = -1;
    int abilities[6];
    printf("ici\n");
    Personnage* character = new Personnage();

    printf("FirstName ?\n");
    scanf("%s", firstName);
    character->setFirstName(firstName);

    printf("LastName ?\n");
    scanf("%s", lastName);
    character->setLastName(lastName);

    printf("Le personnage s'appelle %s %s\n", character->getFirstName(), character->getLastName());

    while (r != 0)
    {
        printf("Classe ?\n");
        scanf("%s", classe);
        r = character->setClasse(classe);
    }


    printf("Strength ?\n");
    scanf("%d", &abilities[0]);
    printf("Dexterity ?\n");
    scanf("%d", &abilities[1]);
    printf("Constitution ?\n");
    scanf("%d", &abilities[2]);
    printf("Intelligence ?\n");
    scanf("%d", &abilities[3]);
    printf("Wisdom ?\n");
    scanf("%d", &abilities[4]);
    printf("Charisma ?\n");
    scanf("%d", &abilities[5]);
    character->setAbilities(NULL,abilities);

    printf("Skills are not implemented yet\n");
    printf("Race ?\n");
    scanf("%s", race);
    if(strcmp(race,"demielfe") || strcmp(race,"demiorc") || strcmp(race,"humain"))
    {
        bonus = (char*)(malloc(sizeof(char)*50));
        printf("Bonus ?\n");
        scanf("%s", bonus);
    }
    character->setRace(race,bonus);
    printf("Feats are not implemented yet\n");

    free(race);
    free(classe);

    printf("Fin !");
    return character;
}
