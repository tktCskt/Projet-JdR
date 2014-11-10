#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <iostream>
#include <string>
class Utilisateur
{
    public:
        Utilisateur();
        virtual ~Utilisateur();
    protected:
    private:
    int iD_utilisateur;
    char* name;
};

#endif // UTILISATEUR_H
