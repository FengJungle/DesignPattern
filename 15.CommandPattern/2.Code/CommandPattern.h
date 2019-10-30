#ifndef __COMMAND_PATTERN_H__
#define __COMMAND_PATTERN_H__

#include <mutex>
#include <time.h>
using namespace std;

//  命令队列类
#define COMMAND_QUEUE

// 抽象命令类 Command
class Command
{
public:
	Command(){}
	// 声明抽象接口：发送命令
	virtual void execute() = 0;
private:
	Command *command;
};

// 接收者：电灯类
class Lamp
{
public :
	Lamp(){
		this->lampState = false;
	}
	void on(){
		lampState = true;
		printf("Lamp is on\n");
	}
	void off(){
		lampState = false;
		printf("Lamp is off\n");
	}
	bool getLampState(){
		return lampState;
	}
private:
	bool lampState;
};

// 接收者：风扇类
class Fan
{
public:
	Fan(){
		this->fanState = false;
	}
	void on(){
		fanState = true;
		printf("Fan is on\n");
	}
	void off(){
		fanState = false;
		printf("Fan is off\n");
	}
	bool getFanState(){
		return fanState;
	}
private:
	bool fanState;
};

// 具体命令类 LampCommand
class LampCommand :public Command
{
public:
	LampCommand(){
		printf("开关控制电灯\n");
		lamp = new Lamp();
	}
	// 实现execute()
	void execute(){
		if (lamp->getLampState()){
			lamp->off();
		}
		else{
			lamp->on();
		}
	}
private:
	Lamp *lamp;
};

// 具体命令类 FanCommand
class FanCommand :public Command
{
public:
	FanCommand(){
		printf("开关控制风扇\n");
		fan = new Fan();
	}
	// 实现execute()
	void execute(){
		if (fan->getFanState()){
			fan->off();
		}
		else{
			fan->on();
		}
	}
private:
	Fan *fan;
};

// 调用者 Button
class Button
{
public:
	Button(){}
	// 注入具体命令类对象
	void setCommand(Command *cmd){
		this->command = cmd;
	}
	// 发送命令：触摸按钮
	void touch(){
		printf("触摸开关:");
		command->execute();
	}
private:
	Command *command;
};

#ifdef COMMAND_QUEUE
/*************************************/
/*             命令队列              */
#include <vector>

// 命令队列类
class CommandQueue
{
public:
	CommandQueue(){
	}
	void addCommand(Command *cmd){
		commandQueue.push_back(cmd);
	}
	void execute(){
		for (int i = 0; i < commandQueue.size(); i++)
		{
			commandQueue[i]->execute();
		}
	}
private:
	vector<Command*>commandQueue;

};

// 调用者
class Button2
{
public:
	Button2(){}
	// 注入具体命令队列类对象
	void setCommandQueue(CommandQueue *cmdQueue){
		this->cmdQueue = cmdQueue;
	}
	// 发送命令：触摸按钮
	void touch(){
		printf("触摸开关:");
		cmdQueue->execute();
	}
private:
	CommandQueue *cmdQueue;
};

#endif


#endif //__COMMAND_PATTERN_H__