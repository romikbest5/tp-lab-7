#ifndef VIEWFIELD_H
#define VIEWFIELD_H

class Ocean;
class Cell;
class Object;

class VeiwCellContainer
{
    public:
    VeiwCellContainer();
    virtual ~VeiwCellContainer();

    int relative_x = 0;
    int relative_y = 0;
    int distance = 0;
    Cell* origin_cell = 0;
    protected:

    private:

};

class ViewField
{
    public:
        ViewField (Cell* self_, int radius_, Ocean* ocean_, Object* mind_);
        virtual ~ViewField();
        void SetField ();
        void SetField (Cell* self);
        Cell* Observe();
        bool ReactToObject(VeiwCellContainer* aim);
        virtual bool ReactToPrey(VeiwCellContainer* prey);
        virtual bool ReactToPredator(VeiwCellContainer* predator);
        void CalcPath(int& x, int& y, VeiwCellContainer* aim);
        void CalcRunPath(int& x, int& y, VeiwCellContainer* aim);

    protected:
        VeiwCellContainer*** field;
        Ocean* ocean;
        Object* mind;
        int radius;
        int square_size;
        int speed;
        int find_prey;
        Cell* target;
        Cell* self;

    private:

};

#endif // VIEWFIELD_H
