#ifndef FORM_HPP
# define FORM_HPP

# include <string>
#	include <stdexcept>
# include <iostream>

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		const int _grade_s;
		const int _grade_e;
		bool _b;
	public :
		Form();
		Form(const std::string &name,  const int &grade_s, const int &grade_e);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		class GradeTooHighException : public std::exception{
			public : 
				const char* what() const throw(){
					return "Grade is to high";
				};
		};
		class GradeTooLowException : public std::exception{
			public : 
				const char* what() const throw(){
					return "Grade is to low";
				};
		};
		const std::string getname() const;
		bool 							getb() const;
		int				getgrades() const;
		int				getgradee() const;
		void	beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif