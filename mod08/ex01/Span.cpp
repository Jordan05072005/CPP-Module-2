#include "Span.hpp"

Span::Span() : _N(0){}

Span::Span(unsigned int N) : _N(N){};

Span::Span(const Span &other){
	*this = other;
}

Span& Span::operator=(const Span &other){
	if (this != &other){
		this->_v = other._v;
		this->_N = other._N;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int n){
	if (this->_v.size() < this->_N){
		this->_v.push_back(n);
	}
	else{
		throw VectorFull();
	}
}

void Span::addNumber(std::vector<int> v2){
	if (this->_v.size() + v2.size() <= this->_N){
		this->_v.insert(this->_v.end(), v2.begin(), v2.end());
	}
	else{
		throw VectorFull();
	}
}

int Span::shortestSpan(){
	int min;
	std::vector<int> cpy;
	std::vector<int>::iterator	val1;
	std::vector<int>::iterator	val2;

	if (this->_v.size() < 2)
		throw VectorTooSmall();
	else{
		cpy = this->_v;
		min = std::abs(cpy[0] - cpy[1]);
		for (unsigned int i = 1; i < cpy.size() - 1; i++){
			if (std::abs(cpy[i] - cpy[i + 1]) < min)
				min = std::abs(cpy[i] - cpy[i + 1]);
		}
		return (min);
	}
}

int Span::longestSpan(){
	std::vector<int>::iterator	val1;
	std::vector<int>::iterator	val2;

	if (this->_v.size() < 2)
		throw VectorTooSmall();
	else{
		val1 = std::max_element(this->_v.begin(), this->_v.end());
		val2 = std::min_element(this->_v.begin(), this->_v.end());
		return (std::abs(*val1 - *val2));
	}
}
