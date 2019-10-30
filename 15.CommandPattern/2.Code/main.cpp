#include <iostream>
#include "CommandPattern.h"

int main()
{
	// 实例化调用者：按钮
	Button *button = new Button();
	Command *lampCmd, *fanCmd;

	// 按钮控制电灯
	lampCmd = new LampCommand();
	button->setCommand(lampCmd);
	button->touch();
	button->touch();
	button->touch();

	printf("\n\n");

	// 按钮控制风扇
	fanCmd = new FanCommand();
	button->setCommand(fanCmd);
	button->touch();
	button->touch();
	button->touch();

#ifdef COMMAND_QUEUE

	printf("\n\n***********************************\n");
	Button2 *button2 = new Button2();
	Command *lampCmd2, *fanCmd2;
	CommandQueue *cmdQueue = new CommandQueue();

	// 按钮控制电灯
	lampCmd2 = new LampCommand();
	cmdQueue->addCommand(lampCmd2);

	// 按钮控制风扇
	fanCmd2 = new FanCommand();
	cmdQueue->addCommand(fanCmd2);

	button2->setCommandQueue(cmdQueue);
	button2->touch();

#endif

	printf("\n\n");
	system("pause");
	return 0;
}