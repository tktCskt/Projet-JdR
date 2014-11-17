#ifndef GUARD_H
#define GUARD_H
#include "PNJ.h"

class Guard : public PNJScenario
{
    public:
        Guard();
        Guard(Area* newArea, int idCell);
        virtual ~Guard();
    protected:
    private:
};

inline void guardDiscussion()
{
    printf("Bonjour jeune aventurier ! Moi aussi je partais a l aventure autrefois et puis j ai pris une fleche dans le genou.\n\n");
}
#endif // GUARD_H
