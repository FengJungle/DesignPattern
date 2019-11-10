#include "Element.h"

/*****        Apple        *******/
Apple::Apple(){
	setPrice(0);
	setNum(0);
	setName("");
}
Apple::Apple(string name, int price){
	setPrice(price);
	setNum(0);
	setName(name);
}

void Apple::accept(Visitor* visitor){
	visitor->visit(this);
}

/*****        Book        *******/
Book::Book(){
	setPrice(0);
	setNum(0);
	setName("");
}

Book::Book(string iName, int iPrice){
	setPrice(iPrice);
	setNum(0);
	setName(iName);
}

void Book::accept(Visitor* visitor){
	visitor->visit(this);
}