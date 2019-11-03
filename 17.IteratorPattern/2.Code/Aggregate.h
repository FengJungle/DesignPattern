#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__

#include <vector>
using namespace std;

// 前向声明，因为两个类互相引用
class Iterator;
class RemoteControl;

// 抽象聚合类 Aggregate
class Aggregate
{
public:
	Aggregate(){}
	virtual Iterator* createIterator() = 0;
};

// 具体聚合类 Television
class Television :public Aggregate
{
public:
	Television();
	Television(vector<string> iChannelList);
	// 实现创建迭代器
	Iterator* createIterator();
	// 获取总的频道数目
	int getTotalChannelNum();
	void play(int i);
private:
	vector<string> channelList;
};

#endif //__AGGREGATE_H__