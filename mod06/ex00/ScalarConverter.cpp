#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

static void	convChar(float i){
	if (i >= 0 && i <= 127){
		if (i >= 0 && i <= 31)
			std::cout <<"char : Caractère no displayable" << std::endl;
		else
			std::cout << "char : " << static_cast<char>(i)  << std::endl;
	}
	else
		std::cout << "Convert in char is impossible" << std::endl;
}

static void	convInt(float i){
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "Convert in int is impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(i)  << std::endl;
}

static void	convFloat(float i, size_t size){
	if (size == 6)
		std::cout << std::scientific << std::setprecision(size);
	else
		std::cout << std::fixed << std::setprecision(size);
	if (i != i)
    std::cout << "float : nanf" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(i) << "f" << std::endl;
}


static void	convDouble(float i, size_t size){
	if (size == 6)
		std::cout << std::scientific << std::setprecision(size);
	else
		std::cout << std::fixed << std::setprecision(size);
	std::cout << "double : " << static_cast<double>(i) << std::endl;
}

static int	isNum(std::string const &s){
	if (s[0] >= 48 && s[0] <= 57)
		return (1);
	return (0);
}

static int	pseudoLitt(std::string const &s){
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return (1);
	if (s == "-inf" || s == "+inf" || s == "nan")
		return (2);
	return (0);
}

static size_t	lenght(std::string const &str){
	size_t	size;
	size_t	size2;
	int	point;

	point = 0;
	size = 0;
	size2 = 0;
	for (size_t i = 0; i < str.length(); i++){
		if (point && isNum(&str[i]))
			size++;
		else if (point == 0 && str[i] != '.')
			size2++;
		if (str[i] == '.')
			point = 1;
	}
	if (size2 > 6)
		size = size2;
	if (size == 0)
		size++;
	if (size > 6)
		size = 6;
	return (size);
}

void ScalarConverter::convert(std::string const &s){
	float	i;
	int	err;

	if (s.empty()){
		std::cout << "Convert all is impossible" << std::endl;
		return;
	}
	err = pseudoLitt(s);
	if (err != 0){
		std::cout << "Convert in int is impossible" << std::endl;
		std::cout << "Convert in char is impossible" << std::endl;
		if (err == 1){
			std::cout << "float : " << s << std::endl;
			std::cout << "double : " << s.substr(0, s.size() - 1) << std::endl;
		}
		else{
			std::cout << "float : " << s  << "f" << std::endl;
			std::cout << "double : " << s << std::endl;
		}
		return;
	}
	if (s[0] && (isNum(s) || s[0] == '-' || s[0] == '+')){
		std::stringstream ss(s);
		ss >> i;
		if (ss.fail()){
			std::cout << "Convert all is impossible" << std::endl;
			return;
		}
	}
	else
		i = s[0];
	convChar(i);
	convInt(i);
	// i = 0.0f / 0.0f;
	convFloat(i, lenght(s));
	convDouble(i, lenght(s));
}