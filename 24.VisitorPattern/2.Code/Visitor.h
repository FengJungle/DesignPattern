#ifndef __VISITOR_H__
#define __VISITOR_H__

#include <iostream>
using namespace std;

// 前向声明
class Element;
class Apple;
class Book;

// 抽象访问者
class Visitor
{
public:
	Visitor(){};
	// 声明一组访问方法
	virtual void visit(Apple*) = 0;
	virtual void visit(Book*) = 0;
};

// 具体访问者：顾客
class Customer :public Visitor
{
public:
	Customer();
	Customer(string iName);
	void setNum(Apple*, int);
	void setNum(Book*, int);
	void visit(Apple* apple);
	void visit(Book* book);
private:
	string name;
};

// 具体访问者：收银员
class Cashier :public Visitor
{
public:
	Cashier();
	void visit(Apple* apple);
	void visit(Book* book);
};

#endif