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
	system("pause");
	return 0;
}