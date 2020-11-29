#include <iostream>
#include "FacadePattern.h"

int main()
{
	Facade *facade = new Facade();
	facade->powerOn();

	printf("\n\n");
	delete facade;
	system("pause");
	return 0;
}