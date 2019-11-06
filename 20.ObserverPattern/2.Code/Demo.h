#define __DEMO_H__
#ifdef __DEMO_H__

using namespace std;
#include <list>

// 抽象观察者
class Observer
{
public:
	// 声明响应更新方法
	virtual void update() = 0;
};

// 具体观察者
class ConcreteObserver:public Observer
{
public:
	// 实现响应更新方法
	void update(){
		// 具体操作
	}
};

// 抽象目标
class Subject
{
public:
	// 添加观察者
	void attach(Observer* obs){
		obsList.push_back(obs);
	}
	// 移除观察者
	void detach(Observer* obs){
		obsList.remove(obs);
	}
	// 声明通知方法
	virtual void notify() = 0;
protected:
	// 观察者列表
	list<Observer*>obsList;
};

// 具体目标
class ConcreteSubject :public Subject
{
public:
	// 实现通知方法
	void notify(){
		// 具体操作
		// 遍历通知观察者对象
		for (int i = 0; i < obsList.size(); i++){
			obsList[i]->update();
		}
	}
};

// 客户端代码示例
int main()
{
	Subject  *sub = new ConcreteSubject();
	Observer *obs = new ConcreteObserver();
	sub->attach(obs);
	sub->notify();
	return 0;
}
#endif