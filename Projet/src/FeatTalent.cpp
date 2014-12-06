#include "FeatTalent.h"

FeatTalent::FeatTalent()
{
    //ctor
}

void FeatTalent::save(MYSQL* con, int id_feat, int id_talent)
 {
     char* id_featString = (char*)malloc(10);
     itoa(id_feat, id_featString,10);
     char* id_talentString = (char*)malloc(10);
     itoa(id_talent, id_talentString,10);

     char* request = (char*)malloc(sizeof(char) * 1024);
     strcpy(request,"INSERT INTO feat_talent(id_feat, id_talent) VALUES (");
     strcat(request, id_featString );
     strcat(request, ", ");
     strcat(request, id_talentString );
     strcat(request, ");");
     // on considère que les talents ont déjà été créés dans la BDD
     mysql_query(con, request);
 }


FeatTalent::~FeatTalent()
{
    //dtor
}
