#include "AllyCenter.h"
#include "Observer.h"

/***********   AllyCenter    ****************/
AllyCenter::AllyCenter(){
	printf("大吉大利，今晚吃鸡!\n");
}

// 加入玩家
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		printf("玩家已满\n");
		return;
	}
	printf("玩家 %s 加入\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		printf("组队成功，不要怂，一起上！\n");
	}
}
// 移除玩家
void AllyCenter::remove(Observer* player){
	printf("玩家 %s 退出\n", player->getName().c_str());
	//playerList.remove(player);
}
/***********   AllyCenter    ****************/


/**********   AllyCenterController    *******/
AllyCenterController::AllyCenterController(){

}

// 实现通知方法
void AllyCenterController::notify(INFO_TYPE infoType, std::string name){
	switch (infoType){
	case RESOURCE:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->come();
			}
		}
		break;
	case HELP:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->help();
			}
		}
		break;
	default:
		printf("Nothing\n");
	}
}
/**********   AllyCenterController    *******/