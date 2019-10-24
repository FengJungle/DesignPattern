#include <iostream>
#include "BridgePattern.h"

int main()
{
	Game *game;
	Phone *phone;

	//Jungle买了PhoneA品牌的手机，想玩游戏A
	phone = new PhoneA();
	game = new GameA();
	phone->setupGame(game);
	phone->play();
	printf("++++++++++++++++++++++++++++++++++\n");

	//Jungle想在这个手机上玩游戏B
	game = new GameB();
	phone->setupGame(game);
	phone->play();

	system("pause");
	return 0;
}