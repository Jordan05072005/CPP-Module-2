#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(){};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name){
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

const std::string Bureaucrat::getName() const{
	return (this->_name);
}

void	Bureaucrat::up(){
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::down(){
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &f){
	try{
		f.beSigned(*this);
		std::cout << this->getName() <<  " signed " << f.getname() << std::endl;
	}
	catch(std::exception &e){
		std::cout << this->getName() <<  " couldn’t sign " << f.getname() << " because " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() <<", bureaucrat grade "<< b.getGrade() << ".";
	return (os);
}