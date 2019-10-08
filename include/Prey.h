#ifndef PREY_H
#define PREY_H

#include "Stone.h"
class ViewField;

struct Destination {
int x = 0;
int y = 0;
int remaining = 0;
};

class Prey :
public Stone
{
    public:
        Prey(Cell* cell_, Ocean* ocean_);
        virtual ~Prey();
        virtual bool Update();
        virtual void ChooseNewAim();
        virtual bool MoveTo(Cell* target);
        virtual void Damage(int num);
        virtual void Eat(int num){};
        bool IsTired(){return is_tire;};
        void Tired();

    protected:
        ViewField* vision;
        Destination current_aim;
        int speed;

    private:
        bool is_tire = false;
        int tire_counter;
        int tire_waiting;


};

#endif // PREY_H
