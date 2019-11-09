#ifndef __DEMO_H__
#define __DEMO_H__

// 抽象状态类
class State
{
public:
	// 声明抽象方法
	virtual void handle() = 0;
};

// 具体状态类
class ConcreteState :public State
{
public:
	// 实现
	void handle(){
		// ……
	}
};

// 上下文类
class Context
{
public:
	// set方法设置状态对象
	void setState(State* iState){
		this->state = iState;
	}
	// 对外封装的方法
	void request(){
		// do something
		state->handle();
	}
private:
	// 引用状态对象
	State *state;
};

// 1.由环境类来决定实例化为哪一个具体状态类对象
class Context
{
public:
	void convertState(){
		if (condition1){
			this->state = new ConcreteStateA();
		}
		else if (condition2){
			this->state = new ConcreteStateB();
		}
		else{
			// do something
		}
	}
private:
	// 引用状态对象
	State *state;
};
// 2.有具体状态类来决定转换成哪一个具体状态类对象
class ConcreteState :public State
{
public:
	void convertState(Context* ctx){
		if (condition1){
			ctx->setState(new ConcreteStateA());
		}
		else if (condition2){
			ctx->setState(new ConcreteStateB());
		}
		else{
			// do something
		}
	}
};

#endif //__DEMO_H__