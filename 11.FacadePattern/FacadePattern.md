# 如何吃到回锅肉？找厨师啊——外观模式实例解析
```
好不容易盼到周末啦！Jungle想吃点好的犒劳自己！吃什么呢？回锅肉！是的，吃回锅肉！
可是这过程好麻烦啊，先得去市场里买肉，买回来得洗好，然后切好，再炒肉，最后才能吃上！不仅过程繁杂，而且Jungle还得跟市场、厨房打交道，想想都头大。
如果有个厨师就好了，Jungle直接告诉厨师“我要吃回锅肉”，20分钟后厨师直接端上来就开吃。而中间那些买肉洗肉切肉的过程Jungle统统不关心了，而且Jungle也不必再关心市场和厨房，直接和厨师说句话就ok！真是方便！
```
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/11.FacadePattern/1.Picture/%E5%A4%96%E8%A7%82%E6%A8%A1%E5%BC%8F%E4%B8%BE%E4%BE%8B%E5%9B%BE.png)

在这个例子中，厨师整合了一系列复杂的过程，外界（Jungle）只需与厨师交互即可。在软件设计模式中，有一类设计模式正式如此——外观模式。

## 1.外观模式简介
外观模式是一种使用频率较高的设计模式，它提供一个外观角色封装多个复杂的子系统，简化客户端与子系统之间的交互，方便客户端使用。外观模式可以降低系统的耦合度。如果没有外观类，不同的客户端在需要和多个不同的子系统交互，系统中将存在复杂的引用关系，如下图。引入了外观类，原有的复杂的引用关系都由外观类实现，不同的客户端只需要与外观类交互。

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/11.FacadePattern/1.Picture/%E5%A4%96%E8%A7%82%E6%A8%A1%E5%BC%8F%E8%80%A6%E5%90%88%E5%BA%A6%E5%9B%BE.png)

```
外观模式：
为子系统中的一组接口提供一个统一的入口。外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。
```

外观模式的应用很多，比如浏览器，用户要查找什么东西，不论是浏览知乎、腾讯或者CSDN，用户都只需要打开浏览器即可，剩下的搜索工作由浏览器完成。

## 2.外观模式结构
外观模式的UML结构图如下所示：  
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/11.FacadePattern/1.Picture/%E5%A4%96%E8%A7%82%E6%A8%A1%E5%BC%8F.png)

外观模式一共有以下角色：

- **Facade（外观角色）**：外观角色可以知道多个相关子系统的功能，它将所有从客户端发来的请求委派给相应的子系统，传递给相应的子系统处理。
- **SubSystem（子系统角色）**：子系统是一个类，或者由多个类组成的类的集合，它实现子系统具体的功能。 

## 3.外观模式代码实例
电脑主机（Mainframe）中只需要按下主机的开机按钮（powerOn），即可调用其他硬件设备和软件的启动方法，如内存（Memory）的自检（selfCheck）、CPU的运行（run）、硬盘（HardDisk）的读取（read）、操作系统（OS）的载入（load）等。如果某一过程发生错误则电脑开机失败。

这里Jungle用外观模式来模拟该过程，该例子UML图如下：
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/11.FacadePattern/1.Picture/%E5%A4%96%E8%A7%82%E6%A8%A1%E5%BC%8F%E5%AE%9E%E4%BE%8BUML%E5%9B%BE.png)

### 3.1.子系统类
本例中一共有4个子系统，因此设计4个类：Memory、CPU、HardDisk和OS，并且每个子系统都有自己独立的流程。
```
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
```
### 3.2.外观类设计
```
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
```
### 3.3.客户端代码示例
```
#include <iostream>
#include "FacadePattern.h"
 
int main()
{
	Facade *facade = new Facade();
	facade->powerOn();
 
	printf("\n\n");
	delete facade;
	system("pause");
	return 0;
}
```
看到了吗，客户端的代码就是如此简单，跟子系统无关！ 

### 3.4.效果
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/11.FacadePattern/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE1.png)

## 4.总结
- 优点：
    - 外观模式使得客户端不必关心子系统组件，减少了与客户端交互的对象的数量，简化了客户端的编程；
    - 外观模式可以大大降低系统的耦合度；
    - 子系统的变化并不需要修改客户端，只需要适当修改外观类即可；
    - 子系统之间不会相互影响。
- 缺点：
    - 如果需要增加或者减少子系统，需要修改外观类，违反开闭原则；
    - 并不能限制客户端直接与子系统交互，但如果加强限制，又使得系统灵活度降低。
- 适用场景：
    - 为访问一系列复杂的子系统提供一个统一的、简单的入口，可以使用外观模式；
    - 客户端与多个子系统之间存在很大依赖，但在客户端编程，又会增加系统耦合度，且使客户端编程复杂，可以使用外观模式。
