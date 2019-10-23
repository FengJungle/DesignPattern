#ifndef __BRIDGE_PATTERN_H__
#define __BRIDGE_PATTERN_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

//实现类接口
class Game
{
public:
	Game(){}
	virtual void play() = 0;
private:
};

//具体实现类GameA
class GameA:public Game
{
public:
	GameA(){}
	void play(){
		printf("Jungle玩游戏A\n");
	}
};

//具体实现类GameB
class GameB :public Game
{
public:
	GameB(){}
	void play(){
		printf("Jungle玩游戏B\n");
	}
};

//抽象类Phone
class Phone
{
public:
	Phone(){
	}
	//安装游戏
	virtual void setupGame(Game *igame) = 0;
	virtual void play() = 0;
private:
	Game *game;
};

//扩充抽象类PhoneA
class PhoneA:public Phone 
{
public:
	PhoneA(){
	}
	//安装游戏
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};

//扩充抽象类PhoneB
class PhoneB :public Phone
{
public:
	PhoneB(){
	}
	//安装游戏
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};


#endif //__BRIDGE_PATTERN_H__