#ifndef __MEDIATOR_PATTERN_H__
#define __MEDIATOR_PATTERN_H__

#include "common.h"
#include "Colleague.h"

// 抽象中介者
class Mediator
{
public:
	Mediator(){}
	// 声明抽象方法
	virtual void operation(Colleague*) = 0;
	// 声明注册方法
	virtual void registerMethod(Colleague*) = 0;
};

// 具体中介者
class Agency:public Mediator
{
public:
	Agency(){}
	void registerMethod(Colleague* person){
		switch (person->getPersonType()){
		case LANDLORD:
			landlordList.push_back((Landlord*)person);
			break;
		case TENANT:
			tenantList.push_back((Tenant*)person);
			break;
		default:
			printf("wrong person\n");
		}
	}
	void operation(Colleague* person){
		switch (person->getPersonType()){
		case LANDLORD:
			for (int i = 0; i < tenantList.size(); i++){
				tenantList[i]->answer();
			}
			break;
		case TENANT:
			for (int i = 0; i < landlordList.size(); i++){
				landlordList[i]->answer();
			}
			break;
		default:
			break;
		}
	}
private:
	vector<Landlord*>landlordList;
	vector<Tenant*>tenantList;
};


#endif //__MEDIATOR_PATTERN_H__