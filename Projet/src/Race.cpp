#include "race.h"
#include "raceFeat.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
int Race::nbRaces = 0;
Race** Race::listRaces = (Race**)(malloc(sizeof(Race*)*50));

Race::Race()
{
    this->id = Race::nbRaces;
    Race::listRaces[Race::nbRaces] = this;
    Race::nbRaces++;
    this->listFeats = (Feat**)malloc(sizeof(Feat*)*30);
    this->nbFeats = 0;
    this->name = (char*)"default name";
    this->description = (char*)"default description";
}

Race::~Race()
{
    free(this->listFeats);
}

void Race::save(MYSQL* con, int i)
 {
     MYSQL_RES *result = NULL;
     MYSQL_ROW rowFeat = NULL;
     char* nbFeatsString = (char*)malloc(10);
     itoa(this->nbFeats, nbFeatsString,10);

     char* request = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO race(name, description, nb_feats) VALUES ( \"");
     strcat(request, this->name);
     strcat(request, "\",\"");
     strcat(request, this->description);
     strcat(request, "\", ");
     strcat(request, nbFeatsString);
     strcat(request, ");");
     // on considère que les talents ont déjà été créés dans la BDD
     mysql_query(con, request);
     for(int j = 1; j < Race::nbFeats; j++)
     {
        // méthode pour récupérer l'id_talent du talent à relier
        strcpy(request,"SELECT id_feat FROM feat WHERE name = \"");
        strcat(request, Feat::listFeats[j]->getName());
        strcat(request, "\";");
        mysql_query(con, request);
        result = mysql_use_result(con);
        rowFeat =  mysql_fetch_row(result);
        int l= (int) rowFeat[0];
        RaceFeat::save(con, i, l);
     }
 }

int Race::addFeat(Feat* newFeat)
{
    this->listFeats[nbFeats] = newFeat;
    this->nbFeats++;

    return 0;
}

int Race::getId()
{
    return this->id;
}

void Race::setSize(enum size_ newSize)
{
    this->raceSize = newSize;
    /*TODO ADD FEAT*/
}

enum size_ Race::getSize()
{
    return this->raceSize;
};
