#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		size_t _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		class GradeTooHighException : public std::exception{
			public : 
				const char* what() const throw(){
					return "Grade is to high";
				}
		};
		class GradeTooLowException : public std::exception{
			public : 
				const char* what() const throw(){
					return "Grade is to low";
				}
		}; 
		const std::string getName() const;
		int getGrade() const;
		void up();
		void down();
		void signForm(AForm &f);
		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif