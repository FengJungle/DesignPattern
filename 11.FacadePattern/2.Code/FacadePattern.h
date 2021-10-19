#ifndef __FACADE_PATTERN_H__
#define __FACADE_PATTERN_H__

#include <stdio.h>

// subsystem: Memory
class Memory
{
public:
	Memory(){}
	void selfCheck(){
		printf("memory selfchecking......\n");
	}
};

// subsystem: CPU
class CPU
{
public:
	CPU(){}
	void run(){
		printf("running cpu......\n");
	}
};

// subsystem: hardDisk
class HardDisk
{
public:
	HardDisk(){}
	void read(){
		printf("reading hardDisk......\n");
	}
};

// subsystem: OS
class OS
{
public:
	OS(){}
	void load(){
		printf("loading os.....\n");
	}
};

class Facade
{
public:
	Facade(){
		memory = new Memory();
		cpu = new CPU();
		hardDisk = new HardDisk();
		os = new OS();
	}
	~Facade(){
		delete memory;
		delete cpu;
		delete hardDisk;
		delete os;
		memory = nullptr;
		cpu = nullptr;
		hardDisk = nullptr;
		os = nullptr;
	}
	Facade(const Facade& facade) = delete;
	Facade operator=(const Facade& facade) = delete;
	void powerOn(){
		printf("power on……\n");
		memory->selfCheck();
		cpu->run();
		hardDisk->read();
		os->load();
		printf("ready!\n");
	}
private:
	Memory *memory;
	CPU *cpu;
	HardDisk *hardDisk;
	OS *os;
};

#endif //__FACADE_PATTERN_H__
