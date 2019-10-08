#ifndef OBJECT_H
#define OBJECT_H
#include "Common.h"
class Ocean;
class Cell;
enum ObjType { STONE, PREY, PREDATOR, NONE };

class Object
{
    public:
        Object(Cell* cell_);
        virtual ~Object();
        void SetCell(Cell* cell_);
        virtual bool Update() = 0;
        virtual bool MoveTo(Cell* target) = 0;
        virtual void Damage(int num) = 0;
        virtual bool IsTired() = 0;
        virtual void Tired() = 0;
        virtual void Eat(int num) = 0;

        Cell* GetCell(){return cell;};
        ObjType GetType(){return type;};
    protected:
        Cell* cell;
        ObjType type;
        Ocean* ocean;

    private:

};

#endif // OBJECT_H
