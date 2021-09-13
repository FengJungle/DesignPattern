#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

class Singleton_Lazy
{
public:
	static Singleton_Lazy* getInstance(){
		printf("This is Singleton Lazy mode...\n");
		if (instance == NULL){
			m_mutex.lock();
			if (instance == NULL){
				printf("创建新的实例\n");
				instance = new Singleton_Lazy();
			}
			m_mutex.unlock();
		}
		return instance;
	}
private:
	Singleton_Lazy(){}

	static Singleton_Lazy* instance;
	static std::mutex m_mutex;
};

Singleton_Lazy* Singleton_Lazy::instance = NULL;
std::mutex Singleton_Lazy::m_mutex;


class Singleton_Hungry
{
public:
	static Singleton_Hungry* getInstance() 
	{
		printf("This Singleton Hungry mode...\n");
		return instance;
	}
private:
	Singleton_Hungry() {}
	static Singleton_Hungry* instance;
};

Singleton_Hungry* Singleton_Hungry::instance = new Singleton_Hungry;

#endif //__SINGLETON_H__