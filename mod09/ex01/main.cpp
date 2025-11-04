# include "RPN.hpp"

int main(int ac, char** av){
	RPN r;

	if (ac == 2){
		std::string str = av[1];
		r = RPN(str);
		r.rpn();
	}
	else
		std::cout << "Error" << std::endl;

}