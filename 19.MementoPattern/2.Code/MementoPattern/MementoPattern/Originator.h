#ifndef __CODEVERSION_H__
#define __CODEVERSION_H__

#include <iostream>
using namespace std;

#include "Memento.h"

// 原生器：CodeVersion
class CodeVersion
{
public:
	CodeVersion(){
		version = 0;
		date = "1900-01-01";
		label = "none";
	}
	CodeVersion(int iVersion, string iDate, string iLabel){
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	// 保存代码
	Memento* save(){
		return new Memento(this->version, this->date, this->label);
	}
	// 回退版本
	void restore(Memento* memento){
		setVersion(memento->getVersion());
		setDate(memento->getDate());
		setLabel(memento->getLabel());
	}
	void setVersion(int iVersion){
		version = iVersion;
	}
	int getVersion(){
		return version;
	}
	void setLabel(string iLabel){
		label = iLabel;
	}
	string getLabel(){
		return label;
	}
	void setDate(string iDate){
		date = iDate;
	}
	string getDate(){
		return date;
	}
private:
	// 代码版本
	int version;
	// 代码提交日期
	string date;
	// 代码标签
	string label;
};

#endif