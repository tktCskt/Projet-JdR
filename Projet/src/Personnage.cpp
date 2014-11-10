#include "personnage.h"
#include <string>
Personnage::Personnage()
{
    //ctor
}

Personnage::~Personnage()
{
    //dtor
}
// get & set caracs
int Personnage::getForce()
{
    return force;
}

int Personnage::getDexterite()
{
    return dexterite;
}

int Personnage::getConstitution()
{
    return constitution;
}

int Personnage::getIntelligence()
{
    return intelligence;
}

int Personnage::getSagesse()
{
    return sagesse;
}

int Personnage::getCharisme()
{
    return charisme;
}

void Personnage::setForce(int f)
{
    force = f;
}

void Personnage::setDexterite(int d)
{
    dexterite = d;
}

void Personnage::setConstitution(int c)
{
    constitution = c;
}

void Personnage::setIntelligence(int i)
{
    intelligence= i;
}

void Personnage::setSagesse(int s)
{
    sagesse = s;
}

void Personnage::setCharisme(int c)
{
    charisme = c;
}

//fin get & set caracs


char* Personnage::getLastName()
{
    return lastName;
}
char* Personnage::getFirstName()
{
    return firstName;
}

char* Personnage::getNickName()
{
    return nickName;
}

char* Personnage::getAlignement()
{
    return alignement;
}

char* Personnage::getDescription()
{
    return description;
}

int Personnage::getAge()
{
    return age;
}

char* Personnage::getM_taille()
{
    return m_taille;
}

int Personnage::getId_race()
{
    return id_race;
}

int Personnage::getPv_max()
{
    return pv_max;
}

int Personnage::getSauv_ref()
{
    return sauv_ref;
}


int Personnage::getSauv_vig()
{
    return sauv_vig;
}


int Personnage::getSauv_vol()
{
    return sauv_vol;
}

int Personnage::getCa_temp()
{
    return ca_temp;
}

int Personnage::getBba()
{
    return bba;
}

int Personnage::getInit()
{
    return init;
}


//setter possible

void Personnage::setLastName(char* ln)
{
    lastName = ln;
}
void Personnage::setFirstName(char* fn)
{
    firstName = fn;
}

void Personnage::setNickName(char* nm)
{
    nickName = nm;
}

void Personnage::setAlignement(char* al)
{
    alignement = al;
}

void Personnage::setDescription(char* desc)
{
    description = desc;
}

void Personnage::setAge(int a)
{
    age = a;
}

void Personnage::setM_taille(char* t)
{
    m_taille = t;
}

void Personnage::setId_race(int r)
{
    id_race = r;
}

