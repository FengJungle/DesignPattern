#include "Context.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Context* ctx = new Context();
	int arr[] = { 10, 23, -1, 0, 300, 87, 28, 77, -32, 2 };
	ctx->setInput(arr, sizeof(arr)/sizeof(int));
	printf("input:");
	ctx->print();

	// BubbleSort
	ctx->setSortStrategy(new BubbleSort());
	ctx->sort();

	// SelectionSort
	ctx->setSortStrategy(new SelectionSort());
	ctx->sort();

	// InsertSort
	ctx->setSortStrategy(new InsertSort());
	ctx->sort();

	printf("\n\n");
	system("pause");

	delete ctx;
	ctx = nullptr;

	return 0;
}