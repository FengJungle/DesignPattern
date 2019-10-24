#include <iostream>
#include "AbstractFactory.h"

int main()
{
	AbstractFactory *fac = NULL;
	AbstractBall *ball = NULL;
	AbstractShirt *shirt = NULL;

	fac = new BasketballFactory();
	ball = fac->getBall();
	shirt = fac->getShirt();

	fac = new FootballFactory();
	ball = fac->getBall();
	shirt = fac->getShirt();

	system("pause");
	return 0;
}