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

        char* name;
        char* description;

    protected:
    private:
};

#endif // COMPETENCE_H
