#ifndef COMPETENCE_H
#define COMPETENCE_H

#define STRENGTH 1
#define DEXTERITY 2
#define CONSTITUTION 3
#define WISDOM 4
#define INTELLIGENCE 5
#define CHARISMA 6

class Competence
{
    public:
        Competence();
        virtual ~Competence();

        int id;
        int ability;
        static int nbSkills;
        static Competence** listSkills;

        char* name;
        char* description;

    protected:
    private:
};

#endif // COMPETENCE_H
