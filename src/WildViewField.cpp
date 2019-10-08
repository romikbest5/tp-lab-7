#include "WildViewField.h"

WildViewField::WildViewField(Cell* self_, int radius_, Ocean* ocean_, Object* mind_):ViewField(self_, radius_, ocean_, mind_)
{
    //ctor
}

WildViewField::~WildViewField()
{
    //dtor
}

bool WildViewField::ReactToPrey(VeiwCellContainer* prey)
{
    bool react = false;
    int new_x = radius, new_y = radius;
    if (prey->distance < find_prey || find_prey == 0)
    {
        CalcPath(new_x, new_y, prey);
        find_prey = prey->distance;
    }

    VeiwCellContainer* aim = field[new_x][new_y];
    if (aim != 0)
    {
        target = aim->origin_cell;
    }
    return react;
}

bool WildViewField::ReactToPredator(VeiwCellContainer* predator)
{
    return false;
}
