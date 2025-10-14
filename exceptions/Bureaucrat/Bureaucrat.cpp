# include "Bureaucrat.hpp"
# include <iostream>

# define LOW_GRADE 150
# define HIGH_GRADE 1

Bureaucrat::Bureaucrat(): name("Bureaucrat"), grade(1)
{
	if (grade > LOW_GRADE)
		throw (GradeTooLowException());
	else if (grade < HIGH_GRADE)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const std::string &_name, const int &_grade): name(_name), grade(_grade)
{
	if (grade > LOW_GRADE)
		throw (GradeTooLowException());
	else if (grade < HIGH_GRADE)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name), grade(copy.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		this->grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {} // why the des vir too???

const std::string &Bureaucrat::getName() const
{
	return (name);
}

const int &Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incr_Bureaucrat()
{
	this->grade--;
	if (this->grade > LOW_GRADE)
		throw (GradeTooLowException());
	else if (this->grade < HIGH_GRADE)
		throw (GradeTooHighException());
}

void Bureaucrat::decr_Bureaucrat()
{
	this->grade++;
	if (this->grade > LOW_GRADE)
		throw (GradeTooLowException());
	else if (this->grade < HIGH_GRADE)
		throw (GradeTooHighException());
}

std::ostream &operator<< (std::ostream &out,const Bureaucrat &B)
{
	out << B.getName()
      << ", bureaucrat grade "
      << B.getGrade();
  return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade Too Low");
}
