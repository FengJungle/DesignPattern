#include <iostream>
#include "Iterator.h"

int main()
{
	vector<string> channelList = { "新闻频道", "财经频道", "体育频道", "电影频道", "音乐频道", "农业频道", "四川卫视", "成都卫视" };
	// 创建电视
	Television *tv = new Television(channelList);
	// 创建遥控器
	Iterator *remoteControl = tv->createIterator();

	// 顺序遍历
	printf("顺序遍历:\n");
	remoteControl->first();
	// 遍历电视所有频道
	while (remoteControl->hasNext()){
		remoteControl->currentChannel();
		remoteControl->next();
	}

	printf("\n\n");

	// 逆序遍历
	printf("逆序遍历:\n");
	remoteControl->last();
	// 遍历电视所有频道
	while (remoteControl->hasPrevious()){
		remoteControl->currentChannel();
		remoteControl->previous();
	}

	printf("\n\n");
	system("pause");
	return 0;
}