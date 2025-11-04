#ifndef PMERGEME_H
# define PMERGEME_H

#include <vector>
#include <deque>
#include <iostream>
#include <cstdio>

class Pmergeme{
	private:
		std::deque<int> _tab;
		std::vector<int> _pend;
		std::vector<int> _main;
		std::vector<int> _oldmain;
		size_t _niv;
		void __sortPaire();
		int	findItA(int jbn);
		void _invert(std::deque<int> &tab, int a, int b, int c, int d);
		void _createPendMain();
		void _insertPendMain();
		int _insertMain(int jnb, int j, size_t niv);
		int _JacobsthalNb(int nb);
		void _display(size_t a, size_t b, size_t c, size_t d);
	public:
		Pmergeme();
		Pmergeme(const std::deque<int> &tab);
		Pmergeme(const Pmergeme& other);
		Pmergeme& operator=(const Pmergeme& other);
		~Pmergeme();
		void sort();
		void setNiv(size_t niv);
		void display();
		void displayMain();
		void displayPend();
};

#endif