#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <iostream>
# include <fstream>
# include <algorithm>
#	include <stdexcept>
# include <sstream>


class BitcoinExchange{
	private:
		std::string _data;
		std::string _input;
		std::map<std::string, float> _bufData;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &data, const std::string &input);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		std::string&	getInput();
		std::string&	getData();
		void	setInput(std::string &input);
		void	setData(std::string &input);
		void BitcoinExchangeRate();

		class FileNotFound : std::exception{
			public:
				const char*what() const throw(){
					return "File not found ! ";
				}
		};
};

#endif