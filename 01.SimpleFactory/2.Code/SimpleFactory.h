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
	virtual ~AbstractSportProduct(){};
	//抽象方法：
	// virtual void printName(){};
	virtual void printName() = 0;
	// virtual void play(){};
	virtual void play() = 0;
};

//具体产品类Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
		printName();
		play();
	}
	~Basketball()
	{

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
	~Football()
	{

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
	~Volleyball()
	{
		
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
	std::shared_ptr<AbstractSportProduct> getSportProduct(string productName)
	{
		std::shared_ptr<AbstractSportProduct> pro;
		if (productName == "Basketball"){
			pro = std::shared_ptr<AbstractSportProduct>(new Basketball());
		}
		else if (productName == "Football"){
			pro = std::shared_ptr<AbstractSportProduct>(new Football());
		}
		else if (productName == "Volleyball"){
			pro = std::shared_ptr<AbstractSportProduct>(new Volleyball());
		}
		return pro;
	}
};


#endif //__SIMPLE_FACTORY__