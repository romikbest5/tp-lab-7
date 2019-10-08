#ifndef WILDVIEWFIELD_H
#define WILDVIEWFIELD_H

#include "ViewField.h"

class WildViewField :
public ViewField
{
    public:
        WildViewField(Cell* self_, int radius_, Ocean* ocean_, Object* mind_);
        virtual ~WildViewField();
        virtual bool ReactToPrey(VeiwCellContainer* prey);
        virtual bool ReactToPredator(VeiwCellContainer* predator);

    protected:

    private:
};

#endif // WILDVIEWFIELD_H
