	#include "easyfind.hpp"
	#include "easyfind.tpp"



	int main(){
		std::array<int, 5> tab = {1 ,23 ,254, 78, 7};
		std::array<char, 5> tab1 = {'4' ,'t' , 'e', 'j', 'g'};

		std::cout << *easyfind(tab, 1) << std::endl;
		std::cout << easyfind(tab, 1) << std::endl;
		try{
			std::cout << *easyfind(tab1, 1) << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}