#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

//目标抽象类
class Controller
{
public:
	Controller(){}
	virtual void pathPlanning() = 0;
private:
};

//适配者类DxfParser
class DxfParser
{
public:
	DxfParser(){}
	void parseFile(){
		printf("解析文件提取数据\n");
	}
};

//适配者类PathPlanner
class PathPlanner
{
public:
	PathPlanner(){}
	void calculate(){
		printf("计算加工路径\n");
	}
};

//适配器类Adapter
class Adapter:public Controller
{
public:
	Adapter(){
		dxfParser = new DxfParser();
		pathPlanner = new PathPlanner();
	}
	void pathPlanning(){
		printf("路径规划：\n");
		dxfParser->parseFile();
		pathPlanner->calculate();
	}
private:
	DxfParser   *dxfParser;
	PathPlanner *pathPlanner;
};

#endif //__SINGLETON_H__