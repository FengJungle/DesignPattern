#include <iostream>
#include "ProxyPattern.h"

int main()
{
	Subject *subject;
	subject = new Proxy();
	subject->method();

	printf("\n\n");

	delete subject;

	system("pause");
	return 0;
}