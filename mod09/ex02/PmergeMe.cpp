#include "PmergeMe.hpp"

Pmergeme::Pmergeme() : _tab(){
	this->_niv = 2;
}

Pmergeme::Pmergeme(const std::deque<int> &tab){
	if (tab.size() >= 2)
		this->_niv = 2;
	else
		this->_niv = 1;
	this->_tab = tab;
}

Pmergeme::Pmergeme(const Pmergeme& other){
	*this = other;
}

Pmergeme& Pmergeme::operator=(const Pmergeme& other){
	if (this != &other){
		this->_tab = other._tab;
		this->_main = other._main;
		this->_pend = other._pend;
		this->_niv = other._niv;
	}
	return (*this);
}

Pmergeme::~Pmergeme(){}

void Pmergeme::setNiv(size_t niv){
	if (niv <= this->_tab.size())
		this->_niv = niv;
	//else err ?	
}

void Pmergeme::_invert(std::deque<int> &tab, int a, int b, int c, int d){
	int temp;
	int ta = a;
	int tc = c;

	if (d - c != b - a)
		return;

	_display(a, b, c, d);
	while (a <= b && c <= d){
		temp = tab[a];
		tab[a] = tab[c];
		tab[c] = temp;
		a++;
		c++;
	}
	_display(tc, d, ta, b);
}

void Pmergeme::__sortPaire(){
	int i;

	while (this->_niv <= this->_tab.size()){
		i = 0;
		while ((i + this->_niv) <= this->_tab.size()){
				if (this->_tab[i + this->_niv / 2 - 1] > this->_tab[i + this->_niv - 1])
					_invert(this->_tab, i, i + this->_niv / 2 - 1,  i + this->_niv / 2, i + this->_niv - 1);
			i += this->_niv;
		}
		this->_niv *= 2;
	}
	this->_niv /= 2;
}


void Pmergeme::_createPendMain(){
	size_t i;
	int	ab;

	i = 0;
	ab = 1;
	while ((i + this->_niv) <= this->_tab.size()){
		if (ab == 1 || ab % 2 == 0){
			for (size_t j = 0; j < this->_niv; j++){
				this->_main.insert(this->_main.end(), this->_tab[i++]);
			}
		}
		else{
			for (size_t j = 0; j < this->_niv; j++){
				this->_pend.insert(this->_pend.end(), this->_tab[i++]);
			}
		}
		ab++;
	}
	while (i < this->_tab.size())
		this->_pend.insert(this->_pend.end(), this->_tab[i++]);
	displayPend();
	displayMain();
}

int Pmergeme::_JacobsthalNb(int nb){
	if (nb <= 0)
		return 0;
	if (nb == 1)
		return 1;
	return (_JacobsthalNb(nb - 1) + 2 * _JacobsthalNb(nb - 2));
}

int Pmergeme::findItA(int jbn){
	 int element;
	int newIt;
	int j;
	
	j = (this->_niv * jbn) - 1;
	while (j > (int)this->_oldmain.size() - 1)
		j--;
	element = this->_oldmain[(this->_niv * jbn) - 1];
	for (size_t i = 0; i < this->_main.size(); i++){
		if (this->_main[i] == element){ newIt = i;
			break;
		} 
	} 
	return (newIt);
}

int Pmergeme::_insertMain(int jnb, int j, size_t niv){ // j -> index de end bj
	int end = 0;
	int i = this->findItA(jnb);
	if (i > static_cast<int>(this->_main.size())){
		i = this->_main.size() - 1;
		end = 1;
	}
	while (1){
		if (this->_main[i] < this->_pend[j]){
			for (size_t x = 0; x < niv; x++){
				this->_main.insert(this->_main.begin() + (i + (1)) , this->_pend[j - x]);
			}
			return(end);
		}
		if (i <= 0){
			for (size_t x = 0; x < niv; x++){
				this->_main.insert(this->_main.begin(), this->_pend[j - x]);
			}
			return(end);
		}
		i -= niv;
	}
	return (end);
}

void Pmergeme::_insertPendMain(){
	size_t jacobsthal_nb = 3;
	size_t jacobsthal;
	int i = 0;
	size_t base = 1;
	size_t end = 0;
	if (this->_pend.empty())
		return;
	while (end < this->_pend.size()){
		jacobsthal = _JacobsthalNb(jacobsthal_nb);
		while (base < jacobsthal){
			if (this->_pend.size() - end < this->_niv){
				this->_main.insert(this->_main.end(), this->_pend.end() - (this->_pend.size() - end), this->_pend.end());
				return;
			}
			if (jacobsthal <= ((this->_pend.size() / this->_niv) + 1)){
				i = this->_niv * (jacobsthal - 1);
				_insertMain(jacobsthal, i - 1, this->_niv);
				end += this->_niv;
			}
			i -= 1;
			jacobsthal--;
		}
		base = _JacobsthalNb(jacobsthal_nb);
		jacobsthal_nb++;
	}
}

void Pmergeme::sort(){
	std::cout << "Start for Ford-Johnson algorithm" << std::endl;
	if (this->_niv == 2)
		__sortPaire();
	while (this->_niv != 0){
		_createPendMain();
		this->_oldmain = this->_main;
		_insertPendMain();
		this->_tab.assign(this->_main.begin(), this->_main.end());
		this->_main.clear();
		this->_pend.clear();
		std::cout << std::endl << std::endl;
		display();
		this->_niv /= 2;
	}

}

void Pmergeme::_display(size_t a, size_t b, size_t c, size_t d){
	for (size_t i = 0; i < this->_tab.size(); i++){
		if (i >= a && i <= b)
			std::cout << "\033[31m" << this->_tab[i] << "\033[0m ";
		else if (i >= c && i <= d)
			std::cout << "\033[36m" << this->_tab[i] << "\033[0m ";
		else
			std::cout << this->_tab[i] << " ";
	}
	std::cout << std::endl;
}

void Pmergeme::display(){
	for (size_t i = 0; i < this->_tab.size(); i++){
		std::cout << this->_tab[i] << " ";
	}
	std::cout << std::endl;
}

void Pmergeme::displayMain(){
	std::cout << "main : ";
	for (size_t i = 0; i < this->_main.size(); i++){
		std::cout << this->_main[i] << " ";
	}
	std::cout << std::endl;
}

void Pmergeme::displayPend(){
	std::cout << "pend : ";
	for (size_t i = 0; i < this->_pend.size(); i++){
		std::cout << this->_pend[i] << " ";
	}
	std::cout << std::endl;
}