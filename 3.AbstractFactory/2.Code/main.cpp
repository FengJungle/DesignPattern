#include <iostream>
#include "AbstractFactory.h"

int main()
{
	printf("工厂方法模式\n");
	
	//定义工厂类对象和产品类对象
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