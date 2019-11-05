#include "Originator.h"

CodeVersion::CodeVersion(){
	version = 0;
	date    = "1900-01-01";
	label   = "none";
}

CodeVersion::CodeVersion(int iVersion, string iDate, string iLabel)
{
	version = iVersion;
	date    = iDate;
	label   = iLabel;
}

Memento* CodeVersion::commit(){
	return new Memento(this->version, this->date, this->label);
}


void CodeVersion::restore(Memento* memento){
	setVersion(memento->getVersion());
	setDate(memento->getDate());
	setLabel(memento->getLabel());
}

void CodeVersion::setVersion(int iVersion){
	version = iVersion;
}

int CodeVersion::getVersion(){
	return version;
}

void CodeVersion::setLabel(string iLabel){
	label = iLabel;
}

string CodeVersion::getLabel(){
	return label;
}

void CodeVersion::setDate(string iDate){
	date = iDate;
}

string CodeVersion::getDate(){
	return date;
}