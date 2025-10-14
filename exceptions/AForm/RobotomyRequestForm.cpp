# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Robotomy") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target)
	: AForm("RobotomyRequestForm", 72, 45), target(_target) {}

// TODO; what we will call in the init list (AForm(copy)) assinment operator or copy constractor and why?
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), target(copy.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		this->isSigned = copy.isSigned;
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
	// what will done here ????
}