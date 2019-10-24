#ifndef __DECORATOR_PATTERN_H__
#define __DECORATOR_PATTERN_H__

//抽象构件
class Component
{
public:
	Component(){}
	virtual void operation() = 0;
};

//具体构件类
class Phone :public Component
{
public:
	Phone(){}
	void operation(){
		printf("手机\n");
	}
};

//抽象装饰类
class Decorator :public Component
{
public:
	Decorator(){}
	Decorator(Component *c){
		this->component = c;
	}
	void operation(){
		this->component->operation();
	}
	Component *getComponent(){
		return this->component;
	}
	void setComponent(Component *c){
		this->component = c;
	}
private:
	Component *component;
};

//具体装饰类：手机壳
class DecoratorShell:public Decorator
{
public:
	DecoratorShell(){}
	DecoratorShell(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("装手机壳\n");
	}
};

//具体装饰类：手机贴纸
class DecoratorSticker :public Decorator
{
public:
	DecoratorSticker(){}
	DecoratorSticker(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("贴卡通贴纸\n");
	}
};

//具体装饰类：手机挂绳
class DecoratorRope :public Decorator
{
public:
	DecoratorRope(){}
	DecoratorRope(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("系手机挂绳\n");
	}
};
#endif //__DECORATOR_PATTERN_H__