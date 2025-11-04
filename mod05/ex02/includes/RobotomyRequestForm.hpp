#ifndef ROBOTOMYREQUESTFORM_H
#	define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>
#include <ctime> 

class RobotomyRequestForm : public AForm{
	private:
		const	std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &o);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &o);
		~RobotomyRequestForm();
		const std::string& getTarget() const;
		void execute(Bureaucrat const &b) const ;
};

#endif