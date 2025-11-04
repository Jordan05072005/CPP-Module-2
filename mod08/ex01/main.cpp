#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try{
		sp.addNumber(11);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	Span vect = Span(10002);
	std::vector<int> v;

	vect.addNumber(0); // 110
	vect.addNumber(120000000); // 111
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	std::cout << v.size() << std::endl;
	vect.addNumber(v);
	std::cout << vect.shortestSpan() << std::endl;
	std::cout << vect.longestSpan() << std::endl;
	return 0;
}
