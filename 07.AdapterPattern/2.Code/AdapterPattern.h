#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

// 目标抽象类
class Controller
{
public:
	Controller(){}
	virtual ~Controller(){}
	virtual void pathPlanning() = 0;
private:
};

// 适配者类DxfParser
class DxfParser
{
public:
	DxfParser(){}
	void parseFile(){
		printf("Parse dxf file\n");
	}
};

// 适配者类PathPlanner
class PathPlanner
{
public:
	PathPlanner(){}
	void calculate(){
		printf("calculate path\n");
	}
};

// 适配器类Adapter
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
		printf("pathPlanning\n");
		dxfParser->parseFile();
		pathPlanner->calculate();
	}
private:
	DxfParser   *dxfParser;
	PathPlanner *pathPlanner;
};

#endif //__SINGLETON_H__