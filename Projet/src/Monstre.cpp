#include "monstre.h"

Monstre::Monstre()
{
    //ctor
}

Monstre::~Monstre()
{
    //dtor
}

char* Monstre::getName()
{
    return name;
}
void Monstre::setName(char* n)
{
    name = n;
}

float Monstre::getLevel()
{
    return level;
}

void Monstre::setLevel(float l)
{
    level = l;
}

int Monstre::getXp()
{
    return xp;
}

void Monstre::setXp(int x)
{
    xp = x;
}
