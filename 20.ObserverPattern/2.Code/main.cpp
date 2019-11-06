#include "Observer.h"
#include "AllyCenter.h"

int main()
{
	// 创建一个战队
	AllyCenterController* controller = new AllyCenterController();

	// 创建4个玩家，并加入战队
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
	Player* Jianmengtu = new Player("贱萌兔");
	Player* SillyDog = new Player("傻子狗");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);

	printf("\n\n");

	// Jungle发现物资，呼叫队友
	Jungle->call(RESOURCE, controller);

	printf("\n\n");

	// 傻子狗遇到危险，求救队友
	SillyDog->call(HELP, controller);

	printf("\n\n");
	system("pause");
	return 0;
}