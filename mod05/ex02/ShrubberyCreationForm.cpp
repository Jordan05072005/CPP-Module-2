#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default"){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target){

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o) : AForm("ShrubberyCreationForm", o.getgrades(), o.getgradee()), target(o.getTarget()){
	*this = o;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o){
	if (&o !=this)
			return (*this);
	return (*this);
}

const std::string& ShrubberyCreationForm::getTarget() const{
	return (this->target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const {
	if (!this->getb() || b.getGrade() > this->getgradee())
		throw GradeTooLowException();
	std::string filename = this->target + "_shrubbery";
	std::ofstream ofs(filename.c_str());

	ofs <<"           0            "<< std::endl;
	ofs <<"          000           "<< std::endl;
	ofs <<"         00000          "<< std::endl;
	ofs <<"        0000000         "<< std::endl;
	ofs <<"       000000000        "<< std::endl;
	ofs <<"         00000          "<< std::endl;
	ofs <<"        0000000         "<< std::endl;
	ofs <<"       000000000        "<< std::endl;
	ofs <<"      00000000000       "<< std::endl;
	ofs <<"     0000000000000      "<< std::endl;
	ofs <<"       000000000        "<< std::endl;
	ofs <<"      00000000000       "<< std::endl;
	ofs <<"     0000000000000      "<< std::endl;
	ofs <<"    000000000000000     "<< std::endl;
	ofs <<"   00000000000000000    "<< std::endl;
	ofs <<"          000           "<< std::endl;
	ofs <<"          000           "<< std::endl;
	ofs <<"          000           "<< std::endl;
	ofs.close();
}
