#ifndef COMPETENCE_H
#define COMPETENCE_H


class Competence
{
    public:
        Competence();
        virtual ~Competence();
        char* getDescription();
        void setDescription(char* desc);
    protected:
    private:
    int id_competence;
    char* description;
};

#endif // COMPETENCE_H
