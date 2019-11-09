#ifndef __GAMEACCOUNT_H__
#define __GAMEACCOUNT_H__

using namespace std;
#include <iostream>
// Ç°ÏòÉùÃ÷
class Level;

class GameAccount
{
public:
	GameAccount();
	GameAccount(string iName);
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
