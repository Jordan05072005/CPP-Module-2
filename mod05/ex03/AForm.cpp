#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"

AForm::AForm() : _name(""), _grade_s(0), _grade_e(0), _b(false){
}

AForm::AForm(const std::string &name, const int &grade_s, const int &grade_e) : _name(name), _grade_s(grade_s), _grade_e(grade_e) {
	if (grade_e > 150 || grade_s > 150)
		throw GradeTooLowException();
	if (grade_e < 1 || grade_s < 1)
		throw GradeTooHighException();
	_b = false;
}

AForm::AForm(const AForm &other) : _name(other._name), _grade_s(other._grade_s), _grade_e(other._grade_e){
	*this = other;
}

AForm &AForm::operator=(const AForm &other){
	if (&other != this){
		this->_b = other._b;
	}
	return (*this);
}

AForm::~AForm(){};

const std::string AForm::getname() const{
	return (this->_name);
}

bool AForm::getb() const{
	return (this->_b);
}

int AForm::getgradee() const{
	return (this->_grade_e);
}

int AForm::getgrades() const{
	return (this->_grade_s);
}

void	AForm::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= this->getgrades())
		this->_b = true;
	else
		throw GradeTooLowException();

}


std::ostream& operator<<(std::ostream &os, const AForm &f){
	os << f.getname() << ", this grade for sign it is " << f.getgrades() << ", grade for sing exit is " << f.getgradee() << ".";
	return (os);
}
