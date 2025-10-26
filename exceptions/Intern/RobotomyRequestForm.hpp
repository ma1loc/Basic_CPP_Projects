# ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		const std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &_target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		class GradeSignException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		void execute(Bureaucrat const & executor) const;
};

# endif


