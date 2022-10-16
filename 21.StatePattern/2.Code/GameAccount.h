#ifndef __GAMEACCOUNT_H__
#define __GAMEACCOUNT_H__

using namespace std;
#include <iostream>
// 前向声明
class Level;

class GameAccount
{
public:
	GameAccount();
	GameAccount(string iName);
	GameAccount(const GameAccount&) = delete;
	GameAccount& operator=(const GameAccount&) = delete;
	~GameAccount();
	string getName();
	void win();
	void lose();
	void playCard();
	void setLevel(Level*);
	int getScore();
	void setScore(int);

private:
	Level* level;
	int score;
	string name;
};

#endif