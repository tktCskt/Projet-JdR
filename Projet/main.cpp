#include <iostream>
#include "Cell.h"
#include "Area.h"
#include "PersonnageScenario.h"
#include "PNJ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define NB_ZONES 2
#define TAILLE_ZONE_X 10
#define TAILLE_ZONE_Y 10

int getNPCNearTo(Area*, int, PNJScenario**, PNJScenario**);
bool adjacence(Area*, int, int);
int menu (PersonnageScenario*, Area*, PNJScenario**);
int menu_deplacer (PersonnageScenario*, Area*);
int menu_interraction (PersonnageScenario*, PNJScenario**);

/**
  * The Epic Quest to kill the Rat King, now available on your computer!
  * @return 1 Once it's ended
  */
int main()
{
    // ********** Initialisation Campagne **********

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
        strcat(name[n],"Zone ");
        strcat(name[n],numero);
        areas[n].setName(name[n]);
        description[n] = (char*)(malloc(sizeof(char)*1024));
        description[n] = "Cette zone est une zone de test";
        areas[n].setDescription(description[n]);

        areas[n].setCells(cellules[n]);
    }

    /* We create a Rat and an old Lady which give the quest to kill the King Rat */
    printf("Initialisation PNJ...\n");
    PNJScenario** pnjs = (PNJScenario**)(malloc(sizeof(PNJScenario*)*2));
    for(n=0; n<2; n++)
    {
        pnjs[n] = new PNJScenario(&areas[0],n*TAILLE_ZONE_X+1);
        printf("id PNJ[%d] = %d, nbPNJ = %d\n", n, pnjs[n]->getId(), pnjs[n]->nbNPC);
    }
    pnjs[0]->setName("King Rat");
    pnjs[1]->setName("Vieille dame trop mysterieuse");

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

    // ********** Fin Campagne **********

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

    return 0;
}

/**
  * We get the list of PNJ near the idCell
  * @return r The number of PNJ
  */
int getNPCNearTo(Area* area, int idCell, PNJScenario** npcList, PNJScenario** npcListReturned)
{
    int n = npcList[0]->nbNPC;
    int i = 0;
    int r = 0;
    for(i=0; i<n; i++)
    {
        if(npcList[i]->getArea() == area)
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
        int choice;
        printf("--- Que faire ? ---\n1)Se deplacer\n2)Agir sur les PNJs\n3)Fin\n\n");
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
  * Sport is good for health
  */
int menu_deplacer (PersonnageScenario* PJ, Area* areas)
{
    int choice;
    printf("--- Deplacement : ---\n1)Avancer horizontalement\n2)Reculer Horizontalement\n3)Avancer verticalement\n4)Reculer vreticalement\n5)Changer de zone\n\n");
    scanf("%d",&choice); printf("\n");
     switch(choice)
        {
        case 1 :
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
        case 2 :
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
        case 3 :
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
        case 4 :
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
    PNJScenario** pnjs2 = (PNJScenario**)(malloc(sizeof(PNJScenario*)));

    int x,y;
    PJ->getArea()->getCoordonate(PJ->getCell()->getId(),&x,&y);
    printf("Cell id = %d, x = %d, y = %d\n\n",PJ->getCell()->getId(),x,y);

    int r = getNPCNearTo(PJ->getArea(),PJ->getCell()->getId(),npcList,pnjs2);
    printf("%d pnjs a cote\n\n", r);

    for(int n=0; n<r; n++)
    {
        pnjs2[n]->getArea()->getCoordonate(pnjs2[n]->getCell()->getId(),&x,&y);
        printf("%s sur la cellule id=%d,x=%d,y=%d\n", pnjs2[n]->getName(),pnjs2[n]->getCell()->getId(),x,y);
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
            break;
        case 2 :
            break;
        case 3 :
            break;
        default :
            break;
    }
    return 0;
}
