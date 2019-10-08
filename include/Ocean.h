#ifndef OCEAN_H
#define OCEAN_H

#include <iostream>
#include <ctime>
#include <vector>
#include "windows.h"

#include "cstdlib"
#include "Predator.h"
#include "Cell.h"


class Ocean
{
    public:
        Ocean(int x_, int y_, int stone_num, int prey_num, int predator_num);
        void CreateObj(int num, ObjType type);
        virtual ~Ocean();
        void Show();
        void Start();
        bool MoveObj(Object* creature,Cell* target);

        Cell* operator()(int x_, int y_);
        Cell* GetCell(int x_, int y_);
        int size_x,size_y;
    protected:

    private:
        Cell*** field;
        std::vector<Object*> stones;
        std::vector<Object*> preys;
        std::vector<Object*> predators;
        std::vector<Cell*> eges;
};

#endif // OCEAN_H
