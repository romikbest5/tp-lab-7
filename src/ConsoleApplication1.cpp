// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include "cstdlib"
#include "Ocean.h"


using namespace std;
int main()
{
	Ocean Ocean(OCEAN_SIZE_Y, OCEAN_SIZE_X, OCEAN_NUMBER_OF_STONES, OCEAN_NUMBER_OF_PREYS, OCEAN_NUMBER_OF_PREDATORS);
	Ocean.Start();
	system("pause");
	return 0;
}

