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

int main()
{
    /*TODO = Creer un scénario de deux zones avec des monstres et un PJ qu'on déplace + affichage*/
    /*TODO Constructeurs/Destructeurs*/
    /*TODO Renommer PNJ.h*/
    /*Remplacer **cell par *cell*/
    //Creer cellules

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

    //Creer Areas;
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
    /*Test PNJ*/
    printf("Init PNJ\n");
    PNJScenario** pnjs = (PNJScenario**)(malloc(sizeof(PNJScenario*)*2));
    PNJScenario** pnjs2 = (PNJScenario**)(malloc(sizeof(PNJScenario*)*2));
    for(n=0; n<2; n++)
    {
        pnjs[n] = new PNJScenario(&areas[0],n*TAILLE_ZONE_X+1);
        printf("id PNJ[%d] = %d, nbPNJ = %d\n", n, pnjs[n]->getId(), pnjs[n]->nbNPC);
    }
    pnjs[0]->setName("Rat");
    pnjs[1]->setName("Vieille dame trop mysterieuse");
    /*Test Personnage*/
    printf("Init personnage\n");
    PersonnageScenario* ganjoTest = (PersonnageScenario*)(malloc(sizeof(Personnage)));
    ganjoTest->placeOnCell(&areas[0], 0);
    bool fin = false;
    while(!fin)
    {
        printf("ganjotest->idCell = %d\n",ganjoTest->getCell()->getId());
        int r = getNPCNearTo(ganjoTest->getArea(),ganjoTest->getCell()->getId(),pnjs,pnjs2);
        printf("%d pnjs a cote (dans la meme zone ftm)\n", r);
        for(n=0; n<r; n++)
        {
            printf("%s\n", pnjs2[n]->getName());
        }
        int choice;
        printf("1)Avancer X\n2)Reculer X\n3)Avancer Y\n4)Reculer Y\n5)Changer zone\n6)Etat\n7)Fin\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            if(!(ganjoTest->getCell()->getX() == TAILLE_ZONE_X-1))
            {
                 ganjoTest->moveByCoordonate(ganjoTest->getArea(),ganjoTest->getCell()->getX()+1,ganjoTest->getCell()->getY());
                 printf("Vous avez avance horizontalement.\n");
            }
            else
            {
                printf("Vous ne pouvez pas avancer, ganjoTest->idCell=%d\n",ganjoTest->getCell()->getId());
            }
            break;
        case 2 :
            if(!(ganjoTest->getCell()->getX() == 0))
            {
                 ganjoTest->moveByCoordonate(ganjoTest->getArea(),ganjoTest->getCell()->getX()-1,ganjoTest->getCell()->getY());
                 printf("Vous avez recule horizontalement.\n");
            }
            else
            {
                printf("Vous ne pouvez pas reculer, ganjoTest->idCell=%d\n",ganjoTest->getCell()->getId());
            }
            break;
        case 3 :
            if(!(ganjoTest->getCell()->getY() == TAILLE_ZONE_Y-1))
            {
                 ganjoTest->moveByCoordonate(ganjoTest->getArea(),ganjoTest->getCell()->getX(),ganjoTest->getCell()->getY()+1);
                 printf("Vous avez avance verticalement.\n");
            }
            else
            {
                printf("Vous ne pouvez pas avancer, ganjoTest->idCell=%d\n",ganjoTest->getCell()->getId());
            }
            break;
        case 4 :
            if(!(ganjoTest->getCell()->getY() == 0))
            {
                 ganjoTest->moveByCoordonate(ganjoTest->getArea(),ganjoTest->getCell()->getX(),ganjoTest->getCell()->getY()-1);
                 printf("Vous avez recule verticalement.\n");
            }
            else
            {
                printf("Vous ne pouvez pas reculer, ganjoTest->idCell=%d\n",ganjoTest->getCell()->getId());
            }
            break;
        case 5 :
            ganjoTest->setArea(&(areas[(ganjoTest->getArea()->getId()+1)%NB_ZONES]));
            ganjoTest->setCell(ganjoTest->getArea()->getCells());
            printf("Vous avez change de zone\n");
            break;
        case 6 :
            printf("Id de la zone : %d\nNom de la zone : %s\nDescription de la zone :%s\n",ganjoTest->getArea()->getId(),ganjoTest->getArea()->getName(),ganjoTest->getArea()->getDescription());
            break;
        default :
            fin = true;
            break;
        }

    }
    //Liberer PNJ

    //Liberer Personnage
    free(ganjoTest);
    printf("ganjoTest freed\n");
    //Liberer Areas
    for(n=0; n<NB_ZONES; n++)
    {
        free(areas);
    }
    printf("areas freed\n");
    //Liberer cellulles
    for(n=0; n<NB_ZONES; n++)
    {
        free(cellules[n]);
    }
    free(cellules);
    printf("cells freed\n");
    return 0;
}

int getNPCNearTo(Area* area, int idCell, PNJScenario** npcList, PNJScenario** npcListReturned)
{
    int n = npcList[0]->nbNPC;
    int i = 0;
    int r = 0;
    for(i=0; i<n; i++)
    {
        /*FINIR CA*/
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
