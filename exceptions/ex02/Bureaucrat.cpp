# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>

# define LOW_GRADE 150
# define HIGH_GRADE 1

Bureaucrat::Bureaucrat(): name("Bureaucrat"), grade(1)
{
	if (grade < HIGH_GRADE)
		throw (GradeTooHighException());
	else if (grade > LOW_GRADE)
		throw (GradeTooLowException());
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

Bureaucrat::~Bureaucrat() {}

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
	if (this->grade - 1 < HIGH_GRADE)
		throw (GradeTooHighException());
	this->grade--;
}

void Bureaucrat::decr_Bureaucrat()
{
	if (this->grade + 1 > LOW_GRADE)
		throw (GradeTooLowException());
	this->grade++;
}

std::ostream &operator<< (std::ostream &out,const Bureaucrat &b)
{
	out << b.getName()
      << ", bureaucrat grade "
      << b.getGrade();
  return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade Too High -> From Bureaucrat");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade Too Low -> From Bureaucrat");
}

void Bureaucrat::signForm(const AForm &f) const
{
  if (f.getIsSigned())
  {
    std::cout << this->getName()
      << " signed "
      << f.getName()
      << std::endl;
  }
  else 
  {
    std::cout << f.getName()
          << " couldn’t sign "
          << this->getName()
          << " because "
          << f.getGradeSigne()
          << " < " << this->getGrade()
          << std::endl;
  }
}

void  Bureaucrat::executeForm(AForm const &f)
{
	try
	{
		f.execute(*this);
		std::cout << this->getName() << " executed " << f.getName()
				<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute " 
				<< f.getName() << " because "
				<< e.what() << std::endl;
	}
}
