#include <iostream>
#include "DecoratorPattern.h"

int main()
{
	printf("\nJungle的第一个手机：\n");
	Component *c;
	Component *com_Shell;
	c = new Phone();
	com_Shell = new DecoratorShell(c);
	com_Shell->operation();

	printf("\nJungle的第二个手机：\n");
	Component *c2;
	Component *com_Shell2;
	c2 = new Phone();
	com_Shell2 = new DecoratorShell(c2);
	Component *com_Sticker;
	com_Sticker = new DecoratorSticker(com_Shell2);
	com_Sticker->operation();

	printf("\nJungle的第三个手机：\n");
	Component *c3;
	Component *com_Shell3;
	c3 = new Phone();
	com_Shell3 = new DecoratorShell(c3);
	Component *com_Sticker2;
	com_Sticker2 = new DecoratorSticker(com_Shell3);
	Component *com_Rope;
	com_Rope = new DecoratorRope(com_Sticker2);
	com_Rope->operation();

	printf("\n\n");

	system("pause");
	return 0;
}