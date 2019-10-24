#include <iostream>
#include "SimpleFactory.h"

int main()
{
	printf("简单工厂模式\n");
	
	//定义工厂类对象
	Factory *fac = new Factory();
	AbstractSportProduct *product = NULL;

	product = fac->getSportProduct("Basketball");

	product = fac->getSportProduct("Football");

	product = fac->getSportProduct("Volleyball");	

	system("pause");
	return 0;
}