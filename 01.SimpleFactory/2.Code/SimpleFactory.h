#ifndef __SIMPLE_FACTORY__
#define __SIMPLE_FACTORY__

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
		printf("Jungle play Basketball\n");
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
		printf("Jungle play Football\n");
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
		printf("Jungle play Volleyball\n");
	}
};

class Factory
{
public:
	AbstractSportProduct *getSportProduct(string productName)
	{
		AbstractSportProduct *pro = NULL;
		if (productName == "Basketball"){
			pro = new Basketball();
		}
		else if (productName == "Football"){
			pro = new Football();
		}
		else if (productName == "Volleyball"){
			pro = new Volleyball();
		}
		return pro;
	}
};


#endif //__SIMPLE_FACTORY__