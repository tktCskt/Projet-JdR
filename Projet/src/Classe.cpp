#include "classe.h"
#include "evolution.h"
Classe::Classe()
{
    //ctor
}

Classe::~Classe()
{
    //dtor
}

char* Classe::getName()
{
    return name;
}

void Classe::setName(char* n)
{
    name = n;
}

char* Classe::getDescription()
{
    return description;
}

void Classe::setDescription(char* desc)
{
    description = desc;
}

int Classe::getDv()
{
    return dv;
}

void Classe::setDv(int d)
{
    dv = d;
}

int Classe::getReq_niv()
{
    return req_niv;
}

void Classe::setReq_niv(int r)
{
    req_niv = r;
}

int Classe::getGain_comp()
{
    return gain_comp;
}

void Classe::setGain_comp(int g)
{
    gain_comp = g;
}
