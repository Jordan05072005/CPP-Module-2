#ifndef FUNC_HPP
# define FUNC_HPP

#include <iostream>

template <typename T>
void swap(T &val1, T &val2){
	T temp;

	temp = val1;
	val1 = val2;
	val2 = temp;
}

template <typename T>
T min(T &val1, T &val2){
	if (val1 >= val2)
		return (val2);
	else
		return (val1);
}

template <typename T>
T max(T &val1, T &val2){
	if (val1 <= val2)
		return (val2);
	else
		return (val1);
}

#endif