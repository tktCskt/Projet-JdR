#ifndef CELL_H
#define CELL_H

//types de terrain
#define NORMAL 1
#define DIFFICILE 2
#define BLOQUE 3
class Cell
{
    public:
        Cell();
        virtual ~Cell();
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        void setId(int id);
        int getId();
        void setType(int type);
        int getType();
        void setB(bool b);
        bool getB();
    protected:
    private:
        int x;
        int y;
        int id;
        int type;
        // case occupée ou non
        bool b;
};

#endif // CELL_H
