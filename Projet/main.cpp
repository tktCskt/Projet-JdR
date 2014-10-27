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

int main()
{
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
    for(n=0; n<2; n++)
    {
        pnjs[n] = new PNJScenario(&areas[0],n*TAILLE_ZONE_X+1);
        printf("id PNJ[%d] = %d, nbPNJ = %d\n", n, pnjs[n]->getId(), pnjs[n]->nbNPC);
    }
    pnjs[0]->setName("Rat");
    pnjs[1]->setName("Vieille dame trop mysterieuse");
    /*Test Personnage*/
    printf("Init personnage\n");
    PersonnageScenario* ganjoTest = (PersonnageScenario*)(malloc(sizeof(PersonnageScenario)));
    ganjoTest->placeOnCell(&areas[0], 0);
    int fin = 0;
    while(!fin)
    {
        fin = menu(ganjoTest,areas,pnjs);
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

int menu (PersonnageScenario* PJ, Area* areas, PNJScenario** npcList)
{
        int choice;
        printf("1)Se deplacer\n2)Agir sur les PNJs\n3)Fin\n");
        scanf("%d",&choice);
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

int menu_deplacer (PersonnageScenario* PJ, Area* areas)
{
    int choice;
    printf("Deplacement :\n1)Avancer horizontalement\n2)Reculer Horizontalement\n3)Avancer verticalement\n4)Reculer vreticalement\n5)Changer de zone\n");
    scanf("%d",&choice);
     switch(choice)
        {
        case 1 :
            if(!(PJ->getCell()->getX() == TAILLE_ZONE_X-1))
            {
                 if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX()+1,PJ->getCell()->getY()) == 0)
                 {
                     printf("Vous avez avance horizontalement.\n");
                 }
                 else
                 {
                     printf("Erreur deplacement\n");
                 }
            }
            else
            {
                printf("Vous ne pouvez pas avancer, PJ->idCell=%d\n",PJ->getCell()->getId());
            }
            break;
        case 2 :
            if(!(PJ->getCell()->getX() == 0))
            {
                if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX()-1,PJ->getCell()->getY()) == 0)
                {
                    printf("Vous avez recule horizontalement.\n");
                }
                else
                {
                      printf("Erreur deplacement\n");
                }
            }
            else
            {
                printf("Vous ne pouvez pas reculer, PJ->idCell=%d\n",PJ->getCell()->getId());
            }
            break;
        case 3 :
            if(!(PJ->getCell()->getY() == TAILLE_ZONE_Y-1))
            {
                if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX(),PJ->getCell()->getY()+1) == 0)
                {
                    printf("Vous avez avance verticalement.\n");
                }
                else
                {
                    printf("Erreur deplacement\n");
                }
            }
            else
            {
                printf("Vous ne pouvez pas avancer, PJ->idCell=%d\n",PJ->getCell()->getId());
            }
            break;
        case 4 :
            if(!(PJ->getCell()->getY() == 0))
            {
                if(PJ->moveByCoordonate(PJ->getArea(),PJ->getCell()->getX(),PJ->getCell()->getY()-1) == 0)
                {
                    printf("Vous avez recule verticalement.\n");
                }
                else
                {
                    printf("Erreur deplacement\n");
                }
            }
            else
            {
                printf("Vous ne pouvez pas reculer, PJ->idCell=%d\n",PJ->getCell()->getId());
            }
            break;
        case 5 :
            PJ->setArea(&(areas[(PJ->getArea()->getId()+1)%NB_ZONES]));
            PJ->setCell(PJ->getArea()->getCells());
            printf("Vous avez change de zone\n");
            break;
        }
    return 0;
}

int menu_interraction(PersonnageScenario* PJ, PNJScenario** npcList)
{
    PNJScenario** pnjs2 = (PNJScenario**)(malloc(sizeof(PNJScenario*)));
    int x,y;
    PJ->getArea()->getCoordonate(PJ->getCell()->getId(),&x,&y);
    printf("Cell id = %d, x = %d, y = %d\n",PJ->getCell()->getId(),x,y);
    int r = getNPCNearTo(PJ->getArea(),PJ->getCell()->getId(),npcList,pnjs2);
    printf("%d pnjs a cote\n", r);
    int n = 0;
    for(n=0; n<r; n++)
    {
        pnjs2[n]->getArea()->getCoordonate(pnjs2[n]->getCell()->getId(),&x,&y);
        printf("%s sur la cellule id=%d,x=%d,y=%d\n", pnjs2[n]->getName(),pnjs2[n]->getCell()->getId(),x,y);
    }
    int nPNJ = 0;
    printf("Interragir avec quel PNJ ?");
    scanf("%d",&nPNJ);
    /*gerer erreur*/
    printf("Que faire sur %s?\n1)Attaquer\n2)Discuter\n3)Examiner\n",pnjs2[nPNJ]->getName());
    int choice = 0;
    scanf("%d",&choice);
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
