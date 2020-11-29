#include <iostream>
#include "FactoryMethod.h"

int main()
{
	printf("工厂方法模式\n");
	
	//定义工厂类对象和产品类对象
	AbstractFactory *fac = NULL;
	AbstractSportProduct *product = NULL;

	fac = new BasketballFactory();
	product = fac->getSportProduct();
	if (fac)
	{
		delete fac;
	}
	if (product) {
		delete product;
	}

	fac = new FootballFactory();
	product = fac->getSportProduct();
	if (fac)
	{
		delete fac;
	}
	if (product) {
		delete product;
	}

	fac = new VolleyballFactory();
	product = fac->getSportProduct();	
	if (fac)
	{
		delete fac;
	}
	if (product) {
		delete product;
	}

	system("pause");
	return 0;
}