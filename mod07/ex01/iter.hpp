#ifndef ITER_HPP
# define ITER_HPP


#include <iostream>

template <typename T, typename F>
void	iter(T* lst, const int length, F func){
	if (lst == NULL || func == NULL)
		return ;
	for (int i = 0; i < length; i++){
		func(lst[i]);
	}
}

#endif