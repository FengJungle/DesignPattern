#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
using namespace std;
#include "common.h"
#include "AllyCenter.h"

// 抽象观察者 Observer
class Observer
{
public:
	Observer(){}
	// 声明抽象方法
	virtual void call(INFO_TYPE infoType, AllyCenter* ac) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		this->name = iName;
	}
private:
	string name;
};

// 具体观察者 
class Player :public Observer
{
public:
	Player(){
		setName("none");
	}
	Player(string iName){
		setName(iName);
	}
	// 实现
	void call(INFO_TYPE infoType, AllyCenter* ac){
		switch (infoType){
		case RESOURCE:
			printf("%s :我这里有物资\n", getName().c_str());
			break;
		case HELP:
			printf("%s :救救我\n", getName().c_str());
			break;
		default:
			printf("Nothing\n");
		}
		ac->notify(infoType, getName());
	}
	// 实现具体方法
	void help(){
		printf("%s:坚持住，我来救你！\n", getName().c_str());
	}
	void come(){
		printf("%s:好的，我来取物资\n", getName().c_str());
	}
};

#endif
