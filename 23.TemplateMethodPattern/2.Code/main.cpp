#include "FingerprintModule.h"
#include <Windows.h>

int main()
{
	FingerprintModule *fp = new FingerprintModuleA();
	fp->algorithm();

	fp = new FingerprintModuleB();
	fp->algorithm();

	fp = new FingerprintModuleC();
	fp->algorithm();


	printf("\n\n");
	system("pause");
	return 0;
}