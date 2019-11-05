#ifndef __DEMO_H__
#define __DEMO_H__

#ifndef __DEMO_H__
// 前向声明
class Memento;

// 原发器  典型实现
class Originator
{
public:
	Originator(){
		state = "";
	}
	Originator(String iState){
		state = iState;
	}
	// 创建备忘录对象
	Memento* createMemento(){
		return new Memento(this);
	}
	// 利用备忘录对象恢复原发器状态
	void restoreMemento(Memento* m){
		state = m->getState();
	}
	void setState(string iState){ 
		state = iState; 
	}
	string getState(){ 
		return state; 
	}
private:
	string state;
};

// 备忘录  典型实现（仿照原生器的设计）
class Memento
{
public:
	Memento(){
		state = "";
	}
	Memento(Originator* o){
		state = o->getState();
	}
	void setState(String iState){
		state = iState;
	}
	string getState(){
		return state;
	}
private:
	String state;
};

// 负责人  典型实现
class Caretaker
{
public:
	Caretaker(){}
	Memento* getMemento(){
		return memento;
	}
	void setMemento(Memento *m){
		memento = m;
	}
private:
	Memento* memento;
};

// 客户端 示例代码
int main()
{
	// 创建原发器对象
	Originator o = new Originator("状态1");
	// 创建负责人对象
	Caretaker *c = new Caretaker();
	c->setMemento(o->createMemento());

	o->setState("状态2");

	// 从负责人对象中取出备忘录对象，实现撤销
	o->restoreMemento(c->getMemento());

	return 0;
}

#endif 

#endif // __DEMO_H__