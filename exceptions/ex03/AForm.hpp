# ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <ostream>

# include "Bureaucrat.hpp"

class AForm
{
	protected:
		const std::string name;
		const int gradeSign;
		const int gradeExec;
		bool isSigned;
	public:
		AForm();
		AForm(const AForm &copy);
		AForm(std::string const &_name, int _gradeSign, int _gradeExec);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();


		const std::string &getName() const;
		const int &getGradeSigne() const;
		const int &getGradeExecute() const;
		bool getIsSigned() const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
    
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		void beSigned(const Bureaucrat &B);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

# endif
