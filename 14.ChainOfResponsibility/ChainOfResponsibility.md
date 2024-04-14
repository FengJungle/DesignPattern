# “欲戴王冠，必承其重”——深度解析职责链模式
```
应项目需求，公司安排Jungle去成都出差一段时间。这不，Jungle刚结束出差生活，回到公司准备报销。算了一下，Jungle一共有大概50万的一笔小额票据需要报销。按照公司规定，Jungle得先去找自己的组长签字。
组长一看，“啧啧啧，我只能处理10万金额以下的报销，你这单子我签个字，你还得找兵哥（主管）签字”，于是Jungle又跑去找兵哥。
兵哥看了，“啧啧啧，我最多只能管金额不超过30万的单子，你得找春总（经理）签字”。Jungle又不厌其烦地找到了春总。
春总一看，“呵，50万，不少啊！但60万以下我都能做主，这单子我给你签了！要是超过60万，你这狗子还得去找老板！”Jungle总算松了一口气，一级一级网上找领导，也是不容易呀！
```
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/14.ChainOfResponsibility/1.Picture/%E8%81%8C%E8%B4%A3%E9%93%BE%E6%A8%A1%E5%BC%8F%E4%B8%BE%E4%BE%8B%E5%9B%BE.png)

在单位，每个领导都有不同的审批权限，不同额度的报销单层层上报，最终到有权处理该金额范围的领导手里，该单子才算审批完成。这是Jungle所在的公司（相信也是大部分公司）的制度。如果要用代码来模拟这种制度，有没有一种模式可以参考呢？

答案是：有！那就是职责链模式！ 

## 1.职责链模式简介
职责链模式又叫责任链模式。很多情况下，可以处理某个请求的对象可能不止一个，请求可以沿着某一条对象之间形成的关系一级一级由下家传递到上家，形成一条链——职责链。职责链可以是直线，也可以是环或树形结构。常见的职责链形式是直线。**链上的每一个对象都是请求的处理者，客户端要做的仅仅是发送请求，不需要关心请求的处理细节过程。由此，职责链模式将请求者和请求的接收者解耦**。

职责链模式定义如下：
```
职责链模式：
避免将一个请求的发送者和接收者耦合在一起，让多个对象都有机会处理请求。将接收请求的对象连接成一条链，并且沿着这条链传递请求，直到有一个对象能够处理它为止。
```
## 2.职责链模式结构
职责链模式的UML结构如下图所示，职责链模式的核心在于引入了一个抽象处理者：
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/14.ChainOfResponsibility/1.Picture/%E8%81%8C%E8%B4%A3%E9%93%BE%E6%A8%A1%E5%BC%8FUML%E5%9B%BE.png)

职责链模式中一共包含两个角色:

- **Handler（抽象处理者）**：抽象处理者一般为抽象类，声明了一个处理请求的接口handleRequest()，定义了一个抽象处理者类型的对象，作为其对下家的引用，通过该引用可以形成一条责任链。
- **ConcreteHandler（具体处理者）**： 是抽象处理者的子类，实现了处理请求的接口。在具体的实现中，如果该具体处理者能够处理该请求，就处理它，否则将该请求转发给后继者。具体处理者可以访问下一个对象。
由上述可知，在职责链模式中很多对象由每一个对象对其下家的引用连接起来形成一条链条，请求在这个链条上逐级传递，知道某一级能够处理这个请求为止。**客户端不知道也不必知道是哪一级处理者处理了该请求，因为每个处理者都有相同的接口handleRequest()**。接下来通过一个实例来进一步认识职责链模式。

## 3.职责链模式代码实例
以引言中的例子为例，对于不同金额的票据，公司不同级别的领导处理情况如下：
```
金额0~10万：组长可处理
金额10~30万：主管处理
金额30~60万：经理处理
金额超过60万：老板处理
```

本节Jungle将用C++模拟该过程。该实例UML图如下：  
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/14.ChainOfResponsibility/1.Picture/%E8%81%8C%E8%B4%A3%E9%93%BE%E6%A8%A1%E5%BC%8FUML%E5%AE%9E%E4%BE%8B%E5%9B%BE.png)

### 3.1.票据类
```
// 请求：票据
class Bill
{
public:
	Bill(){}
	Bill(int iId, string iName, double iAccount){
		id = iId;
		name = iName;
		account = iAccount;
	}
	double getAccount(){
		return this->account;
	}
	void print(){
		printf("\nID:\t%d\n", id);
		printf("Name:\t%s\n", name.c_str());
		printf("Account:\t%f\n", account);
	}
private:
	int id;
	string name;
	double account;
};
```
### 3.2.抽象处理者
```
// 抽象处理者
class Approver
{
public:
	Approver(){}
	Approver(string iName){
		setName(iName);
	}
	virtual ~Approver(){}
	// 添加上级
	void setSuperior(Approver *iSuperior){
		this->superior = iSuperior;
	}
	// 处理请求
	virtual void handleRequest(Bill*) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		name = iName;
	}
protected:
	Approver *superior;
private:
	string name;
};
```
### 3.3.具体处理者
#### 3.3.1.具体处理者：组长
```
// 具体处理者：组长
class GroupLeader :public Approver
{
public:
	GroupLeader(){}
	GroupLeader(string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		if (bill->getAccount() < 10){
			printf("组长 %s 处理了该票据，票据信息：",this->getName().c_str());
			bill->print();
		}
		else{
			printf("组长无权处理，转交上级……\n");
			this->superior->handleRequest(bill);
		}
	}
};
```
#### 3.3.2.具体处理者：主管
```
// 具体处理者：主管
class Head :public Approver
{
public:
	Head(){}
	Head(string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 10 && bill->getAccount()<30){
			printf("主管 %s 处理了该票据，票据信息：", this->getName().c_str());
			bill->print();
		}
		else{
			printf("主管无权处理，转交上级……\n");
			this->superior->handleRequest(bill);
		}
	}
};
```
#### 3.3.3.具体处理者：经理
```
// 具体处理者：经理
class Manager :public Approver
{
public:
	Manager(){}
	Manager(string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 30 && bill->getAccount()<60){
			printf("经理 %s 处理了该票据，票据信息：", this->getName().c_str());
			bill->print();
		}
		else{
			printf("经理无权处理，转交上级……\n");
			this->superior->handleRequest(bill);
		}
	}
};
```
#### 3.3.4.具体处理者：老板
```
// 具体处理者：老板
class Boss :public Approver
{
public:
	Boss(){}
	Boss(string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		printf("老板 %s 处理了该票据，票据信息：", this->getName().c_str());
		bill->print();
	}
};
```
### 3.5.客户端代码示例
客户端创建了四个角色，分别是组长、主管、经理和老板，并设置了上下级关系。然后创建了4张票据，金额不等，都先统一交给组长处理。
```
#include <iostream>
#include "ChainOfResponsibility.h"
 
int main()
{
	// 请求处理者：组长，兵哥，春总，老板
	Approver *zuzhang, *bingge, *chunzong, *laoban;
 
	zuzhang = new GroupLeader("孙大哥");
	bingge = new Head("兵哥");
	chunzong = new Manager("春总");
	laoban = new Boss("张老板");
 
	zuzhang->setSuperior(bingge);
	bingge->setSuperior(chunzong);
	chunzong->setSuperior(laoban);
 
	// 创建报销单
	Bill *bill1 = new Bill(1, "Jungle", 8); 
	Bill *bill2 = new Bill(2, "Lucy", 14.4);
	Bill *bill3 = new Bill(3, "Jack", 32.9);
	Bill *bill4 = new Bill(4, "Tom", 89);
 
	// 全部先交给组长审批
	zuzhang->handleRequest(bill1); printf("\n");
	zuzhang->handleRequest(bill2); printf("\n");
	zuzhang->handleRequest(bill3); printf("\n");
	zuzhang->handleRequest(bill4);
 
	printf("\n\n");
 
	delete zuzhang;
	delete bingge;
	delete chunzong;
	delete laoban;
	delete bill1;
	delete bill2;
	delete bill3;
	delete bill4;
 
	system("pause");
	return 0;
}
```
### 3.6.效果
运行结果如下图，可以看到，针对不同金额的票据，处理请求在不同职级之间层层上报，成功模拟了引言中的过程.

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/14.ChainOfResponsibility/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE1.png)

## 4.总结
- 优点：
    - 将请求的接收者和处理者解耦，客户端无需知道具体处理者，只针对抽象处理者编程，简化了客户端编程过程，降低系统耦合度；
    - 在系统中增加一个新的处理者时，只需要继承抽象处理者，重新实现handleRequest()接口，无需改动原有代码，符合开闭原则；
    - 给对象分配职责时，职责链模式赋予系统更多灵活性。
- 缺点：
    - 请求没有一个明确的接收者，有可能遇到请求无法响应的问题；
    - 比较长的职责链，其处理过程会很长。
    - 建立职责链的工作是在客户端进行，如果建立不当，可能导致循环调用或者调用失败。
- 适用环境：
    - 有多个对象处理同一个请求，具体由谁来处理是在运行时决定，客户端只需发出请求到职责链上，而无需关心具体是谁来处理；
    - 可动态指定一组对象处理请求，客户端可以动态创建职责链来处理请求，还可以改变职责链中各个处理者之间的上下级关系。

