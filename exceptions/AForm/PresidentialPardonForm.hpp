# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &_target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm & copy);
		~PresidentialPardonForm();

		class GradeSignException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		void execute(Bureaucrat const & executor) const;

};

# endif