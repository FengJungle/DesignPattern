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
	delete fac;
	delete ball;
	delete shirt;

	fac = new FootballFactory();
	ball = fac->getBall();
	shirt = fac->getShirt();
	delete fac;
	delete ball;
	delete shirt;

	system("pause");
	return 0;
}