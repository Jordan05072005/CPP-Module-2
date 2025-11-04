#ifndef AForm_HPP
# define AForm_HPP

# include <string>
#	include <stdexcept>
# include <iostream>

class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		const int _grade_s;
		const int _grade_e;
		bool _b;
	public :
		AForm();
		AForm(const std::string &name,  const int &grade_s, const int &grade_e);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
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
		virtual	void execute(Bureaucrat const &b) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &AForm);

#endif