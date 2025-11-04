#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form f = Form("recrutement", 50, 2);
	Bureaucrat b = Bureaucrat("Christophe", 51);
	try{
		std::cout << b.getGrade() << std::endl;
		std::cout << f.getgrades() << std::endl;
		b.signForm(f);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		f.beSigned(b);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		b.up();
		b.up();
		b.signForm(f);
		f.beSigned(b);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Form f1 = Form("test", 500, -1);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}