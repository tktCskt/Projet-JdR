#ifndef OBJET_H
#define OBJET_H

#include <iostream>
#include <string>
class Objet
{
    public:
        Objet();
        virtual ~Objet();
        char* getName();
        void setName(char* n);
        char* getDescription();
        void setDescription(char* desc);
        long int getPrice();
        void setPrice(long int p);
        bool getEquipable();
        void setEquipable(bool eq);
        float getPoids();
        void setPoids(float p);
    protected:
    private:
   int iD_objet;
   char* name;
   char* description;
   long int price; // on compte en pc
   bool equipable;
   int** table_talent;// id_talent
   float poids;

};

#endif // OBJET_H
