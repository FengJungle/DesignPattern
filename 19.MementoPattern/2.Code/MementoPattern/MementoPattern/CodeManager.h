#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__

#include "Memento.h"
#include <vector>
using namespace std;

// 管理者
class CodeManager
{
public:
	CodeManager(){}
	void commit(Memento* m){
		printf("提交：版本-%d, 日期-%s, 标签-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		mementoList.push_back(m);
	}
	// 切换到指定的版本，即回退到指定版本
	Memento* switchToPointedVersion(int index){
		mementoList.erase(mementoList.begin() + mementoList.size() - index, mementoList.end());
		return mementoList[mementoList.size() - 1];
	}
	// 打印历史版本
	void codeLog(){
		for (int i = 0; i < mementoList.size(); i++){
			printf("[%d]：版本-%d, 日期-%s, 标签-%s\n", i, mementoList[i]->getVersion(),
				mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
		}
	}
private:
	vector<Memento*> mementoList;
};

#endif