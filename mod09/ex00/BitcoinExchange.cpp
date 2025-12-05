#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() : _data(""){}


BitcoinExchange::BitcoinExchange(const std::string &data, const std::string &input) : _data(data), _input(input){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other){
		this->_data = other._data;
		this->_input = other._input;
		this->_bufData = other._bufData;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::setInput(std::string &input){
	this->_input = input;
}

void BitcoinExchange::setData(std::string &data){
	this->_data = data;
}

std::string& BitcoinExchange::getInput(){
	return(this->_input);
}

std::string& BitcoinExchange::getData(){
	return(this->_data);
}

// static std::string trim(const std::string &s, const std::string& sep) {
//     size_t start = s.find_first_not_of(sep);
//     size_t end   = s.find_last_not_of(sep);
//     if (start == std::string::npos) return "";
//     return s.substr(start, end - start + 1);
// }

static float conv(std::string s1){
	std::stringstream t(s1);
	float nb;

	t >> nb;
	return (nb);
}


void	fill(std::map<std::string, float> &s, std::ifstream &fd, std::string sep){
	std::string temp;
	std::string temp2;
	size_t size;
	while (std::getline(fd, temp)){
		size = temp.find(sep);
		if (temp.find("date") != std::string::npos)
			continue;
		else if (size == std::string::npos){
			continue;
		}
		else{
			temp2 = temp.substr(0, size);
			temp = temp.substr(size + 1);
			s[temp2] = conv(temp);
		}
	}
}

int isint(int *tab, float m){
	int i = -1;

	while (tab[++i] != -1){
		if (tab[i] == m)
			return 1;
	}
	return 0;
}

static int checkDay(int a, float m, float j){
	bool bisextile;
	int t[8]= {1, 3, 5, 7, 8, 10, 12, -1};

	bisextile = ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
	if (j <= 0)
		return (0);
	if (m <= 0 || m > 12)
		return (0);
	if (m == 2 && ((bisextile && j > 29) || (!bisextile && j > 28)))
		return (0);
	if (isint(t, m)){
		if (j > 31)
			return (0);
	}
	else{
		if (j > 30)
			return (0);
	}
	return (1);
}

static int	checkerror(std::string l1, std::string l2){
	float	nb;
	int pos;
	int arr[4];
	int i;
	std::string temp;

	pos = 0;
	temp = l1;
	i = 0;
	while ((nb = temp.find('-', pos)) != std::string::npos) {
		arr[i++] = conv(temp.substr(pos, nb - pos));
		pos = nb + 1;
	}
	arr[i++] = conv(temp.substr(pos));
	// for (size_t i = 0; i < v1.size(); i++){
	// 	std::cout << v1[i] << std::endl;
	// }
	nb = conv(l2);

	if (i != 3 || !checkDay(arr[0], arr[1], arr[2]))
		std::cout << "Error: bad input => " << l1 << std::endl;
	else if (l2.size() == 0)
		std::cout << "Error: Syntaxe is bad."<< std::endl;
	else if (nb < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (nb > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
		return (0);
	return (1);
}

void BitcoinExchange::BitcoinExchangeRate(){
	std::ifstream fdD(this->_data.c_str());
	std::ifstream fdI(this->_input.c_str());
	size_t size;
	std::string str;
	std::string line1;
	std::string line2;
	std::map<std::string, float>::iterator tmp;
	std::map<std::string, float>::iterator tmp2;
	int	i = 0;

	if (!fdD.is_open() || !fdI.is_open())
		throw FileNotFound();
	fill(this->_bufData, fdD, ",");
	// fill(this->_bufInput, fdI, " | ");

	tmp2 = this->_bufData.end()--;
	while (std::getline(fdI, str)){
		i++;
		if (i == 1)
			continue;
		size = str.find(" | ");
		if (size == std::string::npos){
			std::cout << "Error: Bad syntaxe" << std::endl;
			continue;
		}
		line1 = str.substr(0, size);
		line2 = str.substr(size + 3);
		if (!checkerror(line1, line2)){
			for (std::map<std::string, float>::iterator it = this->_bufData.begin(); it != this->_bufData.end(); it++){
				tmp2 = it;
				if (it->first >= line1 || ++tmp2 == this->_bufData.end()){
					tmp = it;
					if (it->first > line1){
						if (it == this->_bufData.begin()){
							std::cout << "Error: Date is too old " << std::endl; 
							break;
						}
						tmp--;
					}
					// std::cout << conv(line2) << std::endl;
					// std::cout << tmp->second << std::endl;
					std::cout << line1 << " => " << conv(line2) << " = " << (conv(line2) * tmp->second) << std::endl;
					break;
				}
			}
		}
	}
}

