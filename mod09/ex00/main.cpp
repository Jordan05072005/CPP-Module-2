#include "BitcoinExchange.hpp"



int main(int argc, char **argv){
	std::string rep;
	std::string file1;
	std::string file2;

	if (argc == 2){
		file1 = "data.csv";
		file2 = argv[1];
		rep = "1";
		while (rep == "1" || rep == "2"){
			try{
				BitcoinExchange b(file1, file2);
				b.BitcoinExchangeRate();
			}
			catch(std::exception &e){
				std::cerr << e.what() << std::endl;
			}
			std::cout << "\nDo you wont change file ? (0 -> no, 1 -> fileData, 2 -> fileInput)" <<std::endl;
			std::getline(std::cin, rep);
			if (rep == "1"){
				std::cout << "Write path of file1" <<std::endl;
				std::getline(std::cin, file1);
			}
			else if (rep == "2"){
				std::cout << "Write path of file2" <<std::endl;
				std::getline(std::cin, file2);
			}
		}
	}
	else
		std::cout << "Error: could not open file." << std::endl;
}