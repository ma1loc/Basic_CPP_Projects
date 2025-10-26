# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): name("Form"), gradeSign(50), gradeExec(50), isSigned(false) {}

AForm::AForm(std::string const &_name, int _gradeSign, int _gradeExec)
	:	name(_name),
	gradeSign(_gradeSign), 
	gradeExec(_gradeExec),
	isSigned(false)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw (GradeTooLowException());
	else if (gradeSign < 1 || gradeExec < 1)
		throw (GradeTooHighException());
}

AForm::AForm(const AForm &copy)
	: name(copy.name),
	gradeSign(copy.gradeSign),
	gradeExec(copy.gradeExec),
	isSigned(copy.isSigned) {}

AForm &AForm::operator=(const AForm &copy)
{
  if (this != &copy)
  {
    this->isSigned = copy.isSigned;
  }
  return (*this);
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
  return (name);
}

const int &AForm::getGradeSigne() const
{
  return (gradeSign);
}

const int &AForm::getGradeExecute() const
{
  return (gradeExec);
}

bool AForm::getIsSigned() const
{
  return (isSigned);
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return ("Exception: Grade Too Low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return ("Exception: Grade Too High");
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeSign)
		throw (GradeTooLowException());
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << f.getName()
        << ", AForm grade signe " << f.getGradeSigne()
        << ", AForm grade execute " << f.getGradeExecute();
    return out;
}

