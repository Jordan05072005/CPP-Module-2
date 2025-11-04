#include "includes/RobotomyRequestForm.hpp"
#include "includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default"){};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target){

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o) : AForm("RobotomyRequestForm", o.getgrades(), o.getgradee()), target(o.getTarget()){
	*this = o;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &o){
	if (&o !=this)
			return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

const std::string& RobotomyRequestForm::getTarget() const{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const {
	if (b.getGrade() > this->getgrades() || b.getGrade() > this->getgradee())
		throw GradeTooLowException();
	srand(time(NULL));
	std::cout << "Brr...Vrr....Brouuuuuuuuuum" << std::endl;
	if (rand() % 2 == true)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed." << std::endl;
}
