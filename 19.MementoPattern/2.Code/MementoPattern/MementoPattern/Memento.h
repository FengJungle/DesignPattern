#ifndef __MEMENTO_H__
#define __MEMENTO_H__

class Memento
{
public:
	Memento(){}
	Memento(int iVersion, string iDate, string iLabel){
		version = iVersion;
		date = iDate;
		label = iLabel;
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
	int version;
	string date;
	string label;
};

#endif