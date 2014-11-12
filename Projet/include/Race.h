#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <string>
class Race
{
     public:
        Race();
        virtual ~Race();
        char* getName();
        void setName(char* n);
        char* getDescription();
        void setDescription(char* desc);

        static int nbRaces;
        static Race* listRaces;
    protected:
    private:
    int iD_race;
    char* nom;
    char* description;
    int table_talent[300];// id_talent

};

#endif // RACE_H
