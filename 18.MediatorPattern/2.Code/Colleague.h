#ifndef __COLLEAGUE_H__
#define __COLLEAGUE_H__

#include "common.h"
using namespace std;

// 前向声明
class Mediator;
class Agency;

// 抽象同事类
class Colleague
{
public:
	Colleague(){}
	void setMediator(Mediator* iMediator){
		this->mediator = iMediator;
	}
	Mediator* getMediator(){
		return this->mediator;
	}
	void setPersonType(PERSON_TYPE iPersonType){
		this->personType = iPersonType;
	}
	PERSON_TYPE getPersonType(){
		return this->personType;
	}
	virtual void ask() = 0;
	virtual void answer() = 0;
private:
	PERSON_TYPE personType;
	Mediator* mediator;
};

// 具体同事类：房东
class Landlord :public Colleague
{
public:
	Landlord();
	Landlord(string iName, int iPrice, string iAddress, string iPhoneNum);
	void ask();
	void answer();
private:
	string name;
	int price;
	string address;
	string phoneNumber;
};

// 具体同事类：租客
class Tenant :public Colleague
{
public:
	Tenant();
	Tenant(string name);
	void ask();
	void answer();
private:
	string name;
};

#endif //__COLLEAGUE_H__