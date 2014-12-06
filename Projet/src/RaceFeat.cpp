#include "RaceFeat.h"

RaceFeat::RaceFeat()
{
    //ctor
}

void RaceFeat::save(MYSQL* con, int id_race, int id_feat)
 {
     char* id_raceString = (char*)malloc(10);
     itoa(id_race, id_raceString,10);
     char* id_featString = (char*)malloc(10);
     itoa(id_feat, id_featString,10);

     char* request = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO feat_talent(id_feat, id_talent) VALUES (");
     strcat(request, id_raceString );
     strcat(request, ", ");
     strcat(request, id_featString );
     strcat(request, ");");
     // on considère que les talents ont déjà été créés dans la BDD
     mysql_query(con, request);
 }

RaceFeat::~RaceFeat()
{
    //dtor
}
