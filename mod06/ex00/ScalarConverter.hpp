#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void convert(std::string const &s);
};

#endif