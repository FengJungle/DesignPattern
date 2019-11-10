#ifndef __DEMO_H__
#define __DEMO_H__

// 抽象访问者 Visitor
class Visitor
{
public:
	virtual void visit(ConcreteElementA*) = 0;
	virtual void visit(ConcreteElementB*) = 0;
};

// 具体访问者 ConcreteVisitor
class ConcreteVisitor :public Visitor
{
public:
	// 实现一种针对特定元素的访问操作
	void visit(ConcreteElementA*){
		// 元素A的访问操作代码
	}
	void visit(ConcreteElementB*){
		// 元素B的访问操作代码
	}
};

// 抽象元素
class Element
{
public:
	// 声明抽象方法，以一个抽象访问者的指针作为函数参数
	virtual void accept(Visitor*) = 0;
};

// 具体元素
class ConcreteElement :public Element
{
public:
	void accept(Visitor* visitor){
		visitor->visit(this);
	}
};

// 对象结构
class ObjectStructure
{
public:
	//  提供接口接受访问者访问
	void accept(Visitor* visitor){
		// 遍历访问对象结构中的元素
		for (){
			elementList[i]->accept(visitor);
		}
	}
	void addElement(){}
	void removeElement(){}
private:
	lsit<Element*>elementList;
};

#endif