# include "Form.hpp"
# include "Bureaucrat.hpp"

# define GRADE_HIGH 1
# define GRADE_LOW 150

Form::Form(): name("Form"), grade_signe(50), grade_execute(50), is_signed(false) {}

Form::Form(const std::string &_name, const  int &_grade_signe, const int &_grade_execute): name(_name), grade_signe(_grade_signe), grade_execute(_grade_execute), is_signed(false)
{
	if (grade_signe < GRADE_HIGH || grade_execute < GRADE_HIGH)
		throw (GradeTooHighException());
	else if (grade_signe > GRADE_LOW || grade_execute > GRADE_LOW)
		throw (GradeTooLowException());
}

Form::Form(const Form &copy): name(copy.name), grade_signe(copy.grade_signe), grade_execute(copy.grade_execute), is_signed(copy.is_signed) {}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->is_signed = copy.is_signed;
	}
	return (*this);
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return (name);
}

const int &Form::getGradeSigne() const
{
	return (grade_signe);
}

const int &Form::getGradeExecute() const
{
	return (grade_execute);
}

bool Form::getIsSigned() const
{
	return (is_signed);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade Too Low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade Too High");
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= grade_signe)
		this->is_signed = true;
	else
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << f.getName()
		<< ", Form grade signe " << f.getGradeSigne()
		<< ", Form grade execute " << f.getGradeExecute();
	return out;
}

