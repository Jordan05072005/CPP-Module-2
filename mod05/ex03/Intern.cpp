#include "includes/Intern.hpp"

Intern::Intern(){

}
Intern::Intern(const Intern &other){
	*this = other;
}
Intern& Intern::operator=(const Intern &other){
	if (this != &other)
		return (*this);
	return (*this);
}

Intern::~Intern(){}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static int comp(std::string& s1, std::string &s2){
	for (size_t i = 0; i < std::min(s1.length(), s2.length()); i++){
		if (std::tolower(s1[i]) != std::tolower(s2[i]))
			return (0);
	}
	return (1);
}

AForm* Intern::makeForm(std::string form, std::string target){
	AForm *(*all_Forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string Forms[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	for (int i = 0; i < 3; i++)
	{
		if (comp(form, Forms[i]))
		{
			std::cout << "Intern creates " << form << " now" << std::endl;
			return (all_Forms[i](target));
		}
	}
	std::cout << "\033[33mIntern can not create a AForm called " << form << "\033[0m" << std::endl;
	return (NULL);
}