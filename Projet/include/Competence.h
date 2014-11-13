#ifndef COMPETENCE_H
#define COMPETENCE_H


class Competence
{
    public:
        Competence();
        virtual ~Competence();

        int id;
        static int nbSkills;
        static Competence** listSkills;

        int setName(char* newName);
        int setDescription(char* newDescription);
        char* getName();
        char* getDescription();

    protected:
        char* name;
        char* description;
    private:
};

#endif // COMPETENCE_H
