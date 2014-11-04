#ifndef CELL_H
#define CELL_H

//types de terrain
#define NORMAL 1
#define DIFFICILE 2
#define BLOQUE 3

/**
  * A cell component of an Area
  * if bool b is #true, the cell is occupied; else it is not
  * If type is 1, the cell is normal; if it is 2, the cell is difficult to access; if it is 3, the cell can't be accessed
  */
class Cell
{
    public:
        Cell();
        virtual ~Cell();

        int getX();
        int getY();
        int getId();
        int getType();
        bool getB();

        void setX(int x);
        void setY(int y);
        void setId(int id);
        void setType(int type);
        void setB(bool b);

    private:
        int x;
        int y;
        int id;
        int type;   // What kind of cell it is (see #define above)
        bool b;     // Whether the Cell is busy or not
};

#endif // CELL_H
