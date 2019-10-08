#include "Stone.h"

Stone::Stone(Cell* cell_, Ocean* ocean_):Object(cell_)
{
    life = STONE_LIFE;
    type = STONE;
    ocean = ocean_;
}

Stone::~Stone()
{
    //dtor
}

bool Stone::Update()
{
    life = 0;
	return 1;
}

inline bool Stone::MoveTo(Cell * target) { return 1; }

inline bool Stone::IsTired() { return 1; }
