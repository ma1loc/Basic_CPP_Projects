# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>

class ShrubberyCreationForm: public AForm	
{
	private:
		const std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &_target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		class GradeSignException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FileCreationException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		void execute(Bureaucrat const & executor) const;
};

#endif
