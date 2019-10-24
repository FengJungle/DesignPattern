#include "BuilderPattern.h"

int main()
{
	//抽象建造者
	AbstractBuilder *builder;
	//指挥者
	Director *director = new Director();
	//产品：House
	House *house;

	//指定具体建造者A
	builder = new ConcreteBuilderA();
	director->setBuilder(builder);
	house = director->construct();
	house->printfHouseInfo();

	//指定具体建造者B
	builder = new ConcreteBuilderB();
	director->setBuilder(builder);
	house = director->construct();
	house->printfHouseInfo();

	system("pause");
	return 0;
}