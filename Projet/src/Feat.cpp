#include "Feat.h"
#include "FeatTalent.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Feat::nbFeats = 0;
Feat** Feat::listFeats = (Feat**)(malloc(sizeof(Feat*)*1000));

Feat::Feat()
{
    Feat::listFeats[Feat::nbFeats] = this;
    this->id = Feat::nbFeats;
    Feat::nbFeats++;
    this->name = (char*)"default name";
    this->listTalents = (Talent**)malloc(sizeof(Talent*)*300);
    this->nbTalents = 0;
}

void Feat::save(MYSQL* con, int i)
 {
     MYSQL_RES *result = NULL;
     MYSQL_ROW rowFeat = NULL;
     MYSQL_ROW rowTalent = NULL;
     char* nbTalentsString = (char*)malloc(10);
     itoa(this->nbTalents, nbTalentsString,10);
     char* request = (char*)malloc(sizeof(char) * 1024);
     char* request2 = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO feat(name, nb_talents) VALUES ( \"");
     strcat(request, this->name);
     strcat(request, "\", ");
     strcat(request, nbTalentsString);
     strcat(request, ");");
     // on considère que les talents ont déjà été créés dans la BDD
     mysql_query(con, request);
     // méthode pour récupérer l'id du feat à relier au talent
     mysql_query(con,"SELECT COUNT(*) FROM feat;");
     result = mysql_use_result(con);
     rowFeat =  mysql_fetch_row(result);
     int k= (int) rowFeat[0];
     for(int j = 1; j < Feat::nbTalents; j++)
     {
        // méthode pour récupérer l'id_talent du talent à relier
        strcpy(request2,"SELECT id_talent FROM talent WHERE name = \"");
        strcat(request2, Talent::listTalents[j]->getName());
        strcat(request2, "\";");
        mysql_query(con, request2);
        result = mysql_use_result(con);
        // CETTE LIGNE BUG BITCHE !!!!
        rowTalent =  mysql_fetch_row(result);
        int l= (int) rowTalent[0];
        FeatTalent::save(con, k, l);
     }
 }

Feat::~Feat()
{
    //dtor
}

char* Feat::getName()
{
    return name;
}

int Feat::getId()
{
    return this->id;
}

int Feat::addTalent(Talent* newTalent)
{
    this->listTalents[this->nbTalents] = newTalent;
    this->nbTalents++;

    return 0;
}

Feat* Feat::getFeatByName(const char* featName)
{
    int i = 0;

    for(i=0; i<Feat::nbFeats; i++)
    {
        if(strcmp(featName,Feat::listFeats[i]->name) == 0)
        {
            return Feat::listFeats[i];
        }
    }
    printf("Feat not found\n");
    return NULL;
}
