#ifndef PRESIDENTIALPARDONFFORM_H
#	define PRESIDENTIALPARDONFFORM_H

#include "AForm.hpp"


class PresidentialPardonForm : public AForm{
	private:
		const	std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &o);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &o);
		~PresidentialPardonForm();
		const std::string& getTarget() const;
		void execute(Bureaucrat const &b) const ;
};

#endif