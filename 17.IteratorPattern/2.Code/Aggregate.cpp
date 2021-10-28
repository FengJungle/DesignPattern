#include "Iterator.h"

Television::Television(){}

Television::Television(vector<string> iChannelList){
	this->channelList = iChannelList;
}

Iterator* Television::createIterator(){
	RemoteControl *it = new RemoteControl();
	it->setTV(this);
	return (Iterator*)it;
}

int Television::getTotalChannelNum(){
	return channelList.size();
}

void Television::play(int i){
	printf("现在播放：%s……\n", channelList[i].c_str());
}