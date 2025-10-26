# include "PresidentialPardonForm.hpp"
# include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("Presidential") {};

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target)
	:AForm("PresidentialPardonForm", 25, 5), target(_target) {}

PresidentialPardonForm::PresidentialPardonForm(const  PresidentialPardonForm &copy)
	: AForm(copy), target(copy.target) {};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {};

const char *PresidentialPardonForm::GradeSignException::what() const throw()
{
	return ("PresidentialPardonForm Exception: this 'form' isn’t signed yet, you can’t execute it");
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw (GradeSignException());
	else if (executor.getGrade() > getGradeExecute())
		throw (AForm::GradeTooLowException());
	std::cout << target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
