#ifndef CELL_H
#define CELL_H

#include "Object.h"

class Cell
{
    public:
        Cell();
        virtual ~Cell();
        void SetCell(int x_, int y_);
        ObjType GetType();
        Object* GetData(){return data;};
        void SetLife(Object* data_){data = data_;};

        int x;
        int y;
    protected:

    private:
        Object* data;
};


#endif // CELL_H
