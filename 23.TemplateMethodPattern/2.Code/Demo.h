#ifndef __DEMO_H__
#define __DEMO_H__

// 抽象类（基类）
class AbstractClass
{
public:
	// 模板方法，定义一个算法的框架流程
	void templateMethod(){
		// do something
		method1();
		method2();
		method3();
	}
	// 基本方法——公共方法
	void mehtod1(){
		// do something
	}
	// 基本方法2
	virtual void method2() = 0;
	// 基本方法3——默认实现
	void mehtod3(){
		// do something
	}
};

// 具体类（派生类)
class ConcreteClass :public AbstractClass
{
public:
	// 实现基本方法2
	void method2(){
		// do something
	}
	// 重定义基本方法3，覆盖基类的方法3
	void method3(){
		// do something
	}
};

#endif