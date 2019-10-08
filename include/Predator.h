#ifndef PREDATOR_H
#define PREDATOR_H

#include "WildViewField.h"
#include "Prey.h"

class Predator :
public Prey
{
    public:
        Predator(Cell* cell_, Ocean* ocean_);
        virtual ~Predator();
        virtual void Eat(int num);

    protected:

    private:
};

#endif // PREDATOR_H
