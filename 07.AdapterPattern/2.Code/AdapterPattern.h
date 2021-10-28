#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

//Ŀ�������
class Controller
{
public:
	Controller(){}
	virtual ~Controller(){}
	virtual void pathPlanning() = 0;
private:
};

//��������DxfParser
class DxfParser
{
public:
	DxfParser(){}
	void parseFile(){
		printf("�����ļ���ȡ����\n");
	}
};

//��������PathPlanner
class PathPlanner
{
public:
	PathPlanner(){}
	void calculate(){
		printf("����ӹ�·��\n");
	}
};

//��������Adapter
class Adapter:public Controller
{
public:
	Adapter(){
		dxfParser = new DxfParser();
		pathPlanner = new PathPlanner();
	}
	~Adapter(){
		delete dxfParser;
		delete pathPlanner;
	}
	Adapter(const Adapter& other) = delete;
	Adapter& operator=(const Adapter& ) = delete;
	void pathPlanning(){
		printf("·���滮��\n");
		dxfParser->parseFile();
		pathPlanner->calculate();
	}
private:
	DxfParser   *dxfParser;
	PathPlanner *pathPlanner;
};

#endif //__SINGLETON_H__