#include <iostream>
#include "Array.hpp"
#include "Array.tpp"


int main(){
	Array<int> tab(5);
	Array<int> tab2;

	std::cout << tab[0] << " and size " << tab.size() << std::endl;
	tab[0] = 5;
	std::cout << tab[0] << " and size " << tab.size() << std::endl;

	std::cout << tab[4] << " and size " << tab.size() << std::endl;
	tab[4] = 565;
	std::cout << tab[4] << " and size " << tab.size() << std::endl;
	try{
		std::cout << tab[5] << " and size " << tab.size() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		tab[5] = 20;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}