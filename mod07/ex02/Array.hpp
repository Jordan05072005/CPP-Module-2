#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array{
	private:
		T* _array;
		unsigned int	_n;
	public:
		Array();
		Array(int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();
		T& operator[](unsigned int nb);
		class BadIndexException : public std::exception{
			public :
				const char* what() const throw(){
					return ("Index is not in the range of array");
				}
		};
		int size() const;
};

#endif