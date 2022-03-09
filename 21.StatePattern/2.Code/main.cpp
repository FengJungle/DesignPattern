#include "GameAccount.h"
#include "Level.h"

int main()
{
	GameAccount *jungle = new GameAccount("Jungle");

	for (int i = 0; i < 5; i++){
		printf("%d \n", i + 1);
		jungle->playCard();
	}

	printf("\n\n");
	system("pause");

	delete jungle;
	jungle = nullptr;
	
	return 0;
}