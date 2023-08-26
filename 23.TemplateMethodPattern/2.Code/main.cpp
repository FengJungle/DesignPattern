#include "FingerprintModule.h"

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

	return 0;
}