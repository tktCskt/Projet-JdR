#include "objet.h"

Objet::Objet()
{
    //ctor
}

Objet::~Objet()
{
    //dtor
}
char* Objet::getName()
{
    return name;
}

void Objet::setName(char* n)
{
    name = n;
}

char* Objet::getDescription()
{
    return description;
}

void Objet::setDescription(char* desc)
{
    description = desc;
}

long int Objet::getPrice()
{
    return price;
}

void Objet::setPrice(long int p)
{
    price = p;
}

bool Objet::getEquipable()
{
    return equipable;
}

void Objet::setEquipable(bool eq)
{
    equipable = eq;
}

float Objet::getPoids()
{
    return poids;
}

void Objet::setPoids(float p)
{
    poids = p;
}

