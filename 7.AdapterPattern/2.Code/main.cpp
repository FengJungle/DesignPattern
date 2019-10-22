#include <iostream>
#include "AdapterPattern.h"

int main()
{
	Controller *controller = new Adapter();
	controller->pathPlanning();

	system("pause");
	return 0;
}