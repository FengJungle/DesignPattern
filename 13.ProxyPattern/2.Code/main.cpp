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
