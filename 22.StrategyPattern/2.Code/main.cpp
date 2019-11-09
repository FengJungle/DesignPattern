#include "Context.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Context* ctx = new Context();
	int arr[] = { 10, 23, -1, 0, 300, 87, 28, 77, -32, 2 };
	ctx->setInput(arr, sizeof(arr)/sizeof(int));
	printf("ÊäÈë£º");
	ctx->print();

	// Ã°ÅÝÅÅÐò
	ctx->setSortStrategy(new BubbleSort());
	ctx->sort();

	// Ñ¡ÔñÅÅÐò
	ctx->setSortStrategy(new SelectionSort());
	ctx->sort();

	// ²åÈëÅÅÐò
	ctx->setSortStrategy(new InsertSort());
	ctx->sort();

	printf("\n\n");
	system("pause");
	return 0;
}