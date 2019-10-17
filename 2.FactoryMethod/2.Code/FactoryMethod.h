#ifndef __FACTORY_METHOD__
#define __FACTORY_METHOD__

#include <iostream>
#include <string.h>
using namespace std;

//抽象产品类AbstractProduct
class AbstractSportProduct
{
public:
	AbstractSportProduct(){

	}
	//抽象方法：
	void printName(){};
	void play(){};
};

//具体产品类Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
		printName();
		play();
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Basketball\n");
	}
	void play(){
		printf("Jungle play Basketball\n\n");
	}
};

//具体产品类Football
class Football :public AbstractSportProduct
{
public:
	Football(){
		printName();
		play();
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Football\n");
	}
	void play(){
		printf("Jungle play Football\n\n");
	}
};

//具体产品类Volleyball
class Volleyball :public AbstractSportProduct
{
public:
	Volleyball(){
		printName();
		play();
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Volleyball\n");
	}
	void play(){
		printf("Jungle play Volleyball\n\n");
	}
};

//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractSportProduct *getSportProduct() = 0;
};

//具体工厂类BasketballFactory
class BasketballFactory :public AbstractFactory
{
public:
	BasketballFactory(){
		printf("BasketballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		printf("basketball");
		return new Basketball();
	}
};

//具体工厂类FootballFactory
class FootballFactory :public AbstractFactory
{
public:
	FootballFactory(){
		printf("FootballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		return new Football();
	}
};

//具体工厂类VolleyballFactory
class VolleyballFactory :public AbstractFactory
{
public:
	VolleyballFactory(){
		printf("VolleyballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		return new Volleyball();
	}
};


#endif //__FACTORY_METHOD__