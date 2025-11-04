#ifndef RPN_HPP
# define RPN_HPP

# include <string>
#	include <stdexcept>
#	include <stack>
#	include <cctype>
#	include <iostream>


class RPN{
	private:
		std::string _rpn;
		std::stack<int> _pile;
	public:
		RPN();
		RPN(std::string &rpn);
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();
		void rpn();
		// class RpnError : public std::exception{
		// 	public :
		// 		const char*what() const throw(){
		// 			return "Arg rpn is bad";
		// 		}
		// };

};

#endif