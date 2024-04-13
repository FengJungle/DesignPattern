# 代码还可以这么复用——适配器模式
```
你一定听过“网络适配器”吧？又叫网卡。它的作用是什么呢？——上网！
这样的回答显然不够专业，正确的答案是“网卡的一个重要功能就是要进行串行/并行转换。因为网卡和局域网之间的通信是通过电缆或双绞线以串行传输方式进行，而网卡和计算机之间通信则是通过计算机主板上的I/O总线以并行传输方式进行。”
你肯定要问：“这和我有什么关系？”
当然有了，因为你正在学习设计模式，而这就跟本文即将要介绍的适配器模式有关啦！
```
## 1.适配器模式简介
除了网卡适配器，你一定还听说过电源适配器吧？我国生活用电电压是220V，但我们的电脑、手机、平板、剃须刀（充电式）不会使用这么高的电压。这就需要电源适配器（充电器、变压器），使各个电子设备和220的供电电压兼容。电源适配器就充当了一个适配器的角色。

在软件系统设计中，**当需要组合使用的类不兼容时，也需要类似于变压器一样的适配器来协调这些不兼容者**，这就是适配器模式！

那么什么是适配器模式呢？
```
适配器模式：

将一个类的接口转换成客
户希望的另一个接口。适配器模式让那些接口不兼容的类可以一起工作。
```
与电源适配器类似，适配器模式中会设计一个叫做“**适配器**”的包装类，适配器包装的对象叫做**适配者**。根据定义，适配器是根据客户的需求，将适配者已有的接口转换成另一个接口，得以使不兼容的类可以协同工作。
## 2.适配器模式结构
适配器模式分为类适配器和对象适配器。

- 适配器类（Adapter）：适配器与适配者之间是继承或实现关系；
- 适配者类（Adaptee）：适配器与适配者之间是关联关系。
- 目标抽象类（Target）：定义客户所需要的接口。

类适配器和对象适配器的UML图如下。**类适配器中，适配器类通过继承适配者类**，并重新实现适配者的具体接口来达到适配客户所需要的接口的目的。**对象适配器中，适配器类通过在类中实例化一个适配者类的对象**，并将其封装在客户所需功能的接口里，达到最终的适配目的。
 
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/07.AdapterPattern/1.Picture/%E9%80%82%E9%85%8D%E5%99%A8%E6%A8%A1%E5%BC%8FUML%E5%9B%BE.png)

## 3.适配器模式代码实例
Jungle曾经在一个项目里多次使用了适配器模式。这里举个使用对象适配器模式的例子。

```
路径规划包括两个阶段：首先读取并解析工程图文件，得到其中的点、直线坐标；其次根据需求计算加工路径。软件控制器（Controller）上，系统点击“路径规划”按钮就自动完成上述过程。
Jungle已经封装好一个类DxfParser，该类可以读取后缀名为dxf的工程图文件，并解析其中的点、线，保存到路径列表里。另一个类PathPlanner用于计算加工路径。
```
这个例子中，Controller就是目标抽象类，DxfParser和PathPlanner是适配者类，这两个类提供的方法可以用于实现路径规划的需求。我们只需再定义一个适配器类Adapter即可

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/07.AdapterPattern/1.Picture/UML%E5%AE%9E%E4%BE%8B%E5%9B%BE.png)

### 3.1.目标抽象类
```
// 目标抽象类
class Controller
{
public:
	Controller(){}
	virtual ~Controller(){}
	virtual void pathPlanning() = 0;
private:
};
```
### 3.2.适配者类
```
// 适配者类DxfParser
class DxfParser
{
public:
	DxfParser(){}
	void parseFile(){
		printf("Parse dxf file\n");
	}
};
 
// 适配者类PathPlanner
class PathPlanner
{
public:
	PathPlanner(){}
	void calculate(){
		printf("calculate path\n");
	}
};
```
### 3.3.适配器类
```
// 适配器类Adapter
class Adapter:public Controller
{
public:
	Adapter(){
		dxfParser = new DxfParser();
		pathPlanner = new PathPlanner();
	}
	~Adapter(){
		delete dxfParser;
		delete pathPlanner;
	}
	Adapter(const Adapter& other) = delete;
	Adapter& operator=(const Adapter& ) = delete;
	void pathPlanning(){
		printf("pathPlanning\n");
		dxfParser->parseFile();
		pathPlanner->calculate();
	}
private:
	DxfParser   *dxfParser;
	PathPlanner *pathPlanner;
};
```
### 3.4.客户端代码示例
```
#include <iostream>
#include "AdapterPattern.h"
 
int main()
{
	Controller *controller = new Adapter();
	controller->pathPlanning();
 
	system("pause");
	delete controller;
	return 0;
}
```
### 3.5.效果
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/07.AdapterPattern/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE1.png)
## 4.适配器模式总结
- 优点：
    - 将目标类和适配者类解耦，引入一个适配器类实现代码重用，无需修改原有结构；
    - 增加类的透明和复用，对于客户端而言，适配者类是透明的；
    - 对象适配器可以把不同适配者适配到同一个目标（对象适配器）；
- 缺点：
    - 对编程语言的限制：Java不支持多重继承，一次最多只能适配一个适配者类，不能同时适配多个适配者类；
- 适用环境： 
    - 系统需要使用一些现有的类，但这些类的接口不符合系统需要，或者没有这些类的源代码；
    - 想创建一个重复使用的类，用于和一些彼此没有太大关联的类一起工作。