#ifndef PERSONNAGE_H
#define PERSONNAGE_H


class Personnage
{
    public:
        Personnage();
        virtual ~Personnage();
    protected:
    private:
    int iD_perso;
    char* lastName;
    char* firstName;
    char* nickName;
};

#endif // PERSONNAGE_H
