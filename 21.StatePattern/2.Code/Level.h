#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "GameAccount.h"

class Level
{
public :
	Level();
	// 声明方法
	void playCard();
	void play();
	virtual void doubleScore() = 0;
	virtual void changeCards() = 0;
	virtual void peekCards() = 0;
	// 升级
	virtual void upgradeLevel() = 0;
	GameAccount* getGameAccount();
	void setGameAccount(GameAccount* iGameAccount);
private:
	GameAccount* gameAccount;
};

class Primary;
class Secondary;
class Professional;
class Final;

class Primary :public Level
{
public:
	Primary();
	Primary(Level* level);
	Primary(GameAccount* ga);
	void doubleScore();
	void changeCards();
	void peekCards();
	// 升级
	void upgradeLevel();
};

class Secondary :public Level
{
public:
	Secondary();
	Secondary(Level* level);
	void doubleScore();
	void changeCards();
	void peekCards();
	// 升级
	void upgradeLevel();
};

class Professional :public Level
{
public:
	Professional();
	Professional(Level* level);
	void doubleScore();
	void changeCards();
	void peekCards();
	// 升级
	void upgradeLevel();
};

class Final :public Level
{
public:
	Final();
	Final(Level* level);
	void doubleScore();
	void changeCards();
	void peekCards();
	// 升级
	void upgradeLevel();
};

#endif