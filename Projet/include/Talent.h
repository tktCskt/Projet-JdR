#ifndef TALENT_H
#define TALENT_H

#define STRENGTH_MODIF 1
#define DEXTERITY_MODIF 2
#define CONSTITUTION_MODIF 3
#define INTELLIGENCE_MODIF 4
#define WISDOM_MODIF 5
#define CHARISMA_MODIF 6

class Talent
{
    public:
        Talent();
        virtual ~Talent();

        char* name;
        char* description;
        int type;
        int value;
        int id;

        static int nbFeats;
        static Talent** listFeats;

        static Talent* getFeatByName(char* featName);

    protected:
    private:
};

#endif // TALENT_H
