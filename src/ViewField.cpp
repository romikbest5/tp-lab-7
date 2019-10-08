#include "ViewField.h"
#include <iostream>
using namespace std;

#include "Ocean.h"
#include "Cell.h"

VeiwCellContainer::VeiwCellContainer()
{

}

VeiwCellContainer::~VeiwCellContainer()
{

}



ViewField::ViewField(Cell* self_, int radius_, Ocean* ocean_, Object* mind_)
{
    radius = radius_;
    self = self_;
    square_size = (2*radius)+1;
    ocean = ocean_;
    mind = mind_;
    field = new VeiwCellContainer**[square_size];
    for (int i = 0; i < square_size; i++)
    {
        field[i] = new VeiwCellContainer*[square_size];
        for (int j = 0; j < square_size; j++)
        {
            field[i][j] = new VeiwCellContainer;

            field[i][j]->relative_x = i;
            field[i][j]->relative_y = j;

            field[i][j]->distance = abs(radius_ - i) + abs(radius_ - j);
        }
    }
    field[radius][radius] = 0;
    SetField(self);
}

ViewField::~ViewField()
{
    //dtor
}

void ViewField::SetField()
{
    SetField(self);
}

void ViewField::SetField(Cell* aim)
{
    int x = aim->x, y = aim->y;
    x -= radius;
    y -= radius;

    for (int i = 0; i < square_size; i++)
    {
        for (int j = 0; j < square_size; j++)
        {
            if (i == radius && i == j)
            {
                y++;
                continue;
            }

            //spherical ocean
            if (x < 0) x = ocean->size_x-1+(x+1);
            else if (x >= ocean->size_x) x = x%ocean->size_x;
            if (y < 0) y = ocean->size_y-1+(y+1);
            else if (y >= ocean->size_y) y = y%ocean->size_y;

            field[i][j]->origin_cell = ocean->GetCell(x, y);

            y++;
        }
        y -= square_size;
        x++;
    }

    self = aim;
}

Cell* ViewField::Observe()
{
    target = 0;
    find_prey = 0;
    bool react = false;
    for (int i = 0; i < square_size && !react; i++)
    {
        for (int j = 0; j < square_size && !react; j++)
        {
            react = ReactToObject(field[i][j]);
        }
    }
    return target;
}

bool ViewField::ReactToObject(VeiwCellContainer* aim)
{
    if (aim == 0)
    {
        return false;
    }
    ObjType aim_type = aim->origin_cell->GetType();
    bool react = false;

    switch(aim_type)
    {
    case NONE:
        break;

    case STONE:
        break;

    case PREY:
        react = ReactToPrey(aim);
        break;

    case PREDATOR:
        react = ReactToPredator(aim);
        break;
    }

    return react;
}

bool ViewField::ReactToPrey(VeiwCellContainer* prey)
{
    bool react = false;
    int new_x = radius, new_y = radius;
    bool aim_tired = prey->origin_cell->GetData()->IsTired();
    if (!mind->IsTired() && !aim_tired)
    {
        if (prey->distance < find_prey || find_prey == 0)
        {
            CalcPath(new_x, new_y, prey);
            find_prey = prey->distance;
        }
    }
    else if (prey->distance <= 2)
    {
        CalcRunPath(new_x, new_y, prey);
    }

    VeiwCellContainer* aim = field[new_x][new_y];
    if (aim != 0)
    {
        target = aim->origin_cell;
    }
    return react;
}

bool ViewField::ReactToPredator(VeiwCellContainer* predator)
{
    bool react = false;
    int new_x = radius, new_y = radius;
    CalcRunPath(new_x, new_y, predator);

    VeiwCellContainer* aim = field[new_x][new_y];
    if (aim != 0)
    {
        target = aim->origin_cell;
        react = true;
    }
    return react;
}

void ViewField::CalcPath(int& x, int& y, VeiwCellContainer* aim)
{
    int aim_x = aim->relative_x, aim_y = aim->relative_y;
    int diff_x = aim_x - x, diff_y = aim_y - y;
    if (diff_x < 0) diff_x = -diff_x;
    if (diff_y < 0) diff_y = -diff_y;

    if (diff_x > diff_y)
    {
        (aim_x > x)?(x++):(x--);
    }
    else
    {
        (aim_y > y)?(y++):(y--);
    }
}

void ViewField::CalcRunPath(int& x, int& y, VeiwCellContainer* aim)
{
    int aim_x = aim->relative_x, aim_y = aim->relative_y;
    int diff_x = aim_x - x, diff_y = aim_y - y;
    if (diff_x < 0) diff_x = -diff_x;
    if (diff_y < 0) diff_y = -diff_y;

    if (diff_x < diff_y)
    {
        (aim_x > x)?(x--):(x++);
    }
    else
    {
        (aim_y > y)?(y--):(y++);
    }
}
