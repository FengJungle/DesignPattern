#include <iostream>
#include "InterpreterPattern.h"

int main()
{
	Handler *handler = new Handler();

	string input_1 = "1 and 1";
	string input_2 = "1 and 0";
	string input_3 = "0 and 1";
	string input_4 = "0 and 0";
	string input_5 = "0 or 0";
	string input_6 = "0 or 1";
	string input_7 = "1 or 0";
	string input_8 = "1 or 1";
	string input_9 = "1 and 0 or 1";
	string input_10 = "0 or 0 and 1";
	string input_11 = "1 or 1 and 1 and 0";
	string input_12 = "0 and 1 and 1 and 1";
	string input_13 = "0 and 1 and 1 and 1 or 1 or 0 and 1";
	handler->setInput(input_1); handler->handle();
	handler->setInput(input_2); handler->handle();
	handler->setInput(input_3); handler->handle();
	handler->setInput(input_4); handler->handle();
	handler->setInput(input_5); handler->handle();
	handler->setInput(input_6); handler->handle();
	handler->setInput(input_7); handler->handle();
	handler->setInput(input_8); handler->handle();
	handler->setInput(input_9); handler->handle();
	handler->setInput(input_10); handler->handle();
	handler->setInput(input_11); handler->handle();
	handler->setInput(input_12); handler->handle();
	handler->setInput(input_13); handler->handle();

	printf("\n\n");
	system("pause");
	return 0;
}