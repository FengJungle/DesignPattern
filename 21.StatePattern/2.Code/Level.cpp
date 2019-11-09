#include "Level.h"

/***********     Level    *************/
Level::Level(){

}

void Level::playCard(){
	this->play();
	this->doubleScore();
	this->changeCards();
	this->peekCards();
}

void Level::play(){
	printf("\t使用基本技能,");
}

void Level::setGameAccount(GameAccount* iGameAccount){
	this->gameAccount = iGameAccount;
}

GameAccount* Level::getGameAccount(){
	return gameAccount;
}

/***********     Primary    *************/
Primary::Primary(){

}

Primary::Primary(GameAccount* iGameAccount){
	this->setGameAccount(iGameAccount);
}

Primary::Primary(Level* level){
	getGameAccount()->setLevel(level);
}

void Primary::doubleScore(){
	return;
}

void Primary::changeCards(){
	return;
}

void Primary::peekCards(){
	return;
}

void Primary::upgradeLevel(){
	if (this->getGameAccount()->getScore() > 150){
		this->getGameAccount()->setLevel(new Secondary(this));
		printf("\t升级！ 级别：SECONDARY\n\n");
	}
	else{
		printf("\n");
	}
}

/***********     Secondary    *************/
Secondary::Secondary(){

}

Secondary::Secondary(Level* level){
	this->setGameAccount(level->getGameAccount());
	getGameAccount()->setLevel(level);
}

void Secondary::doubleScore(){
	printf("使用胜利双倍积分技能");
}

void Secondary::changeCards(){
	return;
}

void Secondary::peekCards(){
	return;
}

void Secondary::upgradeLevel(){
	if (this->getGameAccount()->getScore() < 150){
		this->getGameAccount()->setLevel(new Primary(this));
		printf("\t降级！ 级别：PRIMARY\n\n");
	}
	else if (this->getGameAccount()->getScore() > 200){
		this->getGameAccount()->setLevel(new Professional(this));
		printf("\t升级！ 级别：PROFESSIONAL\n\n");
	}
}

/***********     Professional    *************/
Professional::Professional(){

}

Professional::Professional(Level* level){
	this->setGameAccount(level->getGameAccount());
	getGameAccount()->setLevel(level);
}

void Professional::doubleScore(){
	printf("使用胜利双倍积分技能,");
}

void Professional::changeCards(){
	printf("使用换牌技能");
}

void Professional::peekCards(){
	return;
}

void Professional::upgradeLevel(){
	if (this->getGameAccount()->getScore() < 200){
		this->getGameAccount()->setLevel(new Secondary(this));
		printf("\t降级！ 级别：SECONDARY\n\n");
	}
	else if (this->getGameAccount()->getScore() > 250){
		this->getGameAccount()->setLevel(new Final(this));
		printf("\t升级！ 级别：FINAL\n\n");
	}
}

/***********     Final    *************/
Final::Final(){

}

Final::Final(Level* level){
	this->setGameAccount(level->getGameAccount());
	getGameAccount()->setLevel(level);
}

void Final::doubleScore(){
	printf("使用胜利双倍积分技能,");
}

void Final::changeCards(){
	printf("使用换牌技能,");
}

void Final::peekCards(){
	printf("使用偷看卡牌技能");
}

void Final::upgradeLevel(){
	if (this->getGameAccount()->getScore() < 250){
		this->getGameAccount()->setLevel(new Professional(this));
		printf("\t降级！ 级别：PROFESSIONAL\n\n");
	}
	else{
		printf("\t%s 已经是最高级\n\n", this->getGameAccount()->getName().c_str());
	}
}