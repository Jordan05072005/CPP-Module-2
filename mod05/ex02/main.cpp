#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"


int main(){
	Bureaucrat paul = Bureaucrat("paul", 149);
	Bureaucrat paolo = Bureaucrat("paolo", 1);
	PresidentialPardonForm form1 = PresidentialPardonForm("test");
	RobotomyRequestForm form2 = RobotomyRequestForm("test");
	ShrubberyCreationForm form3 = ShrubberyCreationForm("test");
	try{
		form1.beSigned(paul);
		form1.execute(paul);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
		try{
		// form1.beSigned(paolo);
		form1.execute(paolo);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
		try{
		form1.beSigned(paolo);
		form1.execute(paolo);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		form2.beSigned(paul);
		form2.execute(paul);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		form2.beSigned(paolo);
		form2.execute(paolo);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		form3.beSigned(paul);
		form3.execute(paul);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		form3.beSigned(paolo);
		form3.execute(paolo);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

		try{
		paolo.executeForm(form1);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

		try{
		paul.executeForm(form1);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	

}