#ifndef STONE_H
#define STONE_H

#include "Object.h"

class Stone :
public Object
{
    public:
        Stone(Cell* cell_, Ocean* ocean_);
        virtual ~Stone();
        virtual bool Update();
		virtual bool MoveTo(Cell* target);;
        virtual void Damage(int num){};
		virtual bool IsTired();;
        virtual void Tired(){};
        virtual void Eat(int num){};

        int GetLife(){return life;};
    protected:
        int life;

    private:

};

#endif // STONE_H
