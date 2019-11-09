#include "GameAccount.h"
#include "Level.h"
#include <Windows.h>
#include <time.h>
#define  random(x) (rand()%x)

GameAccount::GameAccount(){
	printf("创立游戏角色，积分：100，级别：PRIMARY\n");
	score = 100;
	name = "none";
	setLevel(new Primary(this));
}

GameAccount::GameAccount(string iName){
	printf("创立游戏角色，积分：100，级别：PRIMARY\n");
	score = 100;
	name = iName;
	setLevel(new Primary(this));
}

void GameAccount::setLevel(Level* iLevel){
	this->level = iLevel;
}

string GameAccount::getName(){
	return name;
}

void GameAccount::playCard(){
	this->level->playCard();

	Sleep(100);
	srand((int)time(0));
	int res = random(2);
	if (res % 2 == 0){
		this->win();
	}
	else{
		this->lose();
	}

	this->level->upgradeLevel();
}

void GameAccount::win(){
	if (this->getScore() < 200){
		setScore(getScore() + 50);
	}
	else{
		setScore(getScore() + 100);
	}
	printf("\n\t胜利，最新积分为 %d\n", score);
}

void GameAccount::lose(){
	setScore(getScore() + 30);
	printf("\n\t输牌，最新积分为 %d\n", score);
}

int GameAccount::getScore(){
	return this->score;
}

void GameAccount::setScore(int iScore){
	this->score = iScore;
}