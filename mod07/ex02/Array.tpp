#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0){
	this->_array = new T[this->_n]();
}

template <typename T>
Array<T>::Array(int n) : _n(n){
	if (n >= 0)
		this->_array = new T[n]();
	else
		this->_array = NULL;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _n(other._n){
	this->_array = NULL;
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other){
	if (this->_array != NULL)
		delete [] this->_array;
	if (this != &other){
		_n = other._n;
		this->_array = new T[this->_n]();
		for (unsigned i = 0; i < this->_n; i++){
			this->_array[i] = other._array[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(){
	delete [] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int nb){
	if (nb < this->_n)
		return (this->_array[nb]);
	else
		throw BadIndexException();
}

template <typename T>
int	Array<T>::size() const {
	int	i = 0;
	for (unsigned int j = 0; j < this->_n; j++){
		if (this->_array[j] != 0)
			i++;
	}
	return (i);
	// return (this->_n);
}