#include "includes/PresidentialPardonForm.hpp"
#include "includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o) : AForm("PresidentialPardonForm", o.getgrades(), o.getgradee()), target(o.getTarget()){
	*this = o;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &o){
	if (&o !=this)
			return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

const std::string& PresidentialPardonForm::getTarget() const{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const {
	if (b.getGrade() > this->getgrades() || b.getGrade() > this->getgradee())
		throw GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
