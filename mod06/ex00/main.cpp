#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	// ScalarConverter t = ScalarConverter();
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Incorrect Argument" << std::endl;
}