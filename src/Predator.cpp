#include "Predator.h"


Predator::Predator(Cell* cell_, Ocean* ocean_):Prey(cell_, ocean_)
{
    life = PREDATOR_LIFE;
    type = PREDATOR;
    ocean = ocean_;
    vision = new WildViewField(cell, PREDATOR_VISION, ocean, this);
    speed = PREDATOR_SPEED;
}

Predator::~Predator()
{
    //dtor
}

void Predator::Eat(int num)
{
    life += num;
}
