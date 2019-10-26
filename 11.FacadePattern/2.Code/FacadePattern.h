#ifndef __FACADE_PATTERN_H__
#define __FACADE_PATTERN_H__

//子系统：内存
class Memory
{
public:
	Memory(){}
	void selfCheck(){
		printf("…………内存自检……\n");
	}
};

//子系统：CPU
class CPU
{
public:
	CPU(){}
	void run(){
		printf("…………运行CPU运行……\n");
	}
};

//子系统：硬盘
class HardDisk
{
public:
	HardDisk(){}
	void read(){
		printf("…………读取硬盘……\n");
	}
};

//子系统：操作系统
class OS
{
public:
	OS(){}
	void load(){
		printf("…………载入操作系统……\n");
	}
};

//外观类
class Facade
{
public:
	Facade(){
		memory = new Memory();
		cpu = new CPU();
		hardDisk = new HardDisk();
		os = new OS();
	}
	void powerOn(){
		printf("正在开机……\n");
		memory->selfCheck();
		cpu->run();
		hardDisk->read();
		os->load();
		printf("开机完成！\n");
	}
private:
	Memory *memory;
	CPU *cpu;
	HardDisk *hardDisk;
	OS *os;
};

#endif //__FACADE_PATTERN_H__