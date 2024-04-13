# 逆袭成为主管和高级经理——组合模式
```
今天Jungle又是被压榨的一天：
同事让帮忙做个测试，一测就是一上午；主管叫去开会，尽管他是三级主管，但也是Jungle的主管呀！更磨人的在后头：
Jungle由于项目需要，要申请某个IT权限，需要三级主管、二级主管、成都区总经理层层批复……
这公司哟，简直就像一棵树，Jungle只是一片绿叶，绿叶前面有树枝，树枝前面还有树枝，直到树的躯干……Jungle何时才能成为大树枝呢？
```
这一幕，相信大家都感同身受吧！整个公司的组织结构就像是一个树形结构，公司分成几个区，每个区分成几个产品部门，一个产品部门又会分成几个组，组里可能还会有细分，分到最后，就是类似于Jungle这样的小喽喽了。

看到了吗？这就是组合模式的典型应用场景！什么是组合模式呢？且听Jungle一一道来。

## 1.组合模式简介
组合模式关注包含叶子节点和容器节点的结构以及他们构成的组织形式。这样的组织形式的特点在于：叶子节点不再包含成员对象，而容器节点可以包含成员对象，这些对象可以是叶子节点，也可以是容器节点。这些节点通过不同的**递归组合**形成一个树形结构。好比**Windows系统的目录结构，文件夹里包含文件和子文件夹，子文件夹里还可以包含文件和文件夹**

![avatar](https://github.com/FengJungle/DesignPattern/blob/master/09.CompositePattern/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE1.png)

组合模式为叶子节点和容器节点提供了公共的抽象构建类，客户端无需关心所操作的对象是叶子节点还是容器节点，只需针对抽象构建类编程处理即可。
```
组合模式定义：

组合多个对象形成树形结构以表示具有部分-整体关系的层次结构。组合模式让客户端可以统一对待单个对象和组合对象。
```
## 2.组合模式结构
组合模式结构图如下图：
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/09.CompositePattern/1.Picture/%E7%BB%84%E5%90%88%E6%A8%A1%E5%BC%8F.png)

结合引言及组合模式UML图可知组合模式有如下角色：

- Component（抽象构件）：Component是一个抽象类，定义了构件的一些公共接口，这些接口是管理或者访问它的子构件的方法（如果有子构件），具体的实现在叶子构件和容器构件中进行。
- - Leaf（叶子构件）：它代表树形结构中的叶子节点对象，叶子构件没有子节点，它实现了在抽象构件中定义的行为。对于抽象构件定义的管理子构件的方法，叶子构件可以通过抛出异常、提示错误等方式进行处理。
Composite（容器构件） ：容器构件一方面具体实现公共接口，另一方面通过聚合关系包含子构件，子构件可以是容器构件，也可以是叶子构件。
结合公司组织架构的例子，各个分级部门是容器构件，类似于Jungle的员工是叶子构件；结合Windows目录结构，文件夹是容器构件，可以包含子文件夹和文件，而文件则是叶子构件，不能再包含子构件。

### 2.1.透明组合模式
如UML图所示，组合模式分为透明组合模式和安全组合模式。在透明组合模式中，抽象构件Component声明了add、remove、getChild等所有管理和访问子构件的方法，不论是叶子构件还容器构件都具有相同的接口。**客户端在使用时可以一致地对待所有对象，即具体是叶子构件还是容器构件，对客户端而言是透明的，因为它们都暴露相同的接口**。

但是，叶子构件是没有子构件的，所有就没有add、remove和getChild方法的，所以必须在叶子构件的实现中提供相应的错误处理代码，否则代码会出错。

### 2.2.安全组合模式
在安全组合模式中，抽象构件Component没有声明任何管理和访问子构件的方法，在具体的实现类中才去定义这些行为。之所以叫“安全”，是因为叶子构件没有子构件，也就不必定义管理访问子构件的方法，对客户端而言，当它处理子构件时，不可能调用到类似透明组合模式中的子构件的add、remove等方法，因此也就不会出错。

**安全模式的不足在于不够透明，客户端使用时必须有区别的对待叶子构件和容器构件**。

## 3.组合模式代码实例
如下图，某个公司的组织结构分为总部、省级分部、市级分部和各个分部的行政办公室和教务办公室：   
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/09.CompositePattern/1.Picture/%E7%BB%84%E5%90%88%E6%A8%A1%E5%BC%8F%E5%AE%9E%E4%BE%8B%E5%9B%BE.png)

这是一个典型的树形结构，本例将采用透明这模式来实现上述结构。

### 3.1.抽象构件
```
// 抽象构件
class Component
{
public:
	Component(){}
	Component(string iName){
		this->name = iName;
	}
	virtual ~Component(){}
	// 增加一个部门或办公室
	virtual void add(Component*) = 0;
	// 撤销一个部门或办公室
	virtual void remove(Component*) = 0;
	//
	virtual Component* getChild(int) = 0;
	// 各部门操作
	virtual void operation() = 0;
	string getName(){
		return name;
	}
private:
	string name;
};
```
### 3.2.叶子构件
叶子构件定义了行政办公室和教务办公室，都集成自Office。
```
// 叶子构件：办公室
class Office :public Component
{
public:
	Office(string iName){
		this->name = iName;
	}
	Office(){}
	void add(Component* c){
		printf("not support!\n");
	}
	void remove(Component* c){
		printf("not support!\n");
	}
	Component* getChild(int i){
		printf("not support!\n");
		return NULL;
	}
private:
	string name;
};
 
// 叶子构件：行政办公室
class AdminOffice :public Office
{
public:
	AdminOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Administration Office:%s\n", name.c_str());
	}
private:
	string name;
};
 
// 叶子构件：教务办公室
class DeanOffice :public Office
{
public:
	DeanOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Dean Office:%s\n", name.c_str());
	}
private:
	string name;
};
```
### 3.3.容器构件
```
// 容器构件SubComponent
class SubComponent :public Component
{
public:
	SubComponent(string iName){
		this->name = iName;
	}
	void add(Component *c){
		componentList.push_back(c);
	}
	void remove(Component *c){
		for (int i = 0; i < componentList.size(); i++){
			if (componentList[i]->getName() == c->getName()){
				componentList.erase(componentList.begin() + i);
				break;
			}
		}
	}
	Component* getChild(int i){
		return (Component*)componentList[i];
	}
	void operation(){
		printf("%s\n", this->name.c_str());
		for (int i = 0; i < componentList.size(); i++){
			((Component*)componentList[i])->operation();
		}
	}
private:
	string name;
 
	// 构件列表
	vector<Component*>componentList;
};
```
### 3.4.客户端代码示例
```
#include <iostream>
#include "CompositePattern.h"
 
int main()
{
	Component *head, *sichuanBranch, *cdBranch, *myBranch, *office1, *office2, *office3,
		*office4, *office5, *office6, *office7, *office8;
 
	head = new SubComponent("总部");
	sichuanBranch = new SubComponent("四川分部");
	office1 = new AdminOffice("行政办公室");
	office2 = new DeanOffice("教务办公室");
	
 
	cdBranch = new SubComponent("成都分部");
	myBranch = new SubComponent("绵阳分部");
	office3 = new AdminOffice("行政办公室");
	office4 = new DeanOffice("教务办公室");
	
 
	office5 = new AdminOffice("行政办公室");
	office6 = new DeanOffice("教务办公室");
	
	office7 = new AdminOffice("行政办公室");
	office8 = new DeanOffice("教务办公室");
	
	cdBranch->add(office5);
	cdBranch->add(office6);
 
	myBranch->add(office7);
	myBranch->add(office8);
 
	sichuanBranch->add(office3);
	sichuanBranch->add(office4);
	sichuanBranch->add(cdBranch);
	sichuanBranch->add(myBranch);
 
	head->add(office1);
	head->add(office2);
	head->add(sichuanBranch);
	
	head->operation();
 
	system("pause");
 
	delete head;
	delete sichuanBranch;
	delete cdBranch;
	delete myBranch;
	delete office1;
	delete office2;
	delete office3;
	delete office4;
	delete office5;
	delete office6;
	delete office7;
	delete office8;
 
	head = nullptr;
	sichuanBranch = nullptr;
	cdBranch = nullptr;
	myBranch = nullptr;
	office1 = nullptr;
	office2 = nullptr;
	office3 = nullptr;
	office4 = nullptr;
	office5 = nullptr;
	office6 = nullptr;
	office7 = nullptr;
	office8 = nullptr;
 
	return 0;
}
```
### 3.5.效果
![avatar](https://github.com/FengJungle/DesignPattern/blob/master/09.CompositePattern/1.Picture/%E8%BF%90%E8%A1%8C%E5%9B%BE2.png)
## 4.组合模式总结
- 优点：
    - 清楚地定义分层次的复杂对象，表示出复杂对象的层次结构，让客户端忽略层次的差异；
    - 客户端可以一致地使用层次结构中各个层次的对象，而不必关心其具体构件的行为如何实现；
    - 在组合模式中增加新的叶子构件和容器构件非常方便，易于扩展，符合开闭原则；
    - 为树形结构的案例提供了解决方案。
- 缺点：
    - 子构件或容器构件的行为受限制，因为它们来自相同的抽象层。如果要定义某个容器或者某个叶子节点特有的方法，那么要求在运行时判断对象类型，增加了代码的复杂度。
- 适用场景：
    - 系统中需要用到树形结构；
    - 系统中能够分离出容器节点和叶子节点；
    - 具有整体和部门的层次结构中，能够通过某种方式忽略层次差异，使得客户端可以一致对待。
