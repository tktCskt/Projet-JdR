#include "race.h"
#include <stdlib.h>
#include <string.h>

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

/*void Race::save(MYSQL* con)
 {
     char* nbFeatsString = (char*)malloc(10);
     itoa(this->nbFeats, nbFeatsString,10);

     char* request = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO competence(name, description, nb_feats) VALUES ( \"");
     strcat(request, this->name);
     strcat(request, "\",\"");
     strcat(request, this->description);
     strcat(request, "\", (");
     strcat(request, nbFeatsString);
     strcat(request, ");");
     // on considère que les talents ont déjà été créés dans la BDD
     mysql_query(con, request);
       mysql_query(con, "SELECT COUNT(*) FROM table");
           result = mysql_use_result(con);
           id=&result
     for(i = 0; i < race::nbFeats; i++)
     {
          RaceTalent::listFeats[i]->save(con,id);
     }
 }
*/
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
