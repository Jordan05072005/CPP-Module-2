#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#	include <stdexcept>
# include <algorithm>
# include <array>
# include <string>
# include <iostream>

template <typename T>
typename T::iterator easyfind(T &p1, int p2);

class OccurenceNotFind : public std::exception{
	public:
		const char *what() const throw(){
			return ("Occurence not find");
		}
};

# endif