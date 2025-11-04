#ifndef SHRUBBERYCREATIONFORM_H
#	define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm{
	private:
		const	std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &o);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &o);
		~ShrubberyCreationForm();
		const std::string& getTarget() const;
		void execute(Bureaucrat const &b) const ;
};

#endif