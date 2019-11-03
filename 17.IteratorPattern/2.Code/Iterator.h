#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#pragma once
#include "Aggregate.h"

#include <vector>
using namespace std;

// 抽象迭代器
class Iterator
{
public:
	Iterator(){}
	// 声明抽象遍历方法
	virtual void first() = 0;
	virtual void last() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool hasNext() = 0;
	virtual bool hasPrevious() = 0;
	virtual void currentChannel() = 0;
private:

};

// 遥控器：具体迭代器
class RemoteControl :public Iterator
{
public:
	RemoteControl(){}
	void setTV(Television *iTv){
		this->tv = iTv;
		cursor = -1;
		totalNum = tv->getTotalChannelNum();
	}
	// 实现各个遍历方法
	void first(){
		cursor = 0;
	}
	void last(){
		cursor = totalNum - 1;
	}
	void next(){
		cursor++;
	}
	void previous(){
		cursor--;
	}
	bool hasNext(){
		return !(cursor == totalNum);
	}
	bool hasPrevious(){
		return !(cursor == -1);
	}
	void currentChannel(){
		tv->play(cursor);
	}
private:
	// 游标
	int cursor;
	// 总的频道数目
	int totalNum;
	// 电视
	Television* tv;
};


#endif