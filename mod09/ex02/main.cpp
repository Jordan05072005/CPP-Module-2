#include "PmergeMe.hpp"

int conv(char *s){
	return ((std::stoi(std::string(s))));
}

int main(int ac, char**av){
	std::deque<int> d;
	if (ac > 1){
		for (int i = 1; i < ac ;i++){
			d.push_back(conv(av[i]));
		}
		Pmergeme p = Pmergeme(d);
		p.sort();
	}

}