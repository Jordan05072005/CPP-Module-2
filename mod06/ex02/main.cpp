#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


Base * generate(void){
	int	rdm;
	srand(time(NULL));

	rdm = rand() % 3;
	if (rdm == 0)
		return (new A());
	else if (rdm == 1)
		return (new B());
	else if (rdm == 2)
		return (new C());
	return(nullptr);
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A with pointeur" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B with pointeur" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C with pointeur" << std::endl;
}

void identify(Base& p){
	try{
			A& ref = dynamic_cast<A&>(p);
			std::cout << "Type is A with ref" << std::endl;
	}
	catch(std::exception &e){}
	try{
			B& ref = dynamic_cast<B&>(p);
			std::cout << "Type is B with ref" << std::endl;
	}
	catch(std::exception &e){
		
	}
	try{
			C& ref = dynamic_cast<C&>(p);
			std::cout << "Type is C with ref" << std::endl;
	}
	catch(std::exception &e){
		
	}
}

int main(){
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	A test = A();
	identify(test);
	identify(&test);
}