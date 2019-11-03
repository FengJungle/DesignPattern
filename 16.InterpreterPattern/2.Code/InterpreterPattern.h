#ifndef __INTERPRETOR_PATTERN_H__
#define __INTERPRETOR_PATTERN_H__

#include <vector>
using namespace std;

// 抽象表达式类
class AbstractNode
{
public:
	AbstractNode(){}
	// 声明抽象接口
	virtual char interpret() = 0;
};

// 终结符表达式：ValueNode
class ValueNode :public AbstractNode
{
public :
	ValueNode(){}
	ValueNode(int iValue){
		this->value = iValue;
	}
	// 实现解释操作
	char interpret(){
		return value;
	}
private:
	int value;
};

// 终结符表达式：OperationNode
class OperatorNode :public AbstractNode
{
public:
	OperatorNode(){}
	OperatorNode(string iOp){
		this->op = iOp;
	}
	// 实现解释操作
	char interpret(){
		if (op == "and"){
			return '&';
		}
		else if (op == "or"){
			return '|';
		}
		return 0;
	}
private:
	string op;
};

// 非终结符表达式：SentenceNode
class SentenceNode :public AbstractNode
{
public:
	SentenceNode(){}
	SentenceNode(AbstractNode *iLeftNode,
		AbstractNode *iRightNode, AbstractNode* iOperatorNode){
		this->leftNode = iLeftNode;
		this->rightNode = iRightNode;
		this->operatorNode = iOperatorNode;
	}
	char interpret(){
		if (operatorNode->interpret() == '&'){
			return leftNode->interpret()&rightNode->interpret();
		}
		else{
			return leftNode->interpret()|rightNode->interpret();
		}
		return 0;
	}
private:
	AbstractNode *leftNode;
	AbstractNode *rightNode;
	AbstractNode *operatorNode;
};

// 处理者
class Handler
{
public:
	Handler(){}
	void setInput(string iInput){
		this->input = iInput;
	}
	void handle(){
		AbstractNode      *left = NULL;
		AbstractNode     *right = NULL;
		AbstractNode        *op = NULL;
		AbstractNode  *sentence = NULL;
		string iInput = this->input;
		vector<string>inputList;
		char* inputCh = const_cast<char*>(iInput.c_str());
		char *token = strtok(inputCh, " ");
		while (token != NULL){
			inputList.push_back(token);
			token = strtok(NULL, " ");
		}
		for (int i = 0; i < inputList.size() - 2; i += 2){
			left = new ValueNode(*(inputList[i].c_str()));
			op = new OperatorNode(inputList[i + 1]);
			right = new ValueNode(*(inputList[i+2].c_str()));
			sentence = new SentenceNode(left, right, op);
			inputList[i + 2] = string(1, sentence->interpret());
		}
		string tmpRes = inputList[inputList.size() - 1];
		if (tmpRes == "1"){
			result = 1;
		}
		else if (tmpRes == "0"){
			result = 0;
		}
		else{
			result = -1;
		}
		this->output();
	}
	void output(){
		printf("%s = %d\n", input.c_str(), result);
	}
private:
	string input;
	char result;
};


#endif //__INTERPRETOR_PATTERN_H__