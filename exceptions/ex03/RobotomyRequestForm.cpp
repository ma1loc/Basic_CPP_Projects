# include "RobotomyRequestForm.hpp"
# include <iostream>
# include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Robotomy") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target)
	: AForm("RobotomyRequestForm", 72, 45), target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), target(copy.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char *RobotomyRequestForm::GradeSignException::what() const throw()
{
	return ("RobotomyRequestForm Exception: this 'form' isn’t signed yet, you can’t execute it");
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw (GradeSignException());
	if (executor.getGrade() > getGradeExecute())
		throw (AForm::GradeTooLowException());
	std::cout << "DRRR DBRR DBRRRRRRRRRRRRRRR..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "The robotomy failed." << std::endl;
	else
		std::cout << target << " has been robotomized successfully." << std::endl;
}
