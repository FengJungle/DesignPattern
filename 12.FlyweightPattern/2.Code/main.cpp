#include <iostream>
#include "FlyweightPattern.h"

int main()
{
	NetDeviceFactory *factory = NetDeviceFactory::getFactory();

	NetDevice *device1, *device2, *device3, *device4;

	// 客户端1获取一个hub
	device1 = factory->getNetDevice('H');
	device1->print(1);
	// 客户端2获取一个hub
	device2 = factory->getNetDevice('H');
	device2->print(2);
	// 判断两个hub是否是同一个
	printf("判断两个hub是否是同一个:\n");
	printf("device1:%p\ndevice2:%p\n", device1, device2);

	printf("\n\n\n\n");
	// 客户端3获取一个switch
	device3 = factory->getNetDevice('S');
	device3->print(1);
	// 客户端4获取一个switch
	device4 = factory->getNetDevice('S');
	device4->print(2);
	// 判断两个switch是否是同一个
	printf("判断两个switch是否是同一个:\n");
	printf("device3:%p\ndevice4:%p\n", device3, device4);

	printf("\n\n");

	delete factory;
	delete device1;
	delete device2;
	delete device3;
	delete device4;
	factory = nullptr;
	device1 = nullptr;
	device2 = nullptr;
	device3 = nullptr;
	device4 = nullptr;
	
	system("pause");
	return 0;
}