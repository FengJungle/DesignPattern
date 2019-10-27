#ifndef __FLYPATTERN_PATTERN_H__
#define __FLYPATTERN_PATTERN_H__

#include <mutex>
#include <vector>
using namespace std;

// 抽象享元类
class NetDevice
{
public:
	NetDevice(){}
	virtual string getName() = 0;

	/*void print(){
		printf("NetDevice :%s\n",getName().c_str());
	}*/
	void print(int portNum){
		printf("NetDevice :%s  port: %d\n", getName().c_str(), portNum);
	}
};

// 具体享元类:集线器
class Hub :public NetDevice
{
public:
	Hub(){}
	string getName(){
		return "集线器";
	}
};

// 具体享元类:交换机
class Switch :public NetDevice
{
public:
	Switch(){}
	string getName(){
		return "交换机";
	}
};

// 享元工厂类
class NetDeviceFactory
{
public:
	NetDevice* getNetDevice(char ch){
		if (ch == 'S'){
			return devicePool[1];
		}
		else if (ch == 'H'){
			return devicePool[0];
		}
		else{
			printf("wrong input!\n");
		}
		return NULL;
	}

	// 单例模式：返回享元工厂类的唯一实例
	static NetDeviceFactory* getFactory(){
		if (instance == NULL){
			m_mutex.lock();
			if (instance == NULL){
				instance = new NetDeviceFactory();
			}
			m_mutex.unlock();
		}
		return instance;
	}

private:
	NetDeviceFactory(){
		Hub *hub = new Hub();
		Switch *switcher = new Switch();
		devicePool.push_back(hub);
		devicePool.push_back(switcher);
	}
	static NetDeviceFactory* instance;
	static std::mutex m_mutex;

	// 共享池：用一个vector来表示
	vector<NetDevice*> devicePool;
};

NetDeviceFactory* NetDeviceFactory::instance = NULL;
std::mutex NetDeviceFactory::m_mutex;

#endif //__FLYPATTERN_PATTERN_H__