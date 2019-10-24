#ifndef __ABSTRACT_FACTORY__
#define __ABSTRACT_FACTORY__

#include <iostream>
#include <string.h>
using namespace std;

//抽象产品类AbstractBall
class AbstractBall
{
public:
	AbstractBall(){

	}
	//抽象方法：
	void play(){};
};

//具体产品类Basketball
class Basketball :public AbstractBall
{
public:
	Basketball(){
		play();
	}
	//具体实现方法
	void play(){
		printf("Jungle play Basketball\n\n");
	}
};

//具体产品类Football
class Football :public AbstractBall
{
public:
	Football(){
		play();
	}
	//具体实现方法
	void play(){
		printf("Jungle play Football\n\n");
	}
};

//抽象产品类AbstractShirt
class AbstractShirt
{
public:
	AbstractShirt(){}
	//抽象方法：
	void wearShirt(){};
};

//具体产品类BasketballShirt
class BasketballShirt :public AbstractShirt
{
public:
	BasketballShirt(){
		wearShirt();
	}
	//具体实现方法
	void wearShirt(){
		printf("Jungle wear Basketball Shirt\n\n");
	}
};

//具体产品类FootballShirt
class FootballShirt :public AbstractShirt
{
public:
	FootballShirt(){
		wearShirt();
	}
	//具体实现方法
	void wearShirt(){
		printf("Jungle wear Football Shirt\n\n");
	}
};

//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractBall *getBall() = 0;
	virtual AbstractShirt *getShirt() = 0;
};

//具体工厂类BasketballFactory
class BasketballFactory :public AbstractFactory
{
public:
	BasketballFactory(){
		printf("BasketballFactory\n");
	}
	AbstractBall *getBall(){
		printf("Jungle get basketball\n");
		return new Basketball();
	}
	AbstractShirt *getShirt(){
		printf("Jungle get basketball shirt\n");
		return new BasketballShirt();
	}
};

//具体工厂类BasketballFactory
class FootballFactory :public AbstractFactory
{
public:
	FootballFactory(){
		printf("FootballFactory\n");
	}
	AbstractBall *getBall(){
		printf("Jungle get football\n");
		return new Football();
	}
	AbstractShirt *getShirt(){
		printf("Jungle get football shirt\n");
		return new FootballShirt();
	}
};

#endif //__ABSTRACT_FACTORY__