# ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		class FormNotFoundException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		AForm *makeForm(const std::string &form_name, const std::string &target_form);
};

# endif