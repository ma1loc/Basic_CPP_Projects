# include "Intern.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern() {}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Intern Exception: unknown form name");
}

// TODO; why static function???
static AForm *makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makePresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*available_forms[])(const std::string &) = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (available_forms[i](target));
		}
	}
	std::cout << "Intern couldn’t find "
			<< name << " in the list of 'FORMs'"
			<< std::endl;
	throw FormNotFoundException();
}