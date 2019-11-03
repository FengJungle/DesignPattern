#include "Colleague.h"
#include "Mediator.h"

Tenant::Tenant(){
	name = "none";
	setPersonType(NONE_PERSON);
}

Tenant::Tenant(string iName){
	name = iName;
	setPersonType(TENANT);
}

void Tenant::ask(){
	printf("租客%s询问房东信息\n", name.c_str()); 
	(this->getMediator())->operation(this);
}

void Tenant::answer(){
	printf("租客姓名：%s\n", name.c_str());
}