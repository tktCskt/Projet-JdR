#ifndef TALENT_H
#define TALENT_H
#include <winsock.h>
#include <MYSQL/mysql.h>
/*Types */
#define STRENGTH_MODIF 1
#define DEXTERITY_MODIF 2
#define CONSTITUTION_MODIF 3
#define INTELLIGENCE_MODIF 4
#define WISDOM_MODIF 5
#define CHARISMA_MODIF 6

#define ACROBATICS_MODIF 7
#define APPRAISE_MODIF 8
#define BLUFF_MODIF 9
#define CLIMB_MODIF 10
#define CRAFT_MODIF 11
#define DIPLOMACY_MODIF 12
#define DISABLEDEVICE_MODIF 13
#define DISGUISE_MODIF 14
#define ESCAPE_MODIF 15
#define FLY_MODIF 16
#define HANDLEANIMAL_MODIF 17
#define HEAL_MODIF 18
#define INTIMIDATE_MODIF 19
#define KNOWLEDGE_MODIF 20
#define LINGUISTICS_MODIF 21
#define PERCEPTION_MODIF 22
#define PERFORM_MODIF 23
#define PROFESSION_MODIF 24
#define RIDE_MODIF 25
#define SENSEMOTIVE_MODIF 26
#define SLEIGHTOFHAND_MODIF 27
#define SPELLCRAFT_MODIF 28
#define STEALTH_MODIF 29
#define SURVIVAL_MODIF 30
#define SWIM_MODIF 31
#define UMD_MODIF 32

class Talent
{
    public:
        Talent();
        virtual ~Talent();
        void save(MYSQL* con);
        char* getName();

        char* name;
        char* description;
        int type;
        int value;
        int id;

        static int nbTalents;
        static Talent** listTalents;

        static Talent* getTalentByName(const char* talentName);

    protected:
    private:
};

#endif // TALENT_H
