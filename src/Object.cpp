#include "Object.h"

Object::Object(Cell* cell_)
{
    SetCell(cell_);
}

Object::~Object()
{
    //dtor
}

void Object::SetCell(Cell* cell_)
{
    cell = cell_;
}

