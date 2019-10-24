#ifndef __COMPOSITE_PATTERN_H__
#define __COMPOSITE_PATTERN_H__

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//抽象构件
class Component
{
public:
	Component(){}
	Component(string iName){
		this->name = iName;
	}
	//增加一个部门或办公室
	virtual void add(Component*) = 0;
	//撤销一个部门或办公室
	virtual void remove(Component*) = 0;
	//
	virtual Component* getChild(int) = 0;
	//各部门操作
	virtual void operation() = 0;
	string getName(){
		return name;
	}
private:
	string name;
};

//叶子构件：办公室
class Office :public Component
{
public:
	Office(string iName){
		this->name = iName;
	}
	Office(){}
	void add(Component* c){
		printf("not support!\n");
	}
	void remove(Component* c){
		printf("not support!\n");
	}
	Component* getChild(int i){
		printf("not support!\n");
		return NULL;
	}
private:
	string name;
};

//叶子构件：行政办公室
class AdminOffice :public Office
{
public:
	AdminOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Administration Office:%s\n", name.c_str());
	}
private:
	string name;
};

//叶子构件：教务办公室
class DeanOffice :public Office
{
public:
	DeanOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Dean Office:%s\n", name.c_str());
	}
private:
	string name;
};

//容器构件SubComponent
class SubComponent :public Component
{
public:
	SubComponent(string iName){
		this->name = iName;
	}
	void add(Component *c){
		componentList.push_back(c);
	}
	void remove(Component *c){
		for (int i = 0; i < componentList.size(); i++){
			if (componentList[i]->getName() == c->getName()){
				componentList.erase(componentList.begin() + i);
				break;
			}
		}
	}
	Component* getChild(int i){
		return (Component*)componentList[i];
	}
	void operation(){
		printf("%s\n", this->name.c_str());
		for (int i = 0; i < componentList.size(); i++){
			((Component*)componentList[i])->operation();
		}
	}
private:
	string name;

	//构件列表
	vector<Component*>componentList;
};

#endif //__COMPOSITE_PATTERN_H__