#include "FingerprintModule.h"
#include <Windows.h>

int main()
{
	FingerprintModule *fp = new FingerprintModuleA();
	fp->algorithm();
	delete fp;
	fp = nullptr;

	fp = new FingerprintModuleB();
	fp->algorithm();
	delete fp;
	fp = nullptr;

	fp = new FingerprintModuleC();
	fp->algorithm();
	delete fp;
	fp = nullptr;

	printf("\n\n");
	system("pause");

	return 0;
}