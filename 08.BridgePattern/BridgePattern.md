# 号称最难理解的设计模式，只需看这篇解析——桥接模式
```
Jungle有两个手机，分别是M手机和N手机，M手机上有游戏Game1，N手机上有Game2。每次Jungle想玩Game1时，就使用M手机，想玩Game2时，就玩N手机。要是某天Jungle外出，心情大好，两个游戏都想玩，那Jungle还得带上两个手机？？？麻不麻烦？
如果新出一个游戏Game3，那Jungle是不是要再买一个手机呢？
同样都是游戏软件，为什么不把所有游戏都装到一个手机上
```
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/08.BridgePattern/1.Picture/%E6%A1%A5%E6%8E%A5%E6%A8%A1%E5%BC%8F%E4%B8%BE%E4%BE%8B%E5%9B%BE.png)

## 1.桥接模式简介
如果系统中的某个类存在两个独立变化的维度，通过桥接模式可以将这两个维度分离开来，使两者独立扩展。如同上述实例，Jungle想用手机玩游戏，手机和游戏是两个独立变化的维度，增加一个游戏对手机没有影响，增加一个手机对游戏也没有影响。**手机上可以安装游戏，而游戏必须在手机上玩，从这个角度而言，手机和游戏之间存在较强的耦合**。

但两者可以很好的解耦，且解耦后扩展灵活：所有游戏安装在一个手机上，新出一个游戏，新安装就ok！买了新手机，同样可以装上所有游戏。这就是桥接模式：
```
桥接模式：

将抽象部分与它的实现部分解耦，使得两者都能够独立变化。
```

**桥接模式将两个独立变化的维度设计成两个独立的继承等级结构（而不会将两者耦合在一起形成多层继承结构），在抽象层将二者建立起一个抽象关联，该关联关系类似一座桥，将两个独立的等级结构连接起来**，故曰“桥接模式”。

## 2.桥接模式结构
桥接模式UML图如下图。由图可知，桥接模式包含以下角色：
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/08.BridgePattern/1.Picture/%E6%A1%A5%E6%8E%A5%E6%A8%A1%E5%BC%8FUML%E5%9B%BE.png)

- Abstraction（抽象类）：定义抽象类的接口（抽象接口），由聚合关系可知，抽象类中包含一个Implementor类型的对象，它与Implementor之间有关联关系，既可以包含抽象业务方法，也可以包含具体业务方法；
- Implementor（实现类接口）：定义实现类的接口，这个接口可以与Abstraction类的接口不同。一般而言，实现类接口只定义基本操作，而抽象类的接口还可能会做更多复杂的操作。
- RefinedAbstraction（扩充抽象类）：具体类，实现在抽象类中定义的接口，可以调用在Implementor中定义的方法；
ConcreteImplementor（具体实现类）：具体实现了Implementor接口，在不同的具体实现类中实现不同的具体操作。运行时ConcreteImplementor将替换父类。

简言之，在Abstraction类中维护一个Implementor类指针，需要采用不同的实现方式的时候只需要传入不同的Implementor派生类就可以了。

## 3.桥接模式代码实例
以引言中的故事为例，Jungle学习了桥接模式后大受启发，想实现如下操作：
```
新手机上能够迅速在新手机上安装（setup）并玩（play）游戏

新增加一个游戏时Jungle能够在已有手机上安装并play
```
在这个实例里，手机是**抽象类Abstraction**，具有玩游戏这样的**实现类接口Implementor**，不同的手机品牌**扩充抽象类RefinedAbstraction**，多个不同的游戏则是**具体实现类ConcreteImplementor**。

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/08.BridgePattern/1.Picture/UML%E5%AE%9E%E4%BE%8B%E5%9B%BE.png)

### 3.1.实现类
```
/抽象类Phone
class Phone
{
public:
	Phone(){
	}
	virtual ~Phone(){}
	// Setup game
	virtual void setupGame(Game *igame) = 0;
	virtual void play() = 0;
private:
	Game *game;
};
 
// 扩充抽象类PhoneA
class PhoneA:public Phone 
{
public:
	PhoneA(){
	}
	// Setup game
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};
 
// 扩充抽象类PhoneB
class PhoneB :public Phone
{
public:
	PhoneB(){
	}
	// Setup game
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};
```
抽象类Phone中也声明了两个虚方法，并且定义了一个实现类的对象，使抽象和实现具有关联关系。而对象的实例化则放在客户端使用时进行。
### 3.3.客户端代码示例
```
#include <iostream>
#include "BridgePattern.h"
 
int main()
{
	Game *game;
	Phone *phone;
 
	// Jungle买了PhoneA品牌的手机，想玩游戏A
	phone = new PhoneA();
	game = new GameA();
	phone->setupGame(game);
	phone->play();
	printf("++++++++++++++++++++++++++++++++++\n");
 
	// Jungle想在这个手机上玩游戏B
	delete game;
	game = new GameB();
	phone->setupGame(game);
	phone->play();
 
	delete phone;
	delete game;
 
	system("pause");
	return 0;
}
```
### 3.4.效果
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/08.BridgePattern/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE1.png)
## 4.桥接模式总结
- 优点：
    - 分离抽象接口与实现部分，使用对象间的关联关系使抽象与实现解耦；
    - 桥接模式可以取代多层继承关系，多层继承违背单一职责原则，不利于代码复用；
    - 桥接模式提高了系统可扩展性，某个维度需要扩展只需增加实现类接口或者具体实现类，而且不影响另一个维度，符合开闭原则。
- 缺点：
    - 桥接模式难以理解，因为关联关系建立在抽象层，需要一开始就设计抽象层；
    - 如何准确识别系统中的两个维度是应用桥接模式的难点。
- 适用场景： 
    - 如果一个系统需要在抽象化和具体化之间增加灵活性，避免在两个层次之间增加继承关系，可以使用桥接模式在抽象层建立关联关系；
    - 抽象部分和实现部分可以各自扩展而互不影响；
    - 一个类存在多个独立变化的维度，可采用桥接模式。