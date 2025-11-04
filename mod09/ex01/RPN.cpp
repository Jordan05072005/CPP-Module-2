#include "RPN.hpp"

RPN::RPN() : _rpn(""){}

RPN::RPN(std::string &rpn) : _rpn(rpn){}

RPN::RPN(const RPN &other){
	*this = other;
}

RPN& RPN::operator=(const RPN &other){
	if (this != &other){
		this->_rpn = other._rpn;
	}
	return (*this);
}

RPN::~RPN(){}

static int isoperator(char s){
	if (s == '+' || s == '-' || s == '*' || s == '/')
		return 1;
	return 0;
}

static int check_error(std::string &s){
	if (s.empty())
		return 1;
	for (long unsigned int i = 0; i < s.size(); i++){
		if (!isdigit(s[i]) && !isoperator(s[i]) && s[i] != 32)
			return (1);
	}
	return (0);
}

static int add(std::stack<int> &p){
	int a;
	int b;

	if (p.size() < 2)
		return 1;
	b = p.top();
	p.pop();
	a = p.top();
	p.pop();
	p.push(a + b);
	return 0;
}

static int del(std::stack<int> &p){
	int a;
	int b;

	if (p.size() < 2)
		return 1;
	b = p.top();
	p.pop();
	a = p.top();
	p.pop();
	p.push(a - b);
	return 0;
}

static int multi(std::stack<int> &p){
	int a;
	int b;

	if (p.size() < 2)
		return 1;
	b = p.top();
	p.pop();
	a = p.top();
	p.pop();
	p.push(a * b);
	return 0;
}

static int divi(std::stack<int> &p){
	int a;
	int b;

	if (p.size() < 2)
		return 1;
	b = p.top();
	p.pop();
	a = p.top();
	p.pop();
	if (b == 0)
		return 1;
	p.push(a / b);
	return 0;
}

void RPN::rpn(){
	int err = 0;
	if (check_error(this->_rpn))
		std::cout << "Error" << std::endl;
	else{
		for (long unsigned int i = 0; i < this->_rpn.size(); i++){
			if (this->_rpn[i] == 32)
				continue;
			else if (isdigit(this->_rpn[i]))
				this->_pile.push(this->_rpn[i] - 48);
			else{
				switch (this->_rpn[i]){
					case '+':
						err = add(this->_pile);
						break;
					case '-':
						err = del(this->_pile);
						break;
					case '*':
						err = multi(this->_pile);
						break;
					case '/':
						err = divi(this->_pile);
						break;
					default:
						err = 1;
				}
			}
			if (err){
				std::cout << "Error" << std::endl;
				return ;
			}
		}
		std::cout << this->_pile.top() << std::endl;
	}
}