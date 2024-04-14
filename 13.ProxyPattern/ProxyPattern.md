# 双十一天猫购物找代理？先学会代理模式
```
“代理”这个词不陌生吧？买化妆品、买奶粉、买包包，都可以通过代理代购，甚至有专门的代购网站；
或者要购置一些自己不太清楚原理好坏的物品，可以找相关代理负责帮忙购买，当然了，得支付一定费用。
```
在软件设计模式中，也有一种模式可以提供与代购网站类似的功能。当客户端不能或者不便直接访问一个对象时，可以通过一个称为“代理”的第三方来间接访问，这样的设计模式称为代理模式。
## 1.代理模式简介
代理模式在软件设计中广泛应用，而且产生的变种很多，如远程代理、虚拟代理、缓冲代理、保护代理等。
```
代理模式：
给某一个对象提供一个代理或占位符，并由代理对象来控制对原对象的访问。
```
代理模式是一种对象结构型模式，在该模式中引入了一个代理对象，在客户端和目标访问对象之间起到中介的作用。代理对象可以屏蔽或删除客户不想访问的内容和服务，也可以根据客户需求增加新的内容和服务。 

## 2.代理模式结构
代理模式的关键是代理类（Proxy）。代理模式中引入了抽象层，客户端针对抽象层编程，这样使得客户端可以一致对待真实对象和代理对象。代理模式主要有**抽象主题角色（Subject）**、**代理主题角色（\(Proxy)**和**真实主题角色（RealSubject）**组成，其UML图如下：

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/13.ProxyPattern/1.Picture/%E4%BB%A3%E7%90%86%E6%A8%A1%E5%BC%8FUML%E5%9B%BE.png)

- **抽象主题角色（Subject）**：声明了代理主题角色和真实主题角色共同的一些接口，因此在任何可以使用真实主题对象的地方都可以使用代理主题角色（想一想代购是不是也是这样？），客户端通常针对抽象主题编程；
- **代理主题角色（Proxy）**：代理主题角色通过关联关系引用真实主题角色，因此可以控制和操纵真实主题对象；代理主题角色中提供一个与真实主题角色相同的接口（以在需要时代替真实主题角色），同时还可以在调用对真实主题对象的操作之前或之后增加新的服务和功能；
- **真实主题角色（RealSubject）**：真实主题角色是代理角色所代表的真实对象，提供真正的业务操作，客户端可以通过代理主题角色间接地调用真实主题角色中定义的操作。

在实际开发过程中，代理模式产生了很多类型：
- 远程代理（Remote Proxy）：为一个位于不同地址空间的对象提供一个本地的代理对象。不同的地址空间可以在相同或不同的主机中。
- 虚拟代理（Virtual Proxy）：当创建一个对象需要消耗大量资源时，可以先创建一个消耗较少资源的虚拟代理来表示，当真正需要时再创建。
- 保护代理（Protect Proxy）：给不同的用户提供不同的对象访问权限。
缓冲代理（Cache Proxy）：为某一个目标操作的结果提供临时存储空间，以使更多用户可以共享这些结果。
- 智能引用代理（Smart Reference Proxy）：当一个对象被引用时提供一些额外的操作，比如将对象被调用的次数记录下来等。

## 3.代理模式代码实例
在某应用软件中需要记录业务方法的调用日志，在不修改现有业务的基础上位每个类提供一个日志记录代理类，在代理类中输出日志，例如在业务方法method()调用之前输出“方法method()被调用，调用时间为2019-10-28 07:33:30”，调用之后输出“方法method()”调用成功。在代理类中调用真实业务类的业务方法，使用代理模式设计该日志记录模块的结构。

在这个案例中，真实主题角色是真实业务类，在代理类中调用真实主题角色的method()方法。该实例的UML图如下：

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/13.ProxyPattern/1.Picture/%E4%BB%A3%E7%90%86%E6%A8%A1%E5%BC%8F%E5%AE%9E%E4%BE%8BUML%E5%9B%BE.png)

### 3.1.抽象主题角色
声明抽象方法method():
```
// 抽象主题角色
class Subject
{
public:
	Subject(){}
    virtual ~Subject(){}
	virtual void method() = 0;
};
```
### 3.2.真实主题角色
实现具体业务方法method()：
```
// 真实主题角色
class RealSubject :public Subject
{
public:
	RealSubject(){}
	void method(){
		printf("调用业务方法\n");
	}
};
```
### 3.3.代理角色和Log类
```
// Log类
class Log
{
public:
	Log(){}
	string getTime(){
		time_t t = time(NULL);
		char ch[64] = { 0 };
		//年-月-日 时:分:秒
		strftime(ch, sizeof(ch)-1, "%Y-%m-%d %H:%M:%S", localtime(&t));     
		return ch;
	}
};
 
// 代理类
class Proxy:public Subject
{
public:
	Proxy(){
		realSubject = new RealSubject();
		log = new Log();
	}
	Proxy(const Proxy& o) = delete;
	Proxy& operator=(const Proxy&) = delete;
	~Proxy(){
		delete realSubject;
		delete log;
		realSubject = nullptr;
		log = nullptr;
	}
	void preCallMethod(){
		printf("方法method()被调用，调用时间为%s\n",log->getTime().c_str());
	}
	void method(){
		preCallMethod();
		realSubject->method();
		postCallMethod();
	}
	void postCallMethod(){
		printf("方法method()调用调用成功!\n");
	}
private:
	RealSubject *realSubject;
	Log* log;
};
```
### 3.4.客户端代码示例
```
#include <iostream>
#include "ProxyPattern.h"
 
int main()
{
	Subject *subject;
	subject = new Proxy();
	subject->method();
 
	printf("\n\n");
 
	delete subject;
	subject = nullptr;
 
	system("pause");
	return 0;
}
```
### 3.5.效果 
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/13.ProxyPattern/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE1.png)

## 4.总结
- 优点：
    - 代理模式能够协调调用者和被调用者，降低系统耦合度；
    - 客户端针对抽象主题角色编程，如果要增加或替换代理类，无需修改源代码，符合开闭原则，系统扩展性好；
    - 远程代理优点：为两个位于不同地址空间的对象的访问提供解决方案，可以将一些资源消耗较多的对象移至性能较好的计算机上，提高系统整体性能；
    - 虚拟代理优点：通过一个资源消耗较少的对象来代表一个消耗资源较多的对象，节省系统运行开销；
    - 缓冲代理优点：为某一个操作结果提供临时的存储空间，可以在后续操作中使用这些结果，缩短了执行时间；
    - 保护代理优点：:控制对一个对象的访问权限，为不同客户提供不同的访问权限。
- 缺点：
    - 增加了代理类和代理对象，增加了代理对象中的某些处理流程，可能会使得系统响应变慢；
    - 有的代理模式（如远程代理）实现代码较为复杂。
- 适用环境：
    - 当客户端对象需要访问远程主机中的对象——可以使用远程代理；
    - 当需要用一个资源消耗较少的对象来代表一个资源消耗较多的对象——虚拟代理；
    - 当需要限制不同用户对一个独享的访问权限——保护代理；
    - 当需要为一个频繁访问的操作结果提供临时存储空间——缓冲代理；
    - 当需要为一个对象的访问提供一些额外的操作——智能引用代理。
