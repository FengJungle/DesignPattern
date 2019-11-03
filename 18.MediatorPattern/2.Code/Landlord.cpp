#include "Colleague.h"
#include "Mediator.h"

Landlord::Landlord(){
	name = "none";
	price = 0;
	address = "none";
	phoneNumber = "none";
	setPersonType(NONE_PERSON);
}

Landlord::Landlord(string iName, int iPrice, 
	string iAddress, string iPhoneNum){
	name = iName;
	price = iPrice;
	address = iAddress;
	phoneNumber = iPhoneNum;
	setPersonType(LANDLORD);
}

void Landlord::answer(){
	printf("房东姓名：%s, 房租：%d, 地址：%s, 联系电话：%s\n",
		name.c_str(), price, address.c_str(), phoneNumber.c_str());
}

void Landlord::ask(){
	printf("房东%s查看租客信息：\n",name.c_str());
	(this->getMediator())->operation(this);
}