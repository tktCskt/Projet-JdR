#ifndef PERSONNAGE_H
#define PERSONNAGE_H

// TODO Give access to lastName, firstName and nickName with a getter
class Personnage
{
    public:
        Personnage();
        virtual ~Personnage();

    private:
        int iD_perso;
        char* lastName;
        char* firstName;
        char* nickName;
};

#endif // PERSONNAGE_H
