#include "Visitor.h"
#include "Element.h"

/*****        Customer        *******/
Customer::Customer(){
	this->name = "";
}

Customer::Customer(string iName){
	this->name = iName;
}

void Customer::setNum(Apple* apple, int iNum){
	apple->setNum(iNum);
}
void Customer::setNum(Book* book, int iNum){
	book->setNum(iNum);
}

void Customer::visit(Apple* apple){
	int price = apple->getPrice();
	printf("  %s \t单价: \t%d 元/kg\n", apple->getName().c_str(), apple->getPrice());
}

void Customer::visit(Book* book){
	int price = book->getPrice();
	string name = book->getName();
	printf("  《%s》\t单价: \t%d 元/本\n", book->getName().c_str(), book->getPrice());
}

/*****        Cashier        *******/
Cashier::Cashier(){

}

void Cashier::visit(Apple* apple){
	string name = apple->getName();
	int price = apple->getPrice();
	int num = apple->getNum();
	int total = price*num;
	printf("  %s 总价： %d 元\n", name.c_str(), total);
}

void Cashier::visit(Book* book){
	int price = book->getPrice();
	string name = book->getName();
	int num = book->getNum();
	int total = price*num;
	printf("  《%s》 总价： %d 元\n", name.c_str(), total);
}