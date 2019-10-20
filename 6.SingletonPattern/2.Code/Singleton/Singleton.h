#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance(){
		if (instance == NULL){
			m_mutex.lock();
			if (instance == NULL){
				printf("创建新的实例\n");
				instance = new Singleton();
			}
			m_mutex.unlock();
		}
		return instance;
	}
private:
	Singleton(){}

	static Singleton* instance;
	static std::mutex m_mutex;
};

Singleton* Singleton::instance = NULL;
std::mutex Singleton::m_mutex;

#endif //__SINGLETON_H__