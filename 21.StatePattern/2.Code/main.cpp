#include "GameAccount.h"
#include "Level.h"

int main()
{
	GameAccount *jungle = new GameAccount("Jungle");

	for (int i = 0; i < 5; i++){
		printf("µÚ%d¾Ö£º\n", i + 1);
		jungle->playCard();
	}

	printf("\n\n");
	system("pause");
	return 0;
}