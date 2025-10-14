# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    Bureaucrat(const std::string &_name, const int &_grade); // TODO;

		const std::string &getName() const; 
		const int &getGrade() const;

		void incr_Bureaucrat();
		void decr_Bureaucrat();

    class GradeTooHighException: public std::exception
    {
      public:
        const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
      public:
        const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);

# endif
