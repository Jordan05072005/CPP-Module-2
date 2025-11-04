#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"

int main(){
	Intern i = Intern();

	AForm *t = i.makeForm("robotomy requEst", "Tom");
	delete t;
	// i.makeForm("presidential pardon", "Touf");
	// i.makeForm("shrubbery creation", "Tif");
	// i.makeForm("rootomy requete", "Tom");
	// i.makeForm("presidential padon", "Touf");
	// i.makeForm("shruberr creation", "Tif");
}