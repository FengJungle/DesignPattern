#include <iostream>
#include "FacadePattern.h"

int main()
{
	Facade *facade = new Facade();
	facade->powerOn();

	printf("\n\n");

	system("pause");
	return 0;
}