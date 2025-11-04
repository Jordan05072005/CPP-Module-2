#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
#	include <stdexcept>
#	include <iostream>
#	include <algorithm>


class Span{
	private:
		std::vector<int> _v;
		unsigned int _N;
	public :
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		class VectorFull : public std::exception{
			public:
				const char*what() const throw(){
					return "Vector is Full !";
				}
		};
		class VectorTooSmall : public std::exception{
			public:
				const char*what() const throw(){
					return "Vector is too small !";
				}
		};
		void addNumber(int n);
		void addNumber(std::vector<int> v2);
		int shortestSpan();
		int longestSpan();
};

#endif