#include "Ocean.h"
using namespace std;

Ocean::Ocean(int x_, int y_, int stone_num, int prey_num, int predator_num)
{
    if (x_ > 0 && y_> 0)
    {
        size_x = x_;
        size_y = y_;
        field = new Cell**[x_];
        for (int i = 0; i < x_; i++)
        {
            field[i] = new Cell*[y_];
            for (int j = 0; j < y_; j++)
            {
                field[i][j] = new Cell;
                field[i][j]->SetCell(i,j);
            }
        }

        srand(time(0));
        CreateObj(stone_num, STONE);
        CreateObj(prey_num, PREY);
        CreateObj(predator_num, PREDATOR);
    }
}

void Ocean::CreateObj(int num, ObjType type)
{
    int x = 0, y = 0;
    for (int i =0; i < num; i++)
    {
        while (1)
        {
            x = rand() % size_x;
            y = rand() % size_y;
            if (field[x][y]->GetType() == NONE)
            {
                switch(type)
                {
                case STONE:
                    stones.push_back(new Stone(field[x][y], this));
                    field[x][y]->SetLife(stones.back());
                    break;
                case PREY:
                    preys.push_back(new Prey(field[x][y], this));
                    field[x][y]->SetLife(preys.back());
                    break;
                case PREDATOR:
                    predators.push_back(new Predator(field[x][y], this));
                    field[x][y]->SetLife(predators.back());
                    break;
                default:
                    break;
                }
                break;
            }
        }
    }
}


Ocean::~Ocean()
{
    //dtor
}

void Ocean::Show()
{
    system("cls");
    ObjType tmp;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            tmp = field[i][j]->GetType();

            switch(tmp)
            {
            case STONE:
                cout<<"0";
                break;
            case PREY:
                cout<<"f";
                break;
            case PREDATOR:
                cout<<"S";
                break;
            default:
                cout<<"~";
                break;
            }
        }
        cout<<"|"<<endl;
    }
}

void Ocean::Start()
{
    while (preys.size()>0 && predators.size()>0)
    {
        int i = 0;
        while (1)
        {
            if (i >= preys.size())
            {
                i = 0;
                break;
            }
            if (!preys[i]->Update())
            {
                if (preys[i]->GetCell()->GetData() == preys[i])
                {
                    preys[i]->GetCell()->SetLife(0);
                }
                preys.erase(preys.begin() + i);
                i--;
            }
            i++;
        }

        //place eges
        for (int j = 0; j < eges.size(); j++)
        {
            if (eges[j]->GetType() == NONE)
            {
                Prey* tadpole = new Prey(eges[i], this);
                eges[j]->SetLife(tadpole);
                preys.push_back(tadpole);
                eges.erase(eges.begin() + j);
            }
        }

        while (1)
        {
            if (i >= predators.size())
            {
                break;
            }
            if (!predators[i]->Update())
            {
                if (predators[i]->GetCell()->GetData() == predators[i])
                {
                    predators[i]->GetCell()->SetLife(0);
                }
                predators.erase(predators.begin() + i);
                i--;
            }
            i++;
        }
        Show();
        Sleep(100);
        //system("pause");

    }
}

bool Ocean::MoveObj(Object* creature,Cell* target)
{
    bool moved = false;
    ObjType creature_type = creature->GetType();
    ObjType target_type = target->GetType();
    Object* target_creatur = target->GetData();
    if (target_type == NONE)
    {
        creature->GetCell()->SetLife(0);
        target->SetLife(creature);
        creature->SetCell(target);
        moved = true;
    }
    else if (target_type == STONE)
    {
        creature->Damage(5);
    }
    else //two fish
    {
        if (creature_type == PREDATOR) //target dead;
        {
            target_creatur->Damage(-1);
            creature->Eat(5);

            creature->GetCell()->SetLife(0);
            target->SetLife(creature);
            creature->SetCell(target);
            moved = true;
        }
        else if (creature_type == PREY)
        {
            if (target_type == PREY)//multiply prey
            {
                if (!target_creatur->IsTired() && !creature->IsTired())
                {
                    eges.push_back(target);
                    creature->Tired();
                    target_creatur->Tired();
                }
            }
            else
            {
                creature->Damage(-1);
                target_creatur->Eat(5);
            }
        }
    }
    return moved;
}

Cell* Ocean::operator()(int x_, int y_)
{
    if ((x_ >= 0 && x_ < size_x) &&
        (y_ >= 0 && y_ < size_y))
    {
        return field[x_][y_];
    }
    return 0;
}

Cell* Ocean::GetCell(int x_, int y_)
{
    if ((x_ >= 0 && x_ < size_x) &&
        (y_ >= 0 && y_ < size_y))
    {
        return field[x_][y_];
    }
    return 0;
}
