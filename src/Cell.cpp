#include "Cell.h"

Cell::Cell()
{
    data = 0;
}

Cell::~Cell()
{
    //dtor
}

void Cell::SetCell(int x_, int y_)
{
    x = x_;
    y = y_;
}

ObjType Cell::GetType()
{
    ObjType tmp = NONE;
    if (data != 0)
    {
        tmp = data->GetType();
    }
    return tmp;
}
