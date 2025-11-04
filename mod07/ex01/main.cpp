#include "iter.hpp"

template <typename T>
void	addten(T &nbr)
{
	nbr += 1;
}

int main(){
	int arr[5] = {1, 5 ,6 ,7, 5};
	::iter(arr, 5, static_cast<void(*)(int&)>(addten));
	std::cout << arr[0] << " et " << arr[4] << std::endl;

	char tab[5] = {'a', 'b' , 'c' , '7', 'r'};
	iter(tab, 5, static_cast<void(*)(char&)>(addten));
	std::cout << tab[0] << " et " << tab[4] << std::endl;

	double dbl[5] = {1.5, 5.5 ,6.5 ,7.5, 5.5};
	iter(dbl, 5, static_cast<void(*)(double&)>(addten));
	std::cout << dbl[0] << " et " << dbl[4] << std::endl;
}
