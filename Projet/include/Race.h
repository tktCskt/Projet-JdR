#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <string>
class Race
{
     public:
        Race();
        virtual ~Race();
        char* getNom();
        void setNom(char* n);
        char* getDescription();
        void setDescription(char* desc);
    protected:
    private:
    int iD_race;
    char* nom;
    char* description;
    int table_talent[300];// id_talent

};

#endif // RACE_H
