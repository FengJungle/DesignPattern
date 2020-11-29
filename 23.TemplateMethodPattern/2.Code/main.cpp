#include "FingerprintModule.h"
#include <Windows.h>

int main()
{
	FingerprintModule *fp = new FingerprintModuleA();
	fp->algorithm();
	delete fp;

	fp = new FingerprintModuleB();
	fp->algorithm();
	delete fp;

	fp = new FingerprintModuleC();
	fp->algorithm();
	delete fp;

	printf("\n\n");
	system("pause");

	return 0;
}