#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _grade_s(0), _grade_e(0), _b(false){
}

Form::Form(const std::string &name, const int &grade_s, const int &grade_e) : _name(name), _grade_s(grade_s), _grade_e(grade_e) {
	if (grade_e > 150 || grade_s > 150)
		throw GradeTooLowException();
	if (grade_e < 1 || grade_s < 1)
		throw GradeTooHighException();
	_b = false;
}

Form::Form(const Form &other) : _name(other._name), _grade_s(other._grade_s), _grade_e(other._grade_e){
	*this = other;
}

Form &Form::operator=(const Form &other){
	if (&other != this){
		this->_b = other._b;
	}
	return (*this);
}

Form::~Form(){};

const std::string Form::getname() const{
	return (this->_name);
}

bool Form::getb() const{
	return (this->_b);
}

int Form::getgradee() const{
	return (this->_grade_e);
}

int Form::getgrades() const{
	return (this->_grade_s);
}

void	Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= this->getgrades())
		this->_b = true;
	else
		throw GradeTooLowException();

}


std::ostream& operator<<(std::ostream &os, const Form &f){
	os << f.getname() << ", this grade for sign it is " << f.getgrades() << ", grade for sing exit is " << f.getgradee() << ".";
	return (os);
}
