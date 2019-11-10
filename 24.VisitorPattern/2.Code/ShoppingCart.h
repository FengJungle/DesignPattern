#ifndef __SHOPPINGCART_H__
#define __SHOPPINGCART_H__

#include "Element.h"
#include "Visitor.h"
#include <vector>

class ShoppingCart
{
public:
	ShoppingCart(){}
	void addElement(Element* element){
		printf("  商品名：%s, \t数量：%d, \t加入购物车成功！\n", element->getName().c_str(), element->getNum());
		elementList.push_back(element);
	}
	void accept(Visitor* visitor){
		for (int i = 0; i < elementList.size(); i++){
			elementList[i]->accept(visitor);
		}
	}
private:
	vector<Element*>elementList;
};

#endif 