#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat paul = Bureaucrat("paul", 1);
		std::cout << paul << std::endl;
		paul.up();
		std::cout << paul << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat pauline = Bureaucrat("pauline", 0);
		std::cout << pauline << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat lylian = Bureaucrat("Lylian", 150);
		std::cout << lylian << std::endl;
		lylian.down();
		std::cout << lylian << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat didier = Bureaucrat("dider", 2000);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
